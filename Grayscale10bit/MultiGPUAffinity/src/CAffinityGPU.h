//
// CAffinityGPU.h
//
// Class CAffinityGPU - encapsulates all the info specific to a 
// group of GPU driving a display - 
// such as its name, affinity DC, RC etc
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef _CAFFINITYGPU_H_
#define _CAFFINITYGPU_H_
#include <windows.h>
#include "globaldefs.h"

class CAffinityGPU {
private:
    HDC     affinityDC;      // DC of affinity gpu
    HGLRC   affinityGLRC;    // affinity gpu ogl context
	char	gpuNames[MAX_NUM_GPUS][128]; //gpu strings, quadro 4600 etc
	int		numGPUs; //No of GPU's in the affinity group
public:
	///Default constructor 
	CAffinityGPU();
	///input is the GPU list and the GPU DC and RC are created here
	void init(HGPUNV* hgpu, int num =1);
	///print this GPU's information
	void print();
	///Destructor destroys the GPURC/DC/dissasociates them
	~CAffinityGPU();
	
	/// returns the OGL context
	HGLRC	getRC() {
		return affinityGLRC;
	}

	/// set name for the idx'th GPU, default to one GPU
	void setName(char* name, int idx = 0) {
		strcpy(gpuNames[idx], name);
	}

	/// return name of idx'th GPU in the list
	const char* getName(int idx = 0) {
		return gpuNames[idx];
	}
};


#endif