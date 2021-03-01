//
// CAffinityGPU.cpp
//
// Class CAffinityGPU - encapsulates all the info specific to a 
// group of GPU driving a display - 
// such as its name, affinity DC, RC etc
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include "CAffinityGPU.h"
#include "CDisplayWin.h"
#include <stdio.h>

CAffinityGPU::CAffinityGPU() {
	affinityDC = 0;
	affinityGLRC = 0;
	numGPUs = 0;
	for (int i=0; i<MAX_NUM_GPUS;i++)
		strcpy(gpuNames[i],"");

}

//Get affinity DC and RC for this GPU.
//null terminated list of GPU's 
void CAffinityGPU::init(HGPUNV* gpuMask, int num) {
	numGPUs = num;
	//Create affinity-DC
	if (!(affinityDC = wglCreateAffinityDCNV(gpuMask))) {
		ERR_MSG("Unable to create GPU affinity DC");
	}
	//Set the pixel format for the affinity-DC
	CDisplayWin::setPixelFormat(affinityDC);
	//Create affinity GLRC from affinity-DC
	if (!(affinityGLRC = wglCreateContext(affinityDC))) {
		ERR_MSG("Unable to create GPU affinity RC");
	}
}

void CAffinityGPU::print() {
	//Attach Affinity-GLRC to Affinity-DC
	wglMakeCurrent(affinityDC, affinityGLRC);
	printf("\nNo of GPU's in Affinity Mask = %d\n",numGPUs);
	for (int i =0; i < numGPUs; i++)
		printf("\tGPU %d: %s\n",i,gpuNames[i]);
	GLInfo();
	wglMakeCurrent(NULL, NULL);
}

CAffinityGPU::~CAffinityGPU() {
	if (affinityGLRC)
		wglDeleteContext(affinityGLRC);
	affinityGLRC = 0;

	if (affinityDC)
		wglDeleteDCNV(affinityDC);
	affinityDC = 0;
}


