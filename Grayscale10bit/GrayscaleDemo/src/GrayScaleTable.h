//
// GrayScaleTable.h
//
// Functions to create the lookup table for 8/10/12 bit display cases
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
//extern "C"{
#endif 

typedef struct _RGBtoY {
	int R;
	int G;
	int B;
	float deltaY;
	int deltaGray;
}RGBtoY;

extern COLORREF *cReateYasRGBTable12BitFast(int numEntries = 4096);
extern COLORREF *cReateYasRGBTable10Bit(int numEntries = 4096);
extern COLORREF *cReateYasRGBTable8Bit(int numEntries = 4096);
extern RGBtoY *cReateRGBtoYTable(int tableEntriesLog2, int useDeltaY, int useDeltaGray);


#ifdef __cplusplus
//}
#endif