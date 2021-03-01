//
// 30bitdemo.cpp
// Main test program - opens up a 30-bit and 24-bit window letting user
// toggle between the different rendering modes as well as using on/off screen buffers 
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
//For EXR file loading
#include <ImfRgbaFile.h>
#include <ImfArray.h>
#include <half.h>
//For FBO
#include "framebufferObject.h"


PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsString = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfv = NULL;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribiv = NULL;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat = NULL;
PFNGLDRAWBUFFERSARBPROC glDrawBuffers = NULL;

HDC ghDC30bit =NULL, ghDC24bit = NULL; //Window DC for the 30 and 24bit windows
HGLRC ghRC30bit = NULL, ghRC24bit = NULL; //GL context for the 30 and 24 bit window
HWND ghWnd30bit = NULL, ghWnd24bit = NULL; //handles for the 30bit and 24 bit

//GL Texture Ids for the 3 textures used - 1) RGBA16 Gradient Texture, 2) RGB10A2 Gradient Texture 3) OpenEXR half float texture
GLuint gTexRGBA16=NULL, gTexRGB10A2=NULL, gTexEXR = NULL ; 
unsigned int exrwidth = 0, exrheight = 0; //dimensions of the EXR Image
unsigned int width = 2048, height = 2048;

//4 different draw modes
typedef enum DRAWMODE {DRAW_SHADED=0,DRAW_TEXTURE_RGBA16,DRAW_TEXTURE_RGB10A2,DRAW_TEXTURE_EXR};
char* gDrawModeDesc[4] = {"Shaded Quad", "RGBA16 Texture","RGB10_A2 Texture","OpenEXR File"};
int gDrawMode = DRAW_SHADED; 

//FBO related
bool gfboEnabled = false; //fbo is disabled by default
FramebufferObject* fbo = NULL; //instance of the fbo class defined in framebufferObject.h
GLuint gfboTextures[2];

//For mouse interaction
bool    mb[3];		        // Array Used To Store Mouse Button State
int		prevX = -1;         // Previous X coordinate from mouse
int		prevY = -1;			// Previous Y coordinate from mouse

//For panning
GLfloat x_start = 0.0;		// X starting location within half width window.
GLfloat x_end = 0.0;		// X ending location wthin half width window.
GLfloat y_start = 0.0;		// Y starting location within half width window.
GLfloat y_end = 0.0;		// Y ending location within half width window.
bool isInitialized = false;



//Packed pixel type and format
GLenum packedType = GL_UNSIGNED_INT_10_10_10_2; //or GL_UNSIGNED_INT_2_10_10_10_REV
GLenum packedFormat = GL_RGBA; //or GL_RGB/GL_BGRA/GL_BGR
/*
http://www.opengl.org/registry/specs/EXT/packed_pixels.txt

        UNSIGNED_INT_10_10_10_2_EXT:

             31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
            +-----------------------------+-----------------------------+-----------------------------+-----+
            |                             |                             |                             |     |
            +-----------------------------+-----------------------------+-----------------------------+-----+

                       first                         second                        third               fourth
                       element                       element                       element             element
*/

///GL context must be valid. Loads the 3 textures, should only be called once
void oglInit() {
	//basically this init is only done when we have the 30bitRC, 24bitRC and when we are already not initialized
	if (isInitialized)
		return;

	//Generate a RGBA (ushort component) horizontal gradient
	unsigned short *pImageData = new unsigned short[width*height*4];
	for (unsigned int y=0; y < height; y++) {
		for (unsigned int x=0; x < width; x++) 	{
			int startIdx = (width*y*4)+ x*4;
			unsigned short value = 65536*(x)/(float)(width);
			pImageData[startIdx] = 0; //R
			pImageData[startIdx+1] = value; //G
			pImageData[startIdx+2] = 0; //B
			pImageData[startIdx+3] = 0; //A
		}
	}

	//Load the gradient data into a RGBA16 2D texture
	glGenTextures(1, &gTexRGBA16);  
	glBindTexture(GL_TEXTURE_2D, gTexRGBA16);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // 4 16-bit components per pixel
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16, width, height, 0, GL_RGBA , GL_UNSIGNED_SHORT, pImageData);
	//Make sure we got the right RGBA16 internal format
	GLint internalFormat;
	glGetTexLevelParameteriv(GL_TEXTURE_2D,0, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);
	assert(internalFormat == GL_RGBA16);

	//Now pack RGBA16 gradient data into RGB10A2 pixel data looking at the packedType and packedFormat specified
	unsigned int* packedData = new unsigned int[width*height]; //the 4 components will be packed in 1 unsigned int
	float scale = 1024.0/65536.0; //here we rescale the ushort 16-bit per component data created earlier to 10bits ie 0..1024
	for (unsigned int y=0; y < height; y++) {
		for (unsigned int x=0; x < width; x++) {
			int offset = (width*y)+ x;
			unsigned int alpha = pImageData[offset*4+3]*4.0/65536.0; //since we use 2 bits for alpha, scale to range 0..3
			alpha &= 0x3; //get 2 lower bits
			unsigned int blue = pImageData[offset*4+2]*scale;
			blue &= 0x3FF;	 //get the 10 bits
			unsigned int green = pImageData[offset*4+1]*scale;
			green &= 0x3FF;//10 bits
			unsigned int red = pImageData[offset*4]*scale;
			red &= 0x3FF; //10bits

			if (packedType == GL_UNSIGNED_INT_10_10_10_2) {
				if (packedFormat == GL_RGBA) //R10G10B10A2
					packedData[offset] = (red<<22 | green<<12 | blue<<2 | alpha);
				else  //packedFormat is GL_BGRA, packed in B10G10R10A2
					packedData[offset] = (blue<<22 | green<<12 |red<<2 | alpha);
			}
			else if (packedType == GL_UNSIGNED_INT_2_10_10_10_REV) {
				if (packedFormat == GL_RGBA) //A2B10G10R10
					packedData[offset] = (alpha<<30 | red<<22 | green<<12 | blue<<2);
				else  //packedFormat = GL_BGRA, packed as A2R10G10B10
					packedData[offset] = (alpha<<30 | red<<22 | green<<12 | blue<<2);
			}
		}
	}
	//Now download into the packed pixel texture
	glGenTextures(1, &gTexRGB10A2);  
	glBindTexture(GL_TEXTURE_2D, gTexRGB10A2);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // remember 1 32-bit pixel
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB10_A2, width, height, 0, packedFormat , packedType, packedData);
	glGetTexLevelParameteriv(GL_TEXTURE_2D,0, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);
	assert(internalFormat == GL_RGB10_A2); //confirm we have packed pixel internal format
	free(pImageData);
	free(packedData);

	//Load EXR file now
	Imf::Rgba * pixelBuffer;
	try
	{
		Imf::RgbaInputFile in("test.exr");
		Imath::Box2i win = in.dataWindow();
		Imath::V2i dim(win.max.x - win.min.x + 1, win.max.y - win.min.y + 1);
		pixelBuffer = new Imf::Rgba[dim.x * dim.y];
		int dx = win.min.x;
		int dy = win.min.y;
		in.setFrameBuffer(pixelBuffer - dx - dy * dim.x, 1, dim.x);
		in.readPixels(win.min.y, win.max.y);
		exrwidth = dim.x; exrheight = dim.y;
	}
	catch(Iex::BaseExc & e)
	{
		std::cerr << e.what() << std::endl;
		 // Handle exception.
	}
	//possibly NPOT texture	
	glGenTextures(1, &gTexEXR);
	glBindTexture(GL_TEXTURE_RECTANGLE_NV, gTexEXR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_RECTANGLE_NV, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_RECTANGLE_NV, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_RECTANGLE_NV, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_RECTANGLE_NV, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_RECTANGLE_NV, 0, GL_RGBA16F_ARB, exrwidth, exrheight, 0,GL_RGBA,GL_HALF_FLOAT_ARB, pixelBuffer);
	glGetTexLevelParameteriv(GL_TEXTURE_RECTANGLE_NV,0, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);
	assert(internalFormat == GL_RGBA16F_ARB); //confirm we have RGBA16F internal format
	delete [] pixelBuffer; //done with exr buffer delete it

	//FBO initialization
	glDrawBuffers = (PFNGLDRAWBUFFERSARBPROC)wglGetProcAddress("glDrawBuffersARB");
	glGenTextures(2,gfboTextures);
	//offscreen floating point texture
	glBindTexture(GL_TEXTURE_2D, gfboTextures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);	
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA16F_ARB,width, height,0,GL_RGBA,GL_HALF_FLOAT_ARB,0);

	//offscreen unsigned byte texture
	glBindTexture(GL_TEXTURE_2D, gfboTextures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);	
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,0);

	//Attach both textures
	fbo = new FramebufferObject;
	fbo->Bind();
	fbo->AttachTexture(GL_TEXTURE_2D,gfboTextures[0],GL_COLOR_ATTACHMENT0_EXT);
	fbo->AttachTexture(GL_TEXTURE_2D,gfboTextures[1],GL_COLOR_ATTACHMENT1_EXT);
	fbo->IsValid(); //validate fbo
	FramebufferObject::Disable();

	//Mouse panning parameters
	x_start = 0;
	x_end = (GLfloat)width;
	y_start = 0;
	y_end = (GLfloat)height;
	isInitialized = true;
}

//DRAWING FUNCTIONS
void drawShadedQuads(float x0, float y0, float x1, float y1) {
	glBegin(GL_QUADS);
		glColor3f(0.0,0.25,0.0);	glVertex2f(x0,y0);
		glColor3f(0.0,0.75,0.0);	glVertex2f(x1,y0);
		glColor3f(0.0,0.75,0.0);	glVertex2f(x1,y1);
		glColor3f(0.0,0.25,0.0);	glVertex2f(x0,y1);	
	glEnd();
}

void drawTexturedQuads(float x0, float y0, float x1, float y1) {
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(0.25,0.0); glVertex2f(x0,y0);
		glTexCoord2f(0.75,0.0); glVertex2f(x1,y0);
		glTexCoord2f(0.75,1.0); glVertex2f(x1,y1);
		glTexCoord2f(0.25,1.0); glVertex2f(x0,y1);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawRectTexturedQuads(float maxu, float maxv, float x0, float y0, float x1, float y1) {
	glEnable(GL_TEXTURE_RECTANGLE_NV);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0); glVertex2f(x0,y0);
		glTexCoord2f(maxu,0.0); glVertex2f(x1,y0);
		glTexCoord2f(maxu,maxv); glVertex2f(x1,y1);
		glTexCoord2f(0.0,maxv); glVertex2f(x0,y1);	
	glEnd();
	glDisable(GL_TEXTURE_RECTANGLE_NV);
}

///Draw function called from WM_PAINT with a valid GL context
void oglDraw(int winWidth, int winHeight)
{
	if (gfboEnabled) {
		fbo->Bind();
		//1st pass = Render to two offscreen textures at once
		GLenum buffers[] = {GL_COLOR_ATTACHMENT0_EXT, GL_COLOR_ATTACHMENT1_EXT};
		glDrawBuffers(2,buffers); 
	}

	glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float x0 = x_start;
	float x1 = x_end;
	float y0 = y_start;
	float y1 = y_end;

	if (gfboEnabled) { //in this case the vertex:texture mapping is 1:1
		x0 = y0 = 0;
		x1 = width; y1 = height;
		glViewport(0,0, width, height);
	}
	else {
	    glViewport(0,0, winWidth, winHeight);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (gfboEnabled)  //in this case the vertex:texture mapping is 1:1
		gluOrtho2D(0,width,0,height);
	else
		gluOrtho2D(0,winWidth,0,winHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	switch (gDrawMode) {
		case DRAW_SHADED: //draw a shaded quad with green color 0..1
			drawShadedQuads(x0,y0,x1,y1);
			break;
		//RGBA16 or the packed pixel gradient texture
		case DRAW_TEXTURE_RGBA16:
		case DRAW_TEXTURE_RGB10A2:
			glColor3f(1.0,1.0,1.0); 
			if (gDrawMode == DRAW_TEXTURE_RGBA16)
				glBindTexture(GL_TEXTURE_2D,gTexRGBA16);
			else
				glBindTexture(GL_TEXTURE_2D,gTexRGB10A2);
			drawTexturedQuads(x0,y0,x1,y1);
			break;
		//The EXR image
		case DRAW_TEXTURE_EXR:
			glColor3f(1.0,1.0,1.0); 
			glBindTexture(GL_TEXTURE_RECTANGLE_NV,gTexEXR);
			drawRectTexturedQuads(exrwidth,exrheight,x0,y0,x1,y1);			
			break;
	}
	//2ND pass - blit offscreen textures to screen quads, side by side
	if (gfboEnabled) {
		FramebufferObject::Disable();
		//Now blit offscreen texture to onscreen window
	    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		//Create left viewport, BLIT the float texture to screen
		//Create right viewport BLIT The ubyte texture to screen
		for (int i=0;i<2;i++) {
			glBindTexture(GL_TEXTURE_2D,gfboTextures[i]);
			glViewport(i*winWidth/2,0, winWidth/2, winHeight);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(0,winWidth/2,0,winHeight);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0,0.0); glVertex2f(x_start,y_start);
				glTexCoord2f(1.0,0.0); glVertex2f(x_end,y_start);
				glTexCoord2f(1.0,1.0); glVertex2f(x_end,y_end);
				glTexCoord2f(0.0,1.0); glVertex2f(x_start,y_end);	
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	} //end of if gfboEnabled

}

void redrawAll() {
	InvalidateRect(ghWnd30bit, NULL, FALSE);
	UpdateWindow (ghWnd30bit);
	if (ghWnd24bit) {
		InvalidateRect(ghWnd24bit, NULL, FALSE);
		UpdateWindow (ghWnd24bit);
	}
}


GLvoid PanGLScene(int x, int y)							// Pan Image In The GL Window
{
	// The first time, simply capture the X and Y location.
	// Subsequent times, calculate the change in the X and Y 
	// location and pan the image in the window accordingly.
	if ((prevX != -1) && (prevY != -1)) {
		int deltaX = prevX - x;
		int deltaY = prevY - y;

		x_start -= deltaX;
		y_start += deltaY;
		x_end = x_start + (GLfloat)width;	
		y_end = y_start + (GLfloat)height;
	}

	prevX = x;
	prevY = y;
	fprintf(stderr, "x = %d  y = %d\n", x, y);
	redrawAll();

}
//switch to next draw mode
void switchDrawMode() {
	char str[256];
	gDrawMode++;
	gDrawMode%=4;
	//set 30-bit window text to current draw mode
	sprintf(str,"30 Bit Color Window - ");
	strcat(str,gDrawModeDesc[gDrawMode]);
	SetWindowText(ghWnd30bit,str);		            
	//set 24-bit window text to current draw mode
	if (ghWnd24bit) {
		sprintf(str,"24 Bit Color Window - ");		 
		strcat(str,gDrawModeDesc[gDrawMode]);
		SetWindowText(ghWnd24bit,str);		            
	}
	redrawAll();
}

LRESULT WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    switch(uMsg) {
        case WM_PAINT: 
            {
                RECT rect;
                GetClientRect(hWnd, &rect);
				if (hWnd == ghWnd30bit) {
					wglMakeCurrent(ghDC30bit, ghRC30bit);
					oglDraw(rect.right, rect.bottom);
					SwapBuffers(ghDC30bit);
					wglMakeCurrent(ghDC30bit, NULL);
					ReleaseDC(hWnd, ghDC30bit);
				} else if (hWnd == ghWnd24bit) {
					wglMakeCurrent(ghDC24bit, ghRC24bit);
					oglDraw(rect.right, rect.bottom);
					SwapBuffers(ghDC24bit);
					wglMakeCurrent(ghDC24bit, NULL);
					ReleaseDC(hWnd, ghDC24bit);
				}
                ValidateRect(hWnd, NULL);
                return 0;
            }
        break;
        case WM_KEYDOWN:
		    switch ( wParam )
		    {
		        case VK_ESCAPE:
			        PostQuitMessage(0);
			        return 0;
				case VK_SPACE: //switch between drawing modes and display mode on title bar
					switchDrawMode();
					return 0;
				case 0x46: //key F
					gfboEnabled = 1-gfboEnabled;
					redrawAll();
					return 0;
            }
        case WM_SIZE:
            // Invalidate so the viewport gets refreshed
            InvalidateRect(hWnd, NULL, FALSE);
        break;
	case WM_MOUSEMOVE:								// Mouse moved in window
		if (mb[0]) {
			PanGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord = X, HiWord=Y
		}
		return 0;
	case WM_LBUTTONDOWN:							// Left mouse button down
		mb[0] = TRUE;		
		return 0;
	case WM_LBUTTONUP:								// Left mouse button up
		mb[0] = FALSE;
		prevX = -1;									// Reset mouse coordinate state
		prevY = -1;
		return 0;        
	case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL RegisterOpenGLWindowClass(const char szClassName[])
{
    WNDCLASSEX wndclass = {0};
    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_OWNDC;
    wndclass.lpszClassName = szClassName;
    wndclass.lpfnWndProc = (WNDPROC) WindowProc;
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);   

    if (RegisterClassEx(&wndclass) == 0)
    {
        printf("ERROR: Unable to register the OpenGL window class!\n");
        return FALSE;
    }

    return TRUE;
}

HWND Create8bpcOpenGLWindow(const char szClassName[], const char szWindowTitle[], BOOL bForce8bpc, HDC& myDC, HGLRC& myGLRC)
{
    HWND hWnd;

    hWnd = CreateWindow(szClassName, szWindowTitle, WS_OVERLAPPEDWINDOW, 0, 0, 400, 400, 
        (HWND) NULL, (HMENU) NULL, NULL, NULL);

    if (hWnd == NULL)
    {
        printf("ERROR: Unable to create the '%s' window!\n", szWindowTitle);
        return NULL;
    }

    myDC = GetDC(hWnd);
    if (myDC == NULL)
    {
        printf("ERROR: Unable to get DC for the '%s' window DC!\n", szWindowTitle);
        DestroyWindow(hWnd);
        return NULL;
    }

    PIXELFORMATDESCRIPTOR pfd = {0};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
    if (bForce8bpc) 
    {
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 24;
    }

    int index = ChoosePixelFormat(myDC, &pfd);

    if (index == 0)
    {
        ReleaseDC(hWnd, myDC);
        DestroyWindow(hWnd);
        printf("ERROR: Couldn't create the pixelformat for the '%s' window!\n", szWindowTitle);
        return NULL;
    }

    assert(index > 0);

    DescribePixelFormat(myDC, index, sizeof(pfd), &pfd);

    if (!bForce8bpc && ((pfd.dwFlags & PFD_GENERIC_FORMAT) != 0))
    {
        printf("ERROR: Pixelformat %d is not hw accelerated, unable to get one for the '%s' window!\n", index, szWindowTitle);
        ReleaseDC(hWnd, myDC);
        DestroyWindow(hWnd);
        return NULL;
    }

    SetPixelFormat(myDC, index, &pfd);

    myGLRC = wglCreateContext(myDC);
 
    if (myGLRC == NULL)
    {
        printf("ERROR: Unable to create the GL rendering context for the '%s' window!\n", szWindowTitle);
        ReleaseDC(hWnd, myDC);
        DestroyWindow(hWnd);
        return NULL;
    }
    return hWnd;
}

HWND Create10bpcOpenGLWindow(const char szClassName[], const char szWindowTitle[])
{
    // Create a dummy window to query the WGL_ARB_pixelformats
	HGLRC dummyRC;
	HDC dummyDC;
    HWND dummyWin = Create8bpcOpenGLWindow(szClassName, "Dummy", FALSE, dummyDC, dummyRC);
    if (dummyWin== NULL)
    {
        return NULL;
    }

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

    if ((wglGetPixelFormatAttribfv == NULL) || (wglGetPixelFormatAttribiv == NULL) || (wglChoosePixelFormat == NULL))
    {
        printf("ERROR: Unable to get WGL_ARB_pixel_format function pointers!\n");
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
    int index = 0;
    if (!wglChoosePixelFormat(dummyDC, attribsDesired, NULL, 1, &index, &nMatchingFormats))
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
    wglGetPixelFormatAttribiv(dummyDC, index, 0, 1, &uWglPfmtAttributeName, &redBits);
    uWglPfmtAttributeName = WGL_ALPHA_BITS_ARB;
    wglGetPixelFormatAttribiv(dummyDC, index, 0, 1, &uWglPfmtAttributeName, &alphaBits);

    printf("pixelformat chosen, index %d\n"
        "  red bits: %d\n  alpha bits: %d\n", index, redBits, alphaBits);

    // Finally create the 10bpc window

    ghWnd30bit = CreateWindow(szClassName, szWindowTitle, WS_OVERLAPPEDWINDOW, 0, 0, 400, 400, 
        (HWND) NULL, (HMENU) NULL, NULL, NULL);

    if (ghWnd30bit == NULL)
    {
        printf("ERROR: Unable to create the '%s' window!\n", szWindowTitle);
        goto Cleanup;
    }

    ghDC30bit = GetDC(ghWnd30bit);
    if (ghDC30bit == NULL)
    {
        printf("ERROR: Unable to get the '%s' window DC!\n", szWindowTitle);
        DestroyWindow(ghWnd30bit);
        goto Cleanup;
    }

    PIXELFORMATDESCRIPTOR pfd = {0};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;

    DescribePixelFormat(ghDC30bit, index, sizeof(pfd), &pfd);

    SetPixelFormat(ghDC30bit, index, &pfd);

    ghRC30bit = wglCreateContext(ghDC30bit);
 
    if (ghRC30bit == NULL)
    {
        printf("ERROR: Unable to create the GL rendering context for the '%s' window!\n", szWindowTitle);
        ReleaseDC(ghWnd30bit, ghDC30bit);
        DestroyWindow(ghWnd30bit);
        goto Cleanup;
    }
    ReleaseDC(ghWnd30bit, ghDC30bit);

// Fall through to cleanup

Cleanup:
    wglMakeCurrent(dummyDC, NULL);
    wglDeleteContext(dummyRC);
    ReleaseDC(dummyWin, dummyDC);
    DestroyWindow(dummyWin);

    wglMakeCurrent(ghDC30bit, ghRC30bit);
	oglInit();	

    return ghWnd30bit;
}

int main(int argc, char* argv[])
{
    MSG msg;
    BOOL bShow8bpc = TRUE;

    const char szWindowClass[] = "OpenGLWindowClass";

    printf("10bpc test application (c) NVIDIA Corporation\nBuilt on %s @ %s\n", __DATE__, __TIME__);

    printf("Usage: 10bpctest [bpc]\n"
        "  bpc: Bits per component of the OpenGL window\n"
        "\t\t8 Show only the 8bpc window\n"
        "\t\t10 Show only the 10bpc window\n"
        "\t\tBy default, show both 8bpc and 10bpc windows\n");

    if (argc == 2)
    {
        switch (atoi(argv[1]))
        {
            case 10:
                bShow8bpc = FALSE;
            break;
        }
    }
   
    if (!RegisterOpenGLWindowClass(szWindowClass))
    {
        // Couldn't register the window class
        return 0;
    }

    if ((ghWnd30bit = Create10bpcOpenGLWindow(szWindowClass, "OpenGL 10bpc Demo")) == NULL)    {
        return 0;
    }
    ShowWindow(ghWnd30bit, SW_SHOW);
    UpdateWindow(ghWnd30bit);

	if (bShow8bpc) 
    {
        if ((ghWnd24bit = Create8bpcOpenGLWindow(szWindowClass, "OpenGL 8bpc Demo", TRUE, ghDC24bit, ghRC24bit)) == NULL)
        {
            return 0;
        }
		wglShareLists(ghRC30bit, ghRC24bit);
        ShowWindow(ghWnd24bit, SW_SHOW);
        UpdateWindow(ghWnd24bit);
    }
	

    
    while (BOOL bRet = GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (bRet == -1)
        {
            break;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
	return 0;
}