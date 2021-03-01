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

//Class CDisplayWin - encapsulates all the info specific to a window on an active display
//such as its name, window DC, G RC, handle, display extents, 
class CDisplayWin {
public:
    HWND    hWin;       // handle to window on this display
	int		winWidth, winHeight; //window dimensions
    HDC     winDC;      // DC of window on this display
	HGLRC	winRC;		// GL Resource Context from winDC
    RECT    rect;       // rectangle limits of display
	bool	primary;	//Is this the primary display
	bool	grayscale;	//Is this a grayscale compatible display
	char	displayName[128];	//name of this display (as given by enumdisplays)
	char	gpuName[128];		//name of GPU driving me

	CDisplayWin();
	///if incoming rect spans this display
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
	HWND createWin(int posx, int posy, int width, int height);
	///draw callback for the window
	void draw();
	///WM_SIZE callback for the window
	void resize(GLsizei w, GLsizei h);
	///Print the attributes of this display
	void print();
	///Destructor
	~CDisplayWin();

	//static functions and variables
	///event handling procedure
	static LONG WINAPI winProc(HWND hWin, UINT uMsg, WPARAM wParam, LPARAM lParam);
	///pixel format descriptor constant across all instances of CDisplayWin
	static PIXELFORMATDESCRIPTOR pfd ;
	///function to choose and set pixel format
	static int setPixelFormat(HDC hDC);

};

#define MAX_NUM_GPUS 4
extern int displayCount;
extern CDisplayWin displayWinList[MAX_NUM_GPUS*2];

#endif