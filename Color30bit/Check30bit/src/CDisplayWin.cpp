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
PFNWGLGETEXTENSIONSSTRINGARBPROC CDisplayWin::wglGetExtensionsString = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC CDisplayWin::wglGetPixelFormatAttribfv = NULL;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC CDisplayWin::wglGetPixelFormatAttribiv = NULL;
PFNWGLCHOOSEPIXELFORMATARBPROC CDisplayWin::wglChoosePixelFormat = NULL;

bool CDisplayWin::isClassRegistered = false;
int CDisplayWin::idx30bit = 0;

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
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		case WM_SIZE:
			GetWindowRect(hWin,&rect);
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (hWin == displayWinList[i].m_hWin) {
						displayWinList[i].resize(LOWORD(lParam), HIWORD(lParam));
					}
					//note that the window that was initially created on 1 display may have moved to another display
					//thats exactly what the function below is checking
					if (displayWinList[i].spans(rect)) 
					//now check that this is a 30bit color compatible display
						if (!displayWinList[i].color30bit) 
							//not a 30-bit color display, just print
							printf("WM_SIZE : Window is now spanning a NON-30bit color display\n");
					InvalidateRect(displayWinList[i].m_hWin, NULL, FALSE);
					UpdateWindow (displayWinList[i].m_hWin);
				}
			}
			break;
		case WM_MOVE:
			RECT rect;
			GetWindowRect(hWin,&rect);
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (displayWinList[i].spans(rect)) 
						//now check that this is a 30bit color compatible display
						if (!displayWinList[i].color30bit) 
							//not a 30-bit color display, just print
							printf("WM_MOVE : Window is now spanning a NON-30bit color display\n");
					InvalidateRect(displayWinList[i].m_hWin, NULL, FALSE);
					UpdateWindow (displayWinList[i].m_hWin);
				}
			}			
			break;
		case WM_PAINT:
			if (displayCount) {
				//get the correct win DC for our window
				for (int i=0;i<displayCount;i++) {
					if (hWin == displayWinList[i].m_hWin) {
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


HWND CDisplayWin::createWin(int posx, int posy, int width, int height) {
	//Create window
	WNDCLASS    wc;
	static char szAppClassName[] = "OpenGL";

	// register the frame class
	if (isClassRegistered == 0) {
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
		isClassRegistered = 1;
	}

	// Create the frame
	HWND hWin = CreateWindow(szAppClassName,
		"Check30bit",
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

int CDisplayWin::initWGLExtensions() {
    // Create a dummy window to query the WGL_ARB_pixelformats
    HWND dummyWin = createWin(100,100,500,500);
    if (dummyWin== NULL) {
        return 0;
    }

	HDC dummyDC = GetDC(dummyWin);
	if (setPixelFormat(dummyDC) == 0)
		return 0;
	HGLRC dummyRC = wglCreateContext(dummyDC);

    // Set the dummy context current
    wglMakeCurrent(dummyDC, dummyRC);

    // Find the 10bpc ARB pixelformat
    wglGetExtensionsString = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");
    if (wglGetExtensionsString == NULL)
    {
        printf("ERROR: Unable to get wglGetExtensionsStringARB function pointer!\n");
        goto Cleanup;
    }

    const char *szWglExtensions = wglGetExtensionsString(dummyDC);
    if (strstr(szWglExtensions, " WGL_ARB_pixel_format ") == NULL) 
    {
        printf("ERROR: WGL_ARB_pixel_format not supported!\n");
        goto Cleanup;
    }

    wglGetPixelFormatAttribiv = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) wglGetProcAddress("wglGetPixelFormatAttribivARB");
    wglGetPixelFormatAttribfv = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC) wglGetProcAddress("wglGetPixelFormatAttribfvARB");
    wglChoosePixelFormat = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");

	if ((wglGetPixelFormatAttribfv==NULL)||(wglGetPixelFormatAttribiv==NULL)||(wglChoosePixelFormat==NULL))
    {
        goto Cleanup;
    }

    int attribsDesired[] = {
        WGL_DRAW_TO_WINDOW_ARB, 1,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        WGL_RED_BITS_ARB, 10,
        WGL_GREEN_BITS_ARB, 10,
        WGL_BLUE_BITS_ARB, 10,
        WGL_ALPHA_BITS_ARB, 2,
        WGL_DOUBLE_BUFFER_ARB, 1,
        0,0
    };
    
    UINT nMatchingFormats;
    if (!wglChoosePixelFormat(dummyDC, attribsDesired, NULL, 1, &idx30bit, &nMatchingFormats))
    {
        printf("ERROR: wglChoosePixelFormat failed!\n");
        goto Cleanup;
    }

    if (nMatchingFormats == 0)
    {
        printf("ERROR: No 10bpc WGL_ARB_pixel_formats found!\n");
        goto Cleanup;
    }

    // Double-check that the format is really 10bpc 
    int redBits;
    int alphaBits;
    int uWglPfmtAttributeName = WGL_RED_BITS_ARB;
    wglGetPixelFormatAttribiv(dummyDC, idx30bit, 0, 1, &uWglPfmtAttributeName, &redBits);
    uWglPfmtAttributeName = WGL_ALPHA_BITS_ARB;
    wglGetPixelFormatAttribiv(dummyDC, idx30bit, 0, 1, &uWglPfmtAttributeName, &alphaBits);

    printf("pixelformat chosen, index %d\n"
        "  red bits: %d\n  alpha bits: %d\n", idx30bit, redBits, alphaBits);
Cleanup:
    wglMakeCurrent(dummyDC, NULL);
    wglDeleteContext(dummyRC);
    ReleaseDC(dummyWin, dummyDC);
    DestroyWindow(dummyWin);	
	return idx30bit;
}

//============== END STATIC MEMBERS =================

CDisplayWin::CDisplayWin() {
	m_hWin = 0;
	m_winDC = 0;
	m_winRC = 0;
	primary = false;
	color30bit = false;
	strcpy(displayName, "");
	strcpy(gpuName, "");
	rect.left =	rect.right = rect.top = rect.bottom = 0;
}



HWND CDisplayWin::create24bitWin(int posx, int posy, int width, int height) {
	m_hWin = createWin(posx+rect.left,posy+rect.top,width, height);
	if (!m_hWin) {
		printf("CDisplayWin::create24bitWin : Couldnt create window\n");;
		return NULL;
	}
	m_winDC = GetDC(m_hWin);
	if (setPixelFormat(m_winDC) == 0)
		return NULL;
	m_winRC = wglCreateContext(m_winDC);
	wglMakeCurrent(m_winDC, m_winRC);
	printf("CDisplayWin::createGLWin : Printing GL Info...\n");

	//set window text to have display name, gpu name, primary and color30bit flags
	char str[256];
	sprintf(str,"%s on %s",displayName, gpuName);
	if (primary) strcat(str,": PRIMARY");
	if (color30bit) strcat(str,", 30BIT COLOR ENABLED");
	SetWindowText(m_hWin,str);

	ShowWindow(m_hWin, 1);
	UpdateWindow(m_hWin);
	SetFocus(m_hWin);
	GLInfo();
	return m_hWin;

}


HWND CDisplayWin::create30bitWin(int posx, int posy, int width, int height) {
    // Finally create the 10bpc window

    m_hWin = createWin(posx+rect.left,posy+rect.top,width, height);
    if (m_hWin == NULL) {
        printf("ERROR: Unable to create the  30bit window!\n");
        return NULL;
    }

    m_winDC = GetDC(m_hWin);

    PIXELFORMATDESCRIPTOR pfd = {0};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    DescribePixelFormat(m_winDC, idx30bit, sizeof(pfd), &pfd);
    SetPixelFormat(m_winDC, idx30bit, &pfd);
    m_winRC = wglCreateContext(m_winDC);
 	wglMakeCurrent(m_winDC, m_winRC);
	//Make sure again that the w

	//set window text to have display name, gpu name, primary and color30bit flags
	char str[256];
	sprintf(str,"%s on %s",displayName, gpuName);
	if (primary) strcat(str,": PRIMARY");
	if (color30bit) strcat(str,", 30BIT COLOR ENABLED");
	SetWindowText(m_hWin,str);

	ShowWindow(m_hWin, 1);
	UpdateWindow(m_hWin);
	SetFocus(m_hWin);
	GLInfo();

    return m_hWin;

}

///Simple draw function - just draws a teapot in this case
void CDisplayWin::draw() {
	wglMakeCurrent(m_winDC, m_winRC);
	// Set the viewport to be the entire window
	glViewport(0, 0, m_winWidth, m_winHeight);
	glMatrixMode(GL_PROJECTION);
	// Reset the coordinate system before modifying
	glLoadIdentity();
	gluPerspective(45.0,(float)m_winWidth/m_winHeight,0.1,100);

	glClearColor(0.0,0.0,0.8,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-2.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireTeapot(0.5f);
	SwapBuffers(m_winDC);
}

///Resize functions, sets the perspective
void CDisplayWin::resize(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;
	m_winWidth = w;
	m_winHeight = h;
}

void CDisplayWin::print() {
	printf("\nDisplay Name\t= %s\n", displayName);
	printf("GPU Name\t= %s\n", gpuName);
	if (primary) 
		printf("PRIMARY DISPLAY\n");
	if (color30bit) 
		printf("30BIT COLOR COMPATIBLE\n");
	printf("Position/Size\t= (%d, %d), %dx%d\n", rect.left, rect.top,rect.right-rect.left,rect.bottom-rect.top );
	GLInfo();
}


CDisplayWin::~CDisplayWin() {
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_winRC);
	if (m_winDC) 
		ReleaseDC(m_hWin, m_winDC);
	if (m_hWin)
		DestroyWindow(m_hWin);
	if (isClassRegistered) {
		UnregisterClass("OpenGL",GetModuleHandle(NULL));
		isClassRegistered = false;
	}

}

