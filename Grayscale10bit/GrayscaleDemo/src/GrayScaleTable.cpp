//
// GrayScaleTable.h
//
// Functions to create the lookup table for 8/10/12 bit display cases
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "GrayScaleTable.h"

// could be used starting from entry 32
int fastTable12bit[16][3] = {   { 0,  0,  0},
                                {-1,  1, -2},
                                { 0,  0,  1},
                                { 1,  1, -1},
                                { 0,  0,  2},
                                { 1,  0,  0},
                                { 0,  0,  3},
                                { 1,  0,  1},
                                { 0,  1, -1},
                                { 1,  0,  2},
                                { 0,  1,  0},
                                { 0,  1,  1},
                                { 2,  0,  1},
                                { 2,  1,  2},
                                { 1,  1,  0},
                                { 0,  1,  3} };

// This is a precalculated table for the 1st 32 entries in RGB notation.
int fastTable12bit1st32[32][3] = { 
        {0, 0, 0}, {0, 0, 1}, {0, 0, 1}, {0, 0, 2}, 
        {0, 0, 2}, {1, 0, 0}, {0, 0, 3}, {1, 0, 1}, 
        {1, 0, 2}, {0, 1, 0}, {2, 0, 0}, {0, 1, 1}, 
        {1, 0, 4}, {0, 1, 2}, {1, 1, 0}, {0, 1, 3}, 
        {1, 1, 1}, {0, 1, 4}, {1, 1, 2}, {0, 2, 0}, 
        {1, 1, 3}, {2, 1, 1}, {1, 1, 4}, {2, 1, 2}, 
        {1, 2, 0}, {1, 2, 1}, {3, 1, 1}, {1, 2, 2}, 
        {2, 2, 0}, {1, 2, 3}, {2, 2, 1}, {1, 2, 4} };

// This is a precalculated table for the last 32 entries in RGB notation.
int fastTable12bitLast48[48][3] = { 
        {250, 253, 253}, {252, 252, 253}, {251, 253, 251}, {251, 253, 252}, 
        {253, 252, 252}, {253, 252, 253}, {252, 253, 251}, {253, 252, 254}, 
        {252, 253, 252}, {253, 252, 255}, {252, 253, 253}, {253, 253, 251}, 
        {252, 253, 254}, {253, 253, 252}, {252, 253, 255}, {253, 253, 253}, 
        {252, 254, 251}, {253, 253, 254}, {252, 254, 252}, {253, 253, 255}, 
        {254, 253, 253}, {252, 254, 254}, {254, 253, 254}, {254, 253, 255}, 
        {253, 254, 253}, {254, 254, 251}, {253, 254, 254}, {254, 254, 252}, 
        {253, 254, 255}, {254, 254, 253}, {253, 255, 251}, {254, 254, 254}, 
        {253, 255, 252}, {254, 254, 255}, {253, 255, 253}, {254, 255, 251}, 
        {255, 254, 254}, {253, 255, 255}, {255, 254, 255}, {254, 255, 253}, 
        {254, 255, 254}, {255, 255, 252}, {254, 255, 255}, {255, 255, 253}, 
        {255, 255, 253}, {255, 255, 254}, {255, 255, 254}, {255, 255, 255} };


//
// cReateYasRGBTable12BitFast
//
// Creates a 12 bit RGT to Y lookup Table by using precalculated values.
// The 1st 32 and last 32 entries needs to be taken from a precalculated
// table, while the other values could be computed using a precalculated
// matrix repeated each 16th value.
//
// 
COLORREF *cReateYasRGBTable12BitFast(int numEntries)
{
    COLORREF *table = NULL;

    if (4096 == numEntries) {
    
        table = (COLORREF *)calloc(4096 * sizeof(COLORREF),1);
        
        if (table) {
            int i;
            // 1st 32 entries are precalculated as the do not match in the 
            // calculation scheme which could be used laster on.
            for (i=0; i < 32; i++) {
                table[i] = RGB(fastTable12bit1st32[i][0],
                               fastTable12bit1st32[i][1],
                               fastTable12bit1st32[i][2]);
            }
            // The fastTable12bit entries need to be added to the counter rounded to 8 bit.
            for (; i < 4096 - 48; i++) {
                table[i] =  RGB((i/16) + fastTable12bit[i%16][0],
                                (i/16) + fastTable12bit[i%16][1],
                                (i/16) + fastTable12bit[i%16][2]);
            }
            // last numbers will reach out of it, calculate own table
            for (; i < 4096; i++) {
                table[i] = RGB(fastTable12bitLast48[i-(4096-48)][0],
                            fastTable12bitLast48[i-(4096-48)][1],
                            fastTable12bitLast48[i-(4096-48)][2]);
            }
        }
    }
    return table;
}



//
// cReateYasRGBTable8Bit
//
// 8 bit grayscale table means identical values for R G and B.
// In case numEntries is greater than 256, entries are simply
// duplicated.
//
COLORREF *cReateYasRGBTable8Bit(int numEntries)
{
    COLORREF *table = NULL;

    if (4096 == numEntries) {
    
        table = (COLORREF *)calloc(4096 * sizeof(COLORREF),1);
        
        if (table) {
            int i,j;
            COLORREF color;
            for (i=0; i < numEntries; i+=16) {
                color = RGB(i/16, i/16, i/16);
                for (j=0; j < 16; j++) {
                    table[i+j] = color;
                }
            }
        }
    }
    return table;
}



//
// The table is based on a backend shader which translates into 12 bit grayscale.
// It calculates the values based on brute force. It calculates all possible 
// values and checks the error coefficents, one based on the desired grayscale
// values and one based divergion from the ideal RGB values (same value for R,G,B)
// on the RGB value.
// So far this routine is very slow as the loop is done on the whole number
// area.
// This fuinction was used to calculate the 1st 12 bit lookup table which was then
// analyzed and taken as base for the fast 12 bit lookuptable generation function.
// At the end the functions could be avoided by hardcode the 12bit lookuptable.
//
RGBtoY *cReateRGBtoYTable(int tableEntriesLog2, int useDeltaY, int useDeltaGray)
{
    int entries = 1 << tableEntriesLog2;
    RGBtoY *table = NULL;
    int refEntries = 4096; // The backend will always use 12 bit.
    
    table = (RGBtoY *)calloc(entries * sizeof(RGBtoY),1);
    
    if (table) {
        int R,G,B,T,deltaGrayTemp,RGBmin,RGBmax;
        int RGBminLoop, RGBmaxLoop, searchArea;
        float Y,RScaled,GScaled,BScaled,entryScale;
        float RScale, GScale, BScale;
        float deltaYTemp;
        
        // Scale RGB values to 0.0 ... 1.0 range 1st.
        entryScale = (float)entries / 256.0f;

        // Precalculate the scaling factors of the RGB values here.
        RScale = 0.299f * entryScale * (((float)entries -1.0f) / (entryScale * 255.0f));
        GScale = 0.587f * entryScale * (((float)entries -1.0f) / (entryScale * 255.0f));
        BScale = 0.114f * entryScale * (((float)entries -1.0f) / (entryScale * 255.0f));

        //
        // Basic grayscale formular is Y = 0.299 * R + 0.587 * G + 0.114 * B
        //
        // Since the final calculation will work on integer values of 8 / 12 bit, this needs to be taken into account:
        // The RGB components are unsigned 8 bit values, while the grayscale is unsigned 12 bit.
        // So the RGB sum will be 255 max, which needs to be mapped to 4095, which is the maximal grayscale value.
        //
        // To look at the maximal values:  255 * 16 = 4080      4080 * (4095 / 4080) = 4095
        //
        // So e.g. for 12 bit the scling will be:
        //
        // Y = (0.299 * R + 0.587 * G + 0.114 * B) * 16 * (4095 / 4080)
        //
        // The temporary scaling for each component is in this case:
        //
        // RScale = 0.299 * 16 * (4095 / 4080);
        // GScale = 0.587 * 16 * (4095 / 4080);
        // BScale = 0.114 * 16 * (4095 / 4080);
        //


        // Restrict area to look for matching values around an RGB value to speedup caclulation.
        searchArea = 10;

        for (T = 0; T < entries; T++) 
        {
            table[T].deltaY = (float)refEntries;
            table[T].deltaGray = refEntries;
            table[T].R = 0;
            table[T].G = 0;
            table[T].B = 0;

            // Restric loops on the RGB values:
            RGBminLoop = (T / (int)entryScale) - searchArea;
            RGBmaxLoop = (T / (int)entryScale) + searchArea;

            // only searching in a good area around the values
            if ((T / (int)entryScale) < searchArea)
            {
                RGBminLoop = 0;
            }
            else if ((T / (int)entryScale) > (256 - searchArea))
            {
                RGBmaxLoop = 256;
            }

            // Brute force loop over all RGB values to find the
            // best matching grayscale values.
            for (R = RGBminLoop; R < RGBmaxLoop; R++) 
            {
                RScaled = (float)R * RScale;
                for (G = RGBminLoop; G < RGBmaxLoop; G++) 
                {
                    GScaled = (float)G * GScale;
                    for (B = RGBminLoop; B < RGBmaxLoop; B++) 
                    {
                        BScaled = (float)B * BScale;
                        
                        // Result is already scaled to final bitdepth.
                        Y = RScaled + GScaled + BScaled;
                        
                        deltaYTemp = Y - (float)T;
                        if (deltaYTemp < 0.0) {
                            deltaYTemp *= -1.0;
                        }

                        RGBmin = (R<B ? R : B);
                        RGBmin = (RGBmin<G ? RGBmin : G);

                        RGBmax = (R>B ? R : B);
                        RGBmax = (RGBmax>G ? RGBmax : G);
                        
                        deltaGrayTemp = RGBmax - RGBmin;
                        
                        if (useDeltaY && useDeltaGray) {
                            if ((deltaYTemp < 0.49f) && 
                                (deltaGrayTemp < 10)) {
                                if ((deltaGrayTemp < table[T].deltaGray) ||
                                    (table[T].deltaY > 0.49f)) {
                                    table[T].R = R;
                                    table[T].G = G;
                                    table[T].B = B;
                                    table[T].deltaY = deltaYTemp;
                                    table[T].deltaGray = deltaGrayTemp;

                                    if ((0.0f == deltaYTemp) &&
                                        (0 == deltaGrayTemp)){
                                        goto next;
                                    }
                                }
                            }
                            else if (table[T].deltaY > 0.49f) {
                                if (deltaYTemp < table[T].deltaY) {
                                    table[T].R = R;
                                    table[T].G = G;
                                    table[T].B = B;
                                    table[T].deltaY = deltaYTemp;
                                    table[T].deltaGray = deltaGrayTemp;
                                }
                            }
                        } else if(useDeltaY) {
                            if (deltaYTemp < table[T].deltaY) {
                                table[T].R = R;
                                table[T].G = G;
                                table[T].B = B;
                                table[T].deltaY = deltaYTemp;
                                table[T].deltaGray = deltaGrayTemp;
                            }
                        } else if(useDeltaGray) {
                            if (deltaGrayTemp < table[T].deltaGray) {
                                table[T].R = R;
                                table[T].G = G;
                                table[T].B = B;
                                table[T].deltaY = deltaYTemp;
                                table[T].deltaGray = deltaGrayTemp;
                            }
                        }
                        
                    }
                }
            }
next:;
        }

#if 0
        // In case a printout is needed, this could be reenabled.
        for (T=0;T<entries;T++) {
            printf ("{%d, %d, %d}, ",table[T].R,table[T].G,table[T].B);
            if (3==(T%4))
                printf("\n");
        }
#endif
    }
    
    return table;
}
