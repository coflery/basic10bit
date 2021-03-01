//
// globaldefs.h
//
// All the function handles and error handling functions are in here
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#ifndef _AFFGLOBALDEFS_H_
#define _AFFGLOBALDEFS_H_
#include <windows.h>
#include <gl\gl.h>
#include <wglext.h>
#include <glext.h>

// WGL_NV_gpu_affinity
extern PFNWGLENUMGPUSNVPROC                 wglEnumGpusNV;
extern PFNWGLENUMGPUDEVICESNVPROC           wglEnumGpuDevicesNV;
extern PFNWGLCREATEAFFINITYDCNVPROC         wglCreateAffinityDCNV;
extern PFNWGLDELETEDCNVPROC                 wglDeleteDCNV;
extern PFNWGLENUMGPUSFROMAFFINITYDCNVPROC   wglEnumGpusFromAffinityDCNV;

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
	}                                                               \
}

#define ERR_MSG(STR)                                            \
{																\
	printf("\nERROR - "STR"\n");                                \
    exit(0);													\
}

#define MAX_NUM_GPUS 4
void GLInfo();

#endif