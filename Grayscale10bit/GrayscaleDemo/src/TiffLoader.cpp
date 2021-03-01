//
// tiffloader.cpp
//
// tiff file read function
//
#include <windows.h>
#include "tiffio.h"
#include <GL/gl.h>

//
// readTiff
// 
// Wrapper function for the tifflib library to read in data of a tiff image
// with the given name. The data is transfered to the given pixel container
// (which is alloced internally and needs to be freed by the user) and all
// handles to the tiff file are closed.
// return 0 in error case, 1 in success;
//
int readTiff(char *imageName, GLuint *pWidth, GLuint *pHeight, GLuint *pBpp, GLuint *pMinValue, GLuint *pMaxValue, GLuint *pNumValues, char** pixels) 
{
    int iRet = 0;
    TIFF *image;
    uint16 bps;
    tsize_t stripSize;
    unsigned long imageOffset, result;
    int stripMax, stripCount;
    char *buffer;
    unsigned long bufferSize;

    // Check input variables.
    if (!imageName || !pHeight || !pHeight || !pBpp || !pixels) {
        fprintf(stderr, "Imput variable pointers are zero\n");
        goto Exit;
    }

    // Open the TIFF image
    if((image = TIFFOpen(imageName, "r")) == NULL){
        fprintf(stderr, "Could not open incoming image\n");
        goto Exit;
    }
    // Check that it is of a type that we support
    if((TIFFGetField(image, TIFFTAG_BITSPERSAMPLE, &bps) == 0) || (bps != 16)){
        fprintf(stderr, "Either undefined or unsupported number of bits per sample\n");
        goto Exit;
    }
    // We only support 1 pixelrow per strip
    stripSize = TIFFStripSize (image);
    stripMax = TIFFNumberOfStrips (image);
    imageOffset = 0;
    bufferSize = TIFFNumberOfStrips (image) * stripSize;
    if((buffer = (char *) malloc(bufferSize)) == NULL) {
        fprintf(stderr, "Could not allocate enough memory for the uncompressed image\n");
        goto Exit;
    }
    for (stripCount = 0; stripCount < stripMax; stripCount++) {
        if((result = TIFFReadEncodedStrip (image, stripCount,
            buffer + imageOffset,
            stripSize)) == -1){
            fprintf(stderr, "Read error on input strip number %d\n", stripCount);
            goto Exit;;
        }
        imageOffset += result;
    }

    // Retrieve needed image parameter
    if(TIFFGetField(image, TIFFTAG_IMAGEWIDTH, pWidth) == 0) {
        fprintf(stderr, "Image does not define its width\n");
        goto Exit;
    }
    // imageheight
    if(TIFFGetField(image, TIFFTAG_IMAGELENGTH, pHeight) == 0) {
        fprintf(stderr, "Image does not define its width\n");
        goto Exit;
    }
    if(TIFFGetField(image, TIFFTAG_BITSPERSAMPLE, pBpp) == 0) {
        fprintf(stderr, "Either undefined or unsupported number of bits per sample\n");
        goto Exit;
    }
    *pixels = buffer;


    // Helper function to find out real image bits range (should be 12 bit 0--4095)
    if (1)
    {
        #define MAX_VALUE 65536

        unsigned int table[MAX_VALUE];
        uint16 minv = MAX_VALUE-1;
        uint16 maxv = 0;
        unsigned int x,y;
        uint16 value;
        int count = 0;

        memset(table, 0, sizeof(table));       // zero out structure

        for (y = 0; y < *pHeight; y++) {
            for (x = 0; x < *pWidth; x++) {

                value = ((uint16*)buffer)[y* (*pWidth) +x];

                table[value]++;

                if (value > maxv) {
                    maxv = value;
                }
                if (value < minv) {
                    minv = value;
                }
            }
        }

        // check for number of values used:
        for (y = 0; y < MAX_VALUE; y++) {
            if (table[y]) {
                count++;
            }
        }

        if (pMinValue)
            *pMinValue = minv;
        if (pMaxValue)
            *pMaxValue = maxv;
        if (pNumValues)
            *pNumValues = count;
    }

    iRet = 1;

Exit:;

    // Close image handle in any case. We've red out all we needed.
    if (image)
        TIFFClose(image);

    if (1 != iRet) {
        if (buffer)
            free(buffer);
        if (pWidth)
            *pWidth = 0;
        if (pHeight)
            *pHeight = 0;
        if (pBpp)
            *pBpp = 0;
        if (pMinValue)
            *pMinValue = 0;
        if (pMaxValue)
            *pMaxValue = 0;
        if (pNumValues)
            *pNumValues = 0;
        if (pixels)
            *pixels = 0;
    }

    return iRet;
}
