//
// CAffDisplayWin.cpp
//
// Class CAffDisplayWin - encapsulates all the info specific to a window on an active display
// that is driven by affinity GPU (1 or many GPU's)
// such as its name, window DC, G RC, handle, display extents, 
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include "CAffDisplayWin.h"
#include "globaldefs.h"
#include <stdio.h>

//not much here just calling base class constructor and set the pointer to aff GPU to be 0
CAffDisplayWin::CAffDisplayWin(): CDisplayWin(),pAffinityGPU(0) {}

//initialize with handle to affinity GPU and the GPU_DEVICE that comes from the 
//WGL AFFINITY extension
void CAffDisplayWin::init(CAffinityGPU* pGPU, const GPU_DEVICE& pDevice) {
	pAffinityGPU = pGPU;
	strcpy(displayName,pDevice.DeviceName);
	strcpy(gpuName,pDevice.DeviceString);
	rect.left = pDevice.rcVirtualScreen.left;
	rect.right = pDevice.rcVirtualScreen.right;
	rect.top = pDevice.rcVirtualScreen.top;
	rect.bottom = pDevice.rcVirtualScreen.bottom;
	if ((pDevice.Flags & DISPLAY_DEVICE_PRIMARY_DEVICE)) {
		primary = true;
	}
}


//calls base class createwin function
//The attach the affinity context to this windows DC
//NOTE: Do not create a new window context via wglCreateContext
HWND CAffDisplayWin::createGLWin(int posx, int posy, int width, int height) {
	hWin = createWin(posx+rect.left,posy+rect.top,width, height);
	if (!hWin)
		ERR_MSG("Couldnt create window\n");;
	winDC = GetDC(hWin);
	if (setPixelFormat(winDC) == 0)
		return NULL;
	//do NOT create window context
	//Attach Window DC to Affinity Context
	wglMakeCurrent(winDC, pAffinityGPU->getRC());
	ShowWindow(hWin, 1);
	UpdateWindow(hWin);
	printf("CAffDisplayWin::createGLWin : Printing GL Info...\n");
	GLInfo();
	return hWin;
}

///Simple draw function - just draws a teapot in this case
void CAffDisplayWin::draw() {
	wglMakeCurrent(winDC, pAffinityGPU->getRC());
	oglDraw();
	SwapBuffers(winDC);
}

void CAffDisplayWin::print() {
	CDisplayWin::print(); 
	pAffinityGPU->print(); //print the GPU's driving the display
}


