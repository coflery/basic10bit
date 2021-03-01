//
// MultiGPUAffinity.cpp
//
// Main driver program that creates a window per display and attaches it to the 
// display-specific GPU using the WGL affinity extension.
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <stdio.h>
#include "globaldefs.h"
#include "CAffDisplayWin.h"
#include "CAffinityGPU.h"

CDisplayWin dummyWin; 	//Dummy window just to get the affinity extensions

unsigned int gpuCount = 0; //no of gpu's in system
CAffinityGPU affGPUList[MAX_NUM_GPUS]; //list of gpu's

unsigned int displayCount = 0; //no of displays or screens
CAffDisplayWin displayWinList[MAX_NUM_GPUS*2]; //list of displays, each gpu can attah to max 2 displays


// WGL_gpu_affinity
PFNWGLENUMGPUSNVPROC                    wglEnumGpusNV = NULL;
PFNWGLENUMGPUDEVICESNVPROC              wglEnumGpuDevicesNV = NULL;
PFNWGLCREATEAFFINITYDCNVPROC            wglCreateAffinityDCNV = NULL;
PFNWGLDELETEDCNVPROC                    wglDeleteDCNV = NULL;
PFNWGLENUMGPUSFROMAFFINITYDCNVPROC      wglEnumGpusFromAffinityDCNV = NULL;

BOOL loadAffinityExtensionFunctions(void)
{
	BOOL gpuAffinityOK;

	//Create a dummy window just to get the affinity extensions
	if (!dummyWin.createGLWin(100,100,500,500))
		ERR_MSG("Coudn't create Dummy Window to get the AFFINITY extensions");

	// WGL_NV_gpu_affinity
	wglEnumGpusNV = (PFNWGLENUMGPUSNVPROC)
		wglGetProcAddress("wglEnumGpusNV");
	wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNVPROC)
		wglGetProcAddress("wglEnumGpuDevicesNV");
	wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNVPROC)
		wglGetProcAddress("wglCreateAffinityDCNV");
	wglDeleteDCNV = (PFNWGLDELETEDCNVPROC)
		wglGetProcAddress("wglDeleteDCNV");
	wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)
		wglGetProcAddress("wglEnumGpusFromAffinityDCNV");

	gpuAffinityOK =	(wglEnumGpusNV != NULL) &&
		(wglEnumGpuDevicesNV != NULL) &&
		(wglCreateAffinityDCNV != NULL) &&
		(wglDeleteDCNV != NULL) &&
		(wglEnumGpusFromAffinityDCNV != NULL);

	return gpuAffinityOK;
}

//all the common windows related functions like creation, callbacks etc goes here
void GLInfo() {
	printf("\nOpenGL vendor: %s\n", glGetString(GL_VENDOR));
	printf("OpenGL renderer: %s\n", glGetString(GL_RENDERER));
	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
}

int main(int argc, char** argv)
{
	if (!loadAffinityExtensionFunctions()) {
		ERR_MSG("Error getting affinity extensions");
	}
	//Enumerate all GPU's and their attached displays
	printf("\n=== Using WGL_AFFINITY_EXT===\n");
	HGPUNV curNVGPU;
	//Get a list of GPU's and their associated displays devices
	while ((gpuCount < MAX_NUM_GPUS) && wglEnumGpusNV(gpuCount, &curNVGPU)) { 
		unsigned int curDisplay = 0;
		GPU_DEVICE  gpuDevice;
		gpuDevice.cb = sizeof(gpuDevice);
		HGPUNV gpuMask[2];
		gpuMask[0] = curNVGPU;
		gpuMask[1] = NULL;		
		affGPUList[gpuCount].init(gpuMask);
		//loop through displays
		while (wglEnumGpuDevicesNV(curNVGPU, curDisplay, &gpuDevice)) {
			//The name of the GPU is found with its attached displays.
			//So, get the Gpu name from the first display & store it
			if (curDisplay ==0) {
				affGPUList[gpuCount].setName(gpuDevice.DeviceString);
			}
			//initialize the display win params and associate with its GPU
			displayWinList[displayCount].init(&affGPUList[gpuCount], gpuDevice);
			curDisplay++;
			displayCount++;
		} //end of enumerating displays
		gpuCount++;
	} //end of enumerating gpu's

	//Now create windows on all the displays
	for (int i=0;i<displayCount;i++) {
		printf("\n=== Display Idx %d ===\n",i);
		displayWinList[i].createGLWin(100,100,500,500);
		displayWinList[i].print();
	}

	// Process application messages until the application closes
	MSG  msg;
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}



