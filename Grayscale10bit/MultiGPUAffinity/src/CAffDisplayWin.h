//
// CAffDisplayWin.h
//
// Class CAffDisplayWin - encapsulates all the info specific to a window on an active display
// that is driven by affinity GPU (1 or many GPU's)
// such as its name, window DC, G RC, handle, display extents, 
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef _CAFFDISPLAYWIN_H_
#define _CAFFDISPLAYWIN_H_
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "CDisplayWin.h"
#include "CAffinityGPU.h"


class CAffDisplayWin : public CDisplayWin {
	CAffinityGPU* pAffinityGPU;	//List of GPU's responsible for rendering this window.
public:
	/// Default constructor
	CAffDisplayWin();
	/// Attach the window to its gpu (immutable) and fill other window specific params
	void init(CAffinityGPU* pGPU, const GPU_DEVICE& pDevice);
	///create window (posx and posy are relative to this display) with no window GLRC
	HWND createGLWin(int posx, int posy, int width, int height);
	///draw callback for the window
	void draw();
	///Print the attributes of this display
	void print();
	///Destructor, doesnt do much but for completenes
	~CAffDisplayWin() {};
};





#endif