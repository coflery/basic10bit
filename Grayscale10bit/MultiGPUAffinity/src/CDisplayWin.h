//
// CDisplayWin.h
//
// Class CDisplayWin - encapsulates all the info specific to a window on an active display
// such as its name, window DC, Gl RC, handle, display extents, gpu name
// Also includes static functions for window creation, setup & event handling 
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef _CDISPLAYWIN_H_
#define _CDISPLAYWIN_H_
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

//Class CDisplayWin
//Encapsulates all attributes of a display with a window contained inside it.
class CDisplayWin {
public:
    HWND    hWin;       // handle to window on this display
	int		winWidth, winHeight; //window dimensions
    HDC     winDC;      // DC of window on this display
	HGLRC	winRC;		// GL Resource Context from winDC
    RECT    rect;       // rectangle limits of display
	bool	primary;	//Is this the primary display
	bool	grayscale;	//Is this a grayscale compatible display
	char	displayName[128];	//name of this display (as given by enumdisplays) eg \\.\DISPLAY1
	char	gpuName[128];	//name of the physical GPU driving this eg Quadro FX 4800

	///Constructor 
	CDisplayWin();
	///true if incoming rect spans this display
	bool spans(RECT r) {
	 return ! ( rect.left > r.right
        || rect.right < r.left
        || rect.top > r.bottom
        || rect.bottom < r.top );
	}
	///input is position and size to set the bounding rectangle for this window
	void setRect(int left, int top, int width, int height) {
		rect.left = left;
		rect.top = top;
		rect.right = left+width;
		rect.bottom = top+height;
	}
	///create window (posx and posy are relative to this display
	virtual HWND createGLWin(int posx, int posy, int width, int height);
	///draw callback for the window
	virtual void draw();
	///Print the attributes of this display
	///WM_SIZE callback for the window
	virtual void resize(GLsizei w, GLsizei h) {
		if (h == 0) h =1;
		winWidth = h;
		winHeight = w;
	}
	virtual void print();
	///Destructor
	virtual ~CDisplayWin();

	//static functions and variables
	///event handling procedure
	static LONG WINAPI winProc(HWND hWin, UINT uMsg, WPARAM wParam, LPARAM lParam);
	///pixel format descriptor constant across all instances of CDisplayWin
	static PIXELFORMATDESCRIPTOR pfd ;
	///Whether the wiindow class is registered
	static bool isClassRegistered;
	///function to choose and set pixel format
	static int setPixelFormat(HDC hDC);
protected:
	///generic create window (posx and posy are relative to this display
	static HWND createWin(int posx, int posy, int width, int height);
	///Just draws a OGL teapot, no windowing specific stuff goes in here
	void oglDraw();
};


#endif