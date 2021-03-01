//
// CDisplayWin.cpp
//
// Class CDisplayWin - encapsulates all the info specific to a window on an active display
// such as its name, window DC, Gl RC, handle, display extents, gpu name
// Also includes static functions for window creation, setup & event handling 
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////
#include "CDisplayWin.h"
#include "CAffDisplayWin.h"
#include "globaldefs.h"
#include <stdio.h>

//defined in glut_teapot.cpp
extern void glutWireTeapot(GLdouble scale);
extern void glutSolidTeapot(GLdouble scale);

extern unsigned int displayCount; //no of displays or screens
extern CAffDisplayWin displayWinList[MAX_NUM_GPUS*2]; //list of displays, each gpu can attah to max 2 displays

//============== STATIC MEMBERS for CDisplayWin ===============
bool CDisplayWin::isClassRegistered = false;
PIXELFORMATDESCRIPTOR CDisplayWin::pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
	1,                              // version number
	PFD_DRAW_TO_WINDOW |            // support window
	PFD_SUPPORT_OPENGL |          // support OpenGL
	PFD_DOUBLEBUFFER,             // double buffered
	PFD_TYPE_RGBA,                  // RGBA type
	24,                             // 24-bit color depth
	0, 0, 0, 0, 0, 0,               // color bits ignored
	0,                              // no alpha buffer
	0,                              // shift bit ignored
	0,                              // no accumulation buffer
	0, 0, 0, 0,                     // accum bits ignored
	32,                             // 32-bit z-buffer      
	0,                              // no stencil buffer
	0,                              // no auxiliary buffer
	PFD_MAIN_PLANE,                 // main layer
	0,                              // reserved
	0, 0, 0                         // layer masks ignored
};


LONG WINAPI CDisplayWin::winProc(HWND hWin, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LONG ret = 1;
	RECT rect;
	switch (uMsg) {
		case WM_DESTROY:
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		case WM_SIZE:
			//get the correct win DC for our window
			for (int i=0;i<displayCount;i++) {
				if (hWin == displayWinList[i].hWin) {
					displayWinList[i].resize(LOWORD(lParam), HIWORD(lParam));
				}
			}
			break;
		case WM_PAINT:
			//get the correct win DC for our window
			for (unsigned int i=0;i<displayCount;i++) {
				if (hWin == displayWinList[i].hWin) {
					displayWinList[i].draw();
					break;
				}
			}
			break;
		case WM_KEYDOWN:
			switch(wParam) {
				case VK_SPACE:
					GLInfo();
					break;
				case VK_ESCAPE:
					PostQuitMessage(0);
					return 0;
			}
		case WM_KEYUP:
			return 0;		
		default:
			// pass all unhandled messages to DefWindowProc
			ret = DefWindowProc(hWin, uMsg, wParam, lParam);
			break;
	}
	// return 1 if handled message, 0 if not
	return ret;
}


// Functions to choose and set the pixel format 
int CDisplayWin::setPixelFormat(HDC hDC)
{
	// get the appropriate pixel format 
	int pf = ChoosePixelFormat(hDC, &pfd);
	if (pf == 0) {
		printf("ChoosePixelFormat() failed:  Cannot find format specified."); 
		return 0;
	} 
	// set the pixel format
	if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
		printf("SetPixelFormat() failed:  Cannot set format specified.");
		return 0;
	} 
	return pf;
}  

// Create a window of widthxheight to lie within the display 
// This function doesn't do any OpenGL initialization, 
// calling functions must do that after this returns
HWND CDisplayWin::createWin(int posx, int posy, int width, int height) {
	//Create window
	WNDCLASS    wc;

	// register the frame class
	if (isClassRegistered == false) {
		wc.style         = 0;
		wc.lpfnWndProc   = (WNDPROC)CDisplayWin::winProc;
		wc.cbClsExtra    = 0;
		wc.cbWndExtra    = 0;
		wc.hInstance     = GetModuleHandle(NULL);
		wc.hIcon         = NULL;
		wc.hCursor       = LoadCursor(NULL,IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		wc.lpszMenuName  = NULL;
		wc.lpszClassName = "OpenGL";

		if (!RegisterClass(&wc)) return FALSE;
		isClassRegistered = true;
	}

	// Create the frame
	HWND hWin = CreateWindow("OpenGL",
		"MultiGPUAffinity",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		posx, posy,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);

	return hWin;
}
//============== END STATIC MEMBERS =================

CDisplayWin::CDisplayWin() {
	hWin = 0;
	winRC = 0;
	winDC = 0;
	primary = false;
	grayscale = false;
	strcpy(displayName, "");
	strcpy(gpuName, "");
	rect.left =	rect.right = rect.top = rect.bottom = 0;
}


//Calls createWin, does all the pixel format setup & creates the OpenGL win context
HWND CDisplayWin::createGLWin(int posx, int posy, int width, int height) {
	hWin = createWin(posx+rect.left,posy+rect.top,width, height);
	if (!hWin)
		ERR_MSG("CDisplayWin::createGLWin : Couldnt create window\n");;
	winDC = GetDC(hWin);
	if (setPixelFormat(winDC) == 0)
		return NULL;
	winRC = wglCreateContext(winDC);
	wglMakeCurrent(winDC, winRC);
	printf("CDisplayWin::createGLWin : Printing GL Info...\n");
	GLInfo();
	return hWin;
}


///base drawing call, assuming context is already made current
void CDisplayWin::oglDraw() {
	// Set the viewport to be the entire window
	glViewport(0, 0, winWidth, winHeight);
	glMatrixMode(GL_PROJECTION);
	// Reset the coordinate system before modifying
	glLoadIdentity();
	gluPerspective(45.0,(float)winWidth/winHeight,0.1,100);

	glClearColor(0.0,0.0,0.8,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-2.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireTeapot(0.5f);
}

///draw callback, makes window context current and calls generic draw
void CDisplayWin::draw() {
	wglMakeCurrent(winDC, winRC);
	oglDraw();
	SwapBuffers(winDC);
}


void CDisplayWin::print() {
	printf("Display Name\t= %s\n", displayName);
	printf("\tGPU Name\t= %s\n", gpuName);
	if (primary) 
		printf("\tPRIMARY DISPLAY\n");
	if (grayscale) 
		printf("\tGRAYSCALE COMPATIBLE\n");
	printf("\tPosition/Size\t= (%d, %d), %dx%d\n", rect.left, rect.top,rect.right-rect.left,rect.bottom-rect.top );
}


CDisplayWin::~CDisplayWin() {
	wglMakeCurrent(NULL, NULL);
	if (winRC) //remember no winrc in the case of affinity window
		wglDeleteContext(winRC);
	if (winDC) 
		ReleaseDC(hWin, winDC);
	if (hWin)
		DestroyWindow(hWin);
	if (isClassRegistered) {
		UnregisterClass("OpenGL",GetModuleHandle(NULL));
		isClassRegistered = false;
	}
}

