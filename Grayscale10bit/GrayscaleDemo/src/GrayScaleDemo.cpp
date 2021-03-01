//
// GrayScaleDemo.cpp
//
// Main driver program for the 10-bit display, Loads a file and displays in 10/12bit
// using the lookup table created in GrayScaleTable.h
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <GL\glew.h>	
#include <GL\gl.h>			// Header Files For The OpenGL
#include <GL\glu.h>	
#include "GrayScaleTable.h"

// helper variables/constans for the file open dialogue
static TCHAR szFilter[] = TEXT("Tiff files (*.tif*)\0*.tif*\0");
OPENFILENAME g_ofn = {sizeof(OPENFILENAME),NULL,NULL,szFilter,NULL,0,0,NULL,MAX_PATH,NULL,MAX_PATH,NULL,NULL,0,0,0,TEXT("tif\tiff"),0L,NULL,NULL};


HDC			ghDC=NULL;		// Private GDI Device Context
HGLRC		ghRC=NULL;		// Permanent Rendering Context
HWND		ghWnd=NULL;		// Holds Our Window Handle
HINSTANCE	ghInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool    mb[3];		        // Array Used To Store Mouse Button State
int		prevX = -1;         // Previous X coordinate from mouse
int		prevY = -1;			// Previous Y coordinate from mouse

GLsizei gWinWidth = 768;			// Window width
GLsizei gWinHeight = 768;         // Window height
GLuint gImageWidth = 2048;		// Image width
GLuint gImageHeight = 2048;		// Image height
GLuint gLutWidth = 4096;		// Image width
GLuint gImageTexId, gLut12BitTexId, gLut8BitTexId; //Tex ids for image and 2 lookup tables
bool gLut12BitEnabled = true; //by default, enable 12-bit LUT, user can change later at run-time if needed
float gLutScale = 1.0f;
float gLutOffset = 0.0f;
GLhandleARB gShaderProgram = NULL;

GLfloat x_start = 0.0;		// X starting location within half width window.
GLfloat x_end = 0.0;		// X ending location wthin half width window.
GLfloat y_start = 0.0;		// Y starting location within half width window.
GLfloat y_end = 0.0;		// Y ending location within half width window.

extern int readTiff(char *imageName, GLuint *pWidth, GLuint *pHeight, GLuint *pBpp, GLuint *pMinValue, GLuint *pMaxValue, GLuint *pNumValues, char** pixels) ;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
#ifdef _DEBUG
#define CHECK_GL(_x_)  (assert((_x_) != GL_NO_ERROR))
#else 
#define CHECK_GL(_x_)  _x_
#endif

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

const GLcharARB fragmentShaderSource[] = 
"#version 120                                   \n"
"#extension GL_EXT_gpu_shader4 : enable         \n" // Need gpu_shader 4 for unsigned int support in the shader
"uniform usampler2D image;                   \n" // Needs to be set by app to textureunit 0, Key here: unsigned sample !
"uniform sampler1D  lut;                   \n" // Needs to be set by app to textureunit 1, normalized float sampler.
"uniform vec2  textureSize;					\n" // Needs to be set by app size of texture.
"uniform bool  doBilinear = true;			\n" //Needs to be set by the app if bilinear filtering is reqd
"uniform float  lutOffset = 0.0;			\n" //Needs to be set by the app if windowing size needs to scale
"uniform float  lutScale = 1.0;			\n"  //Needs to be set by the app if offset or bias is needed

"                                               \n"
"void main(void)                                \n"
"{                                              \n"
"	vec2  TexCoord  = vec2(gl_TexCoord[0]);                 \n"
"   float GrayFloat;                            \n"
"	float normalizer = 1.0/4096.0;                \n" //lo 12 bits taken only  : adjust here to take highest bits into accout ( e.g. replace '/ 4096.0' with '/ 65536.0');
"	if (doBilinear) {                           \n"
"		vec2 f = fract(TexCoord.xy * textureSize );\n"
"		vec2 texelSize = 1.0/textureSize;	        \n"
"		float t00 = float(texture2D(image, TexCoord).a)*normalizer;		\n" // 
"		float t10 = float(texture2D(image, TexCoord + vec2( texelSize.x, 0.0 )).a)*normalizer;		\n"
"		float tA = mix(t00, t10, f.x );         \n"
"		float t01 = float(texture2D(image, TexCoord + vec2( 0.0, texelSize.y )).a)*normalizer;		\n"
"		float t11 = float(texture2D(image, TexCoord + vec2(texelSize.x, texelSize.y)).a)*normalizer ;\n"
"		float tB = mix( t01, t11, f.x );        \n"
"		GrayFloat = mix( tA, tB, f.y );			\n"
"	}											\n"
"	else	{										\n"
"		GrayFloat = float(texture2D(image, TexCoord).a)*normalizer;		\n" // 
"	}											\n"
"	vec4  Gray      = vec4(texture1D(lut, (GrayFloat-lutOffset)*lutScale)); \n"  // fetch right grayscale value out of table
"	gl_FragColor  = Gray.rgba;                               \n"  // write data to the framebuffer
"}";




void printInfoLog(GLhandleARB object)
{
	int maxLength = 0;
	glGetObjectParameterivARB(object, GL_OBJECT_INFO_LOG_LENGTH_ARB, &maxLength);

	char *infoLog = new char[maxLength];
	glGetInfoLogARB(object, maxLength, &maxLength, infoLog);

	printf("%s\n", infoLog);
}

bool generateGradientImage(GLuint width, GLuint height, GLuint *pMinValue, GLuint *pMaxValue, GLuint *pNumValues, unsigned short** pixels) {
#define MAX_VALUE 65536
	unsigned short value;
	unsigned int table[MAX_VALUE];
	unsigned short minv = MAX_VALUE-1;
	unsigned short maxv = 0;
	unsigned int count = 0;
	memset(table, 0, sizeof(table));       // zero out structure
	for (unsigned int y=0; y < height; y++) {
		for (unsigned int x=0; x < width; x++) 	{
			value = (x + y) / ( (2*width) / 4096);
			(*pixels)[(width*y)+ x] = value;
			table[value]++;
			if (value > maxv) {
				maxv = value;
			}
			if (value < minv) {
				minv = value;
			}
		}
	}
	// check for number of values used:
	for (int j = 0; j < MAX_VALUE; j++) {
		if (table[j]) {
			count++;
		}
	}
	*pMinValue = minv;
	*pMaxValue = maxv;
	*pNumValues = count;
	return true;
}


//
// InitGL - Initialize OpenGL state
//
bool oglInit(GLvoid)
{
	// Now we have a valid opengl context and could initialize needed extension stuff.
	glewInit();
	if (!glewIsSupported(
		"GL_VERSION_2_0 "
		"GL_ARB_vertex_program "
		"GL_ARB_fragment_program "
		"GL_EXT_texture_array "
		"GL_EXT_gpu_shader4 "
		"GL_NV_gpu_program4 "   // also initializes NV_fragment_program4 etc.
		))   {
			printf("Unable to load extension(s), this sample requires:\n  OpenGL version 2.0\n"
				"  GL_ARB_vertex_program\n  GL_ARB_fragment_program\n  GL_EXT_texture_array\n"
				"  GL_NV_gpu_program4\n Program will not show grayscale image...\n");
			return false;
	}

	gShaderProgram = glCreateProgramObjectARB();
	// Create  fragment shader object
	GLhandleARB object = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	// Add shader source code
//	GLint length = (GLint)strlen(fpsrc);
    const GLcharARB *fShade = (char *) &fragmentShaderSource;
	glShaderSourceARB(object, 1, &fShade, NULL);
	// Compile fragment shader object
	glCompileShaderARB(object);
	// Check if shader compiled
	GLint compiled = 0;
	glGetObjectParameterivARB(object, GL_OBJECT_COMPILE_STATUS_ARB, &compiled);
	if (!compiled) {
		printInfoLog(object);
		return false;
	}
	// Attach shader to program object
	glAttachObjectARB(gShaderProgram, object);
	// Delete shader object, no longer needed
	glDeleteObjectARB(object);
	// Link shader program.
	glLinkProgramARB(gShaderProgram);

	GLint linked = false;
	glGetObjectParameterivARB(gShaderProgram, GL_OBJECT_LINK_STATUS_ARB, &linked);
	if (!linked) {
		printInfoLog(gShaderProgram);
		return false;
	}


    unsigned short *pImageData = NULL;
	GLuint bitDepth, minValue, maxValue, numValues;
	//Prompt user to load a file
	// Open the standard file load dialog
	TCHAR szFileName[MAX_PATH], szTitleName[MAX_PATH];
	g_ofn.hwndOwner = ghWnd;
	g_ofn.lpstrFile = szFileName;
	g_ofn.lpstrFileTitle = szTitleName;
	g_ofn.lpstrFile[0] = '\0';
	g_ofn.nMaxFile = MAX_PATH;
	g_ofn.nFilterIndex = 1;
	g_ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	bool fileLoadedOK = false;
	// If this succeds, try to load the image into the texture
	if (GetOpenFileName(&g_ofn)) {
		readTiff(g_ofn.lpstrFile, &gImageWidth, &gImageHeight, &bitDepth, &minValue, &maxValue, &numValues,  (char**)&pImageData);
		if (bitDepth = 16) //all OK, lets set the flag to trye
			fileLoadedOK = true;			
	}
	if (!fileLoadedOK) {//load default grayscale gradient texture
		pImageData = (unsigned short*)malloc(gImageWidth*gImageHeight*sizeof(unsigned short) );
	    generateGradientImage(gImageWidth, gImageHeight, &minValue, &maxValue, &numValues,  &pImageData);	
	}

	//Download the image to a 2D texture in texunit #0 (integer extension used)
	glGenTextures(1, &gImageTexId);  
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gImageTexId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	float borderColor[4] = {0.0f,0.0f,0.0f,0.0f};
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA16UI_EXT, gImageWidth, gImageHeight, 0, GL_ALPHA_INTEGER_EXT , GL_UNSIGNED_SHORT, pImageData);
	free(pImageData);
	GL_GETERROR;

	//generate LUT for 12-bit graydata ie 4096 entries
	COLORREF* pLut12BitData  = cReateYasRGBTable12BitFast(); 
	//download LUT values into the 1D texture in texunit #1 
	glGenTextures(1, &gLut12BitTexId);  
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_1D, gLut12BitTexId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//No interpolation should be used for LUT
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage1D(GL_TEXTURE_1D, 0, 4, gLutWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, pLut12BitData );
	free(pLut12BitData); //this was malloced in the createYasRGBTable function

	//generate 8-bit LUT in case 256 unique values duplicated to 4096 entries
	COLORREF* pLut8BitData  = cReateYasRGBTable8Bit(); 
	//download LUT values into the 1D texture in texunit #1 
	glGenTextures(1, &gLut8BitTexId);  
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_1D, gLut8BitTexId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//No interpolation should be used for LUT
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage1D(GL_TEXTURE_1D, 0, 4, gLutWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, pLut8BitData);
	free(pLut8BitData); //this was malloced in the createYasRGBTable function

	//Initialize shader variables
	GLenum eVal;
	glUseProgramObjectARB(gShaderProgram);
	//Attach texunit#0 to Image and texunit#1 to LUT
	glUniform1iARB(glGetUniformLocationARB(gShaderProgram, "image"), 0);
	eVal = glGetError();
	glUniform1iARB(glGetUniformLocationARB(gShaderProgram, "lut"), 1);
	eVal = glGetError();
	//set the image dimensions
	glUniform2fARB(glGetUniformLocationARB(gShaderProgram, "textureSize"), (float) gImageWidth, (float) gImageHeight);

	glUseProgramObjectARB(0);
	//====== END Initialize Shader
	//Init OpenGl state
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	//glClearDepth(1.0f);									// Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	//glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	//glColor3f(1.0, 1.0, 1.0);							// White for texturing

	x_start = 0;
	x_end = (GLfloat)gImageWidth;
	y_start = 0;
	y_end = (GLfloat)gImageHeight;
	return TRUE;										// Initialization Went OK
}


GLvoid oglResize(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	// Update window width and height
	gWinWidth = width;
	gWinHeight = height;

	// Update viewport, projection and view
	glViewport(0, 0, gWinWidth, gWinHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, gWinWidth, 0, gWinHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//
// Redraw GL scene using current coordinates.
// At this point use the 16-bit and 8-bit FBO-attached textures where we previously rendered to
GLvoid oglDraw()
{
	GLfloat x0, y0, x1, y1;					// Draw coordinates

	GLenum eval = GL_NO_ERROR;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
	x0 = x_start;
	y0 = y_start;
	x1 = x_end;
	y1 = y_end;

	glViewport(0, 0, gWinWidth, gWinHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, gWinWidth, 0, gWinHeight);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();

	glUseProgramObjectARB(gShaderProgram);
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
	glUniform1iARB(glGetUniformLocationARB(gShaderProgram, "image"), 0);
	glUniform1iARB(glGetUniformLocationARB(gShaderProgram, "lut"), 1);
	glUniform1fARB(glGetUniformLocationARB(gShaderProgram, "lutOffset"), gLutOffset);
	glUniform1fARB(glGetUniformLocationARB(gShaderProgram, "lutScale"), gLutScale);
	GLenum eVal = glGetError();


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gImageTexId);
	glActiveTexture(GL_TEXTURE1);
	if (gLut12BitEnabled)
		glBindTexture(GL_TEXTURE_1D, gLut12BitTexId);
	else
		glBindTexture(GL_TEXTURE_1D, gLut8BitTexId);
		

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_1D);
	glBegin(GL_QUADS);
	//We are flipping the y since the tiff image will start from top left
	//while ogl starts from bottom right
	glTexCoord2f(0.0, 1.0); glVertex2f(x0, y0);
	glTexCoord2f(0.0, 0.0); glVertex2f(x0, y1);
	glTexCoord2f(1.0, 0.0); glVertex2f(x1, y1);
	glTexCoord2f(1.0, 1.0); glVertex2f(x1, y0);
	glEnd();
	GL_GETERROR;

    glDisable(GL_FRAGMENT_PROGRAM_ARB);
	glUseProgramObjectARB(0);
	eVal = glGetError();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_1D);
}

void oglCleanup() {
	glDeleteTextures(1,&gImageTexId);
	glDeleteTextures(1,&gLut12BitTexId);
	glDeleteTextures(1,&gLut8BitTexId);
    glDeleteProgram(gShaderProgram);
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
		x_end = x_start + (GLfloat)gImageWidth;	
		y_end = y_start + (GLfloat)gImageHeight;
	}

	prevX = x;
	prevY = y;

	fprintf(stderr, "x = %d  y = %d\n", x, y);
}

GLvoid KillGLWindow(GLvoid)								
{
    wglMakeCurrent(ghDC, ghRC);
	oglCleanup();									// Cleanup OpenGL state first while we still have the context
	//ErrHandler - for all the functions below
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(ghRC);							//Delete the OpenGL context
	ReleaseDC(ghWnd,ghDC);							//Release the DC we got from winfow
	DestroyWindow(ghWnd);							//destroy window, send WM_DESTROY?
	UnregisterClass("OpenGL",ghInstance);		
}


// Select the pixel format for a given device context


LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg) {									// Check For Windows Messages
	case WM_CLOSE:									// Did We Receive A Close Message?
		PostQuitMessage(0);							// Send A Quit Message
		return 0;									// Jump Back

	case WM_KEYDOWN:								// Is A Key Being Held Down?
		switch (wParam) { 
		case VK_ESCAPE:								// Escape = Quit
			PostQuitMessage (0);
			return 0;
		case 76:                                    // L = toggle LUT depth
			gLut12BitEnabled = !gLut12BitEnabled;
			if (gLut12BitEnabled)
				printf("12-bit LUT Enabled\n");
			else
				printf("8-bit LUT Enabled\n");
			break;
		case 82:                                    // R = Reset everything
			gLutScale = 1.0f;
			gLutOffset = 0.0f;
			gLut12BitEnabled = true;
			x_start = 0;
			x_end = (GLfloat)gImageWidth;
			y_start = 0;
			y_end = (GLfloat)gImageHeight;
			break;
        case VK_RIGHT:
            gLutOffset -= 0.01f;
			printf("New LUT offset %f\n",gLutOffset);
            break;
        case VK_LEFT:
            gLutOffset += 0.01f;
			printf("New LUT offset %f\n",gLutOffset);
            break;
        case VK_UP:
            gLutScale += 0.01f;
			printf("New LUT scale %f\n",gLutScale);
            break;
        case VK_DOWN:
            gLutScale -= 0.01f;
			printf("New LUT scale %f\n",gLutScale);
            break;
		}
		oglDraw();
		return 0;
	case WM_SIZE:									// Resize The OpenGL Window
		oglResize(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;									// Jump Back

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
	}
	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

bool CreateGLWindow(char* title, int width, int height, HINSTANCE instance)
{
	//Create Window
	static WNDCLASS	wc;			// Windows class structure
	static bool classRegistered = false;

	// Register Window style
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance 		= instance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);	
	// No need for background brush for OpenGL window
	wc.hbrBackground	= NULL;		
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= "OpenGL";

	if (!classRegistered) {
		if(RegisterClass(&wc) == 0)					// Register the window class
			return FALSE;							// not succesful
		classRegistered = true;						//only register 1st time,
	}

	// Create the main application window
	ghWnd = CreateWindow(
				"OpenGL",
				title,
				// OpenGL requires WS_CLIPCHILDREN and WS_CLIPSIBLINGS
				WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
				// Window position and size
				0, 0,
				width, height,
				NULL,
				NULL,
				instance,
				NULL);

	// If window was not created, quit
	if(ghWnd == NULL)
		return FALSE;

	ShowWindow(ghWnd,SW_SHOW);						// Show The Window
//	UpdateWindow(ghWnd);							//TODO what does this do?
	ghDC = GetDC(ghWnd);						// Store the device context
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),	// Size of this structure
		1,								// Version of this structure	
		PFD_DRAW_TO_WINDOW |			// Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |			// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,				// Double buffered mode
		PFD_TYPE_RGBA,					// RGBA Color mode
		32,								// Want 32 bit color 
		0,0,0,0,0,0,					// Not used to select mode
		0,0,							// Not used to select mode
		0,0,0,0,0,						// Not used to select mode
		16,								// Size of depth buffer
		0,								// Not used 
		0,								// Not used 
		0,	            				// Not used 
		0,								// Not used 
		0,0,0 };						// Not used 

	int nPixelFormat = ChoosePixelFormat(ghDC, &pfd); // Choose a pixel format that best matches that described in pfd
	SetPixelFormat(ghDC, nPixelFormat, &pfd);	// Set the pixel format for the device context
	ghRC = wglCreateContext(ghDC);				// Create the rendering context 
	wglMakeCurrent(ghDC, ghRC);					// Activate the context
	if (!oglInit()) 
		return FALSE;									
	return TRUE;									// Success
}



//TODO make this main so that we get console
int main(int argc, char** argv)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop
	ghInstance = GetModuleHandle(NULL);
	// Create Our OpenGL Window
	if (!CreateGLWindow("GrayScaleDemo", gWinWidth, gWinHeight, ghInstance))
	{
		return 0;									// Quit If Window Was Not Created
	}

	oglDraw();									// Initial Draw Of 3D Scene

	while(!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
			{
				done=TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		
		oglDraw();									// Draw The Scene
		SwapBuffers(ghDC);				            // Swap Buffers (Double Buffering)
	} // while (!done)

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}










