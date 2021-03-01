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
#include <stdio.h>
#define GET_GLERROR()                                          \
{                                                                 \
    GLenum err = glGetError();                                    \
    if (err != GL_NO_ERROR) {                                     \
    fprintf(stderr, "[%s line %d] GL Error: %s\n",                \
    __FILE__, __LINE__, gluErrorString(err));                     \
    fflush(stderr);                                               \
    }                                                             \
}

#define GL_GETERROR                                                     \
{                                                                       \
	GLenum  err = glGetError();                                         \
	char    cbuf[64];                                                   \
	if (err != GL_NO_ERROR) {                                           \
	wsprintf((LPTSTR)cbuf, (LPCTSTR)"[%s line %d] GL Error: %s\n",  \
	__FILE__, __LINE__, gluErrorString(err));                     \
	MessageBox(NULL, cbuf, "Error", MB_OK);                         \
	exit(0);                                                        \
	}                                                                   \
}

int displayCount = 0;
CDisplayWin displayWinList[MAX_NUM_GPUS*2];

//defined in glut_teapot.cpp
extern void glutWireTeapot(GLdouble scale);
extern void glutSolidTeapot(GLdouble scale);

void GLInfo() {
	printf("OpenGL vendor: %s\n", glGetString(GL_VENDOR));
	printf("OpenGL renderer: %s\n", glGetString(GL_RENDERER));
	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
}


//============== STATIC MEMBERS ===============
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
			GetClientRect(hWin,&rect);
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (hWin == displayWinList[i].hWin) {
						displayWinList[i].resize(LOWORD(lParam), HIWORD(lParam));
					}
					//note that the window that was initially created on 1 display may have moved to another display
					//thats exactly what the function below is checking
					if (displayWinList[i].spans(rect)) 
					//now check that this is a grayscale compatible display
						if (!displayWinList[i].grayscale) 
							//not a grayscale display, just print
							printf("WM_SIZE : Window is now spanning a NON-grayscale display\n");
				}
			}
			break;
		case WM_MOVE:
			RECT rect;
			GetClientRect(hWin,&rect);
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (displayWinList[i].spans(rect)) 
						//now check that this is a grayscale compatible display
						if (!displayWinList[i].grayscale) 
							//not a grayscale display, just print
							printf("WM_MOVE : Window is now spanning a NON-grayscale display\n");
				}
			}			
			break;
		case WM_PAINT:
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (hWin == displayWinList[i].hWin) {
						displayWinList[i].draw();
						break;
					}
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
	int pf;
	// get the appropriate pixel format 
	pf = ChoosePixelFormat(hDC, &pfd);
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


//============== END STATIC MEMBERS =================


CDisplayWin::CDisplayWin() {
	hWin = 0;
	winDC = 0;
	winRC = 0;
	primary = false;
	grayscale = false;
	strcpy(displayName, "");
	strcpy(gpuName, "");
	rect.left =	rect.right = rect.top = rect.bottom = 0;
}


//Create a window of 500x500 to lie within the display 
//The attach the affinity context to this windows DC
HWND CDisplayWin::createWin(int posx, int posy, int width, int height) {
	//Create window
	WNDCLASS    wc;
	static char szAppClassName[] = "OpenGL";
	static bool classRegistered = 0;

	// register the frame class
	if (classRegistered == 0) {
		wc.style         = 0;
		wc.lpfnWndProc   = (WNDPROC)CDisplayWin::winProc;
		wc.cbClsExtra    = 0;
		wc.cbWndExtra    = 0;
		wc.hInstance     = GetModuleHandle(NULL);
		wc.hIcon         = NULL;
		wc.hCursor       = LoadCursor(NULL,IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		wc.lpszMenuName  = NULL;
		wc.lpszClassName = szAppClassName;

		if (!RegisterClass(&wc)) return FALSE;
		classRegistered = 1;
	}

	// Create the frame
	hWin = CreateWindow(szAppClassName,
		"CheckGrayscale",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		posx+rect.left, posy+rect.top,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);

	// make sure window was created
	if (!hWin) 
		return FALSE;
	ShowWindow(hWin, 1);
	UpdateWindow(hWin);
	winDC = GetDC(hWin);
	if (setPixelFormat(winDC) == 0)
		return NULL;
	winRC = wglCreateContext(winDC);
	wglMakeCurrent(winDC, winRC);
	//set window text to have display name, gpu name, primary and grayscale flags
	char str[256];
	sprintf(str,"%s on %s",displayName, gpuName);
	if (primary) strcat(str,": PRIMARY");
	if (grayscale) strcat(str,", GRAYSCALE");
	SetWindowText(hWin,str);

	ShowWindow(hWin, 1);
	UpdateWindow(hWin);
	SetFocus(hWin);
	return hWin;
}

///Simple draw function - just draws a teapot in this case
void CDisplayWin::draw() {
	wglMakeCurrent(winDC, winRC);
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
	SwapBuffers(winDC);
}

///Resize functions, sets the perspective
void CDisplayWin::resize(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;
	winWidth = w;
	winHeight = h;
}

void CDisplayWin::print() {
	printf("\nDisplay Name\t= %s\n", displayName);
	printf("GPU Name\t= %s\n", gpuName);
	if (primary) 
		printf("PRIMARY DISPLAY\n");
	if (grayscale) 
		printf("GRAYSCALE COMPATIBLE\n");
	printf("Position/Size\t= (%d, %d), %dx%d\n", rect.left, rect.top,rect.right-rect.left,rect.bottom-rect.top );
	GLInfo();
}


CDisplayWin::~CDisplayWin() {
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(winRC);
	if (winDC) 
		ReleaseDC(hWin, winDC);
	if (hWin)
		DestroyWindow(hWin);
	static bool isClassRegistered = true;
	if (isClassRegistered) {
		UnregisterClass("OpenGL",GetModuleHandle(NULL));
		isClassRegistered = false;
	}

}

