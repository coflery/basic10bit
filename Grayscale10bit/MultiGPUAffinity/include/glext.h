#ifndef __glext_h_
#define __glext_h_

/*
** Copyright 1998-2002, NVIDIA Corporation.
** All Rights Reserved.
** 
** THE INFORMATION CONTAINED HEREIN IS PROPRIETARY AND CONFIDENTIAL TO
** NVIDIA, CORPORATION.  USE, REPRODUCTION OR DISCLOSURE TO ANY THIRD PARTY
** IS SUBJECT TO WRITTEN PRE-APPROVAL BY NVIDIA, CORPORATION.
** 
** 
** Copyright 1992-1999, Silicon Graphics, Inc.
** All Rights Reserved.
** 
** Portions of this file are UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon
** Graphics, Inc.; the contents of this file may not be disclosed to third
** parties, copied or duplicated in any form, in whole or in part, without
** the prior written permission of Silicon Graphics, Inc.
** 
** RESTRICTED RIGHTS LEGEND:
** Use, duplication or disclosure by the Government is subject to
** restrictions as set forth in subdivision (c)(1)(ii) of the Rights in
** Technical Data and Computer Software clause at DFARS 252.227-7013,
** and/or in similar or successor clauses in the FAR, DOD or NASA FAR
** Supplement.  Unpublished - rights reserved under the Copyright Laws of
** the United States.
*/

#ifndef GLAPIENTRY
# ifdef _WIN32
#  if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)  /* Mimic <windef.h> */
#   define GLAPIENTRY __stdcall
#  else
#   define GLAPIENTRY
#  endif
# else
#  define GLAPIENTRY
# endif
#endif

#ifndef GLAPI
# define GLAPI extern
#endif

#ifndef GLAPIENTRYP
# define GLAPIENTRYP GLAPIENTRY *
#endif

/*************************************************************/

#ifndef GL_TYPEDEFS_1_5
#define GL_TYPEDEFS_1_5
#if defined(_WIN64)
    typedef __int64 GLintptr;
    typedef __int64 GLsizeiptr;
#elif defined(__x86_64__)
    typedef long int GLintptr;
    typedef long int GLsizeiptr;
#else
    typedef int GLintptr;
    typedef int GLsizeiptr;
#endif
#endif

#ifndef GL_TYPEDEFS_2_0
# define GL_TYPEDEFS_2_0
    typedef char GLchar;
#endif

typedef unsigned short GLhalf;
typedef unsigned int GLhandleARB;
typedef char GLcharARB;
#if defined(_WIN64)
    typedef __int64 GLintptrARB;
    typedef __int64 GLsizeiptrARB;
#elif defined(__x86_64__)
    typedef long int GLintptrARB;
    typedef long int GLsizeiptrARB;
#else
    typedef int GLintptrARB;
    typedef int GLsizeiptrARB;
#endif

typedef signed long GLint64EXT;
typedef unsigned long GLuint64EXT;


#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GLAPI void GLAPIENTRY glBlendEquation (GLenum mode);
GLAPI void GLAPIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
GLAPI void GLAPIENTRY glColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
GLAPI void GLAPIENTRY glColorTableParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glColorTableParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glCopyColorTable (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glGetColorTable (GLenum target, GLenum format, GLenum type, GLvoid *table);
GLAPI void GLAPIENTRY glGetColorTableParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetColorTableParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (GLAPIENTRYP PFNGLCOPYCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, GLvoid *table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorSubTable (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
GLAPI void GLAPIENTRY glCopyColorSubTable (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glConvolutionFilter1D (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
GLAPI void GLAPIENTRY glConvolutionFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
GLAPI void GLAPIENTRY glConvolutionParameterf (GLenum target, GLenum pname, GLfloat params);
GLAPI void GLAPIENTRY glConvolutionParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glConvolutionParameteri (GLenum target, GLenum pname, GLint params);
GLAPI void GLAPIENTRY glConvolutionParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glCopyConvolutionFilter1D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyConvolutionFilter2D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetConvolutionFilter (GLenum target, GLenum format, GLenum type, GLvoid *image);
GLAPI void GLAPIENTRY glGetConvolutionParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetConvolutionParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetSeparableFilter (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
GLAPI void GLAPIENTRY glSeparableFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
GLAPI void GLAPIENTRY glGetHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GLAPI void GLAPIENTRY glGetHistogramParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetHistogramParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GLAPI void GLAPIENTRY glGetMinmaxParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetMinmaxParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glHistogram (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GLAPI void GLAPIENTRY glMinmax (GLenum target, GLenum internalformat, GLboolean sink);
GLAPI void GLAPIENTRY glResetHistogram (GLenum target);
GLAPI void GLAPIENTRY glResetMinmax (GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOPYCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERIPROC) (GLenum target, GLenum pname, GLint params);
typedef void (GLAPIENTRYP PFNGLCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (GLAPIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid *image);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
typedef void (GLAPIENTRYP PFNGLSEPARABLEFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETHISTOGRAMPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETMINMAXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLHISTOGRAMPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRYP PFNGLMINMAXPROC) (GLenum target, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRYP PFNGLRESETHISTOGRAMPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLRESETMINMAXPROC) (GLenum target);
#endif


#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveTexture (GLenum texture);
GLAPI void GLAPIENTRY glClientActiveTexture (GLenum texture);
GLAPI void GLAPIENTRY glMultiTexCoord1d (GLenum target, GLdouble s);
GLAPI void GLAPIENTRY glMultiTexCoord1dv (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord1f (GLenum target, GLfloat s);
GLAPI void GLAPIENTRY glMultiTexCoord1fv (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord1i (GLenum target, GLint s);
GLAPI void GLAPIENTRY glMultiTexCoord1iv (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord1s (GLenum target, GLshort s);
GLAPI void GLAPIENTRY glMultiTexCoord1sv (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord2d (GLenum target, GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glMultiTexCoord2dv (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord2f (GLenum target, GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glMultiTexCoord2fv (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord2i (GLenum target, GLint s, GLint t);
GLAPI void GLAPIENTRY glMultiTexCoord2iv (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord2s (GLenum target, GLshort s, GLshort t);
GLAPI void GLAPIENTRY glMultiTexCoord2sv (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord3d (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glMultiTexCoord3dv (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord3f (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glMultiTexCoord3fv (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord3i (GLenum target, GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glMultiTexCoord3iv (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord3s (GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glMultiTexCoord3sv (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord4d (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glMultiTexCoord4dv (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glMultiTexCoord4fv (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord4i (GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glMultiTexCoord4iv (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord4s (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glMultiTexCoord4sv (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glLoadTransposeMatrixf (const GLfloat *m);
GLAPI void GLAPIENTRY glLoadTransposeMatrixd (const GLdouble *m);
GLAPI void GLAPIENTRY glMultTransposeMatrixf (const GLfloat *m);
GLAPI void GLAPIENTRY glMultTransposeMatrixd (const GLdouble *m);
GLAPI void GLAPIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glGetCompressedTexImage (GLenum target, GLint lod, GLvoid *img);
GLAPI void GLAPIENTRY glSampleCoverage (GLclampf value, GLboolean invert);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (GLAPIENTRYP PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble *m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble *m);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLvoid *img);
typedef void (GLAPIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);
#endif


#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterf (GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glPointParameteri (GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPointParameteriv (GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glWindowPos2d (GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glWindowPos2f (GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glWindowPos2i (GLint x, GLint y);
GLAPI void GLAPIENTRY glWindowPos2s (GLshort x, GLshort y);
GLAPI void GLAPIENTRY glWindowPos2dv (const GLdouble *p);
GLAPI void GLAPIENTRY glWindowPos2fv (const GLfloat *p);
GLAPI void GLAPIENTRY glWindowPos2iv (const GLint *p);
GLAPI void GLAPIENTRY glWindowPos2sv (const GLshort *p);
GLAPI void GLAPIENTRY glWindowPos3d (GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glWindowPos3f (GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glWindowPos3i (GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glWindowPos3s (GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glWindowPos3dv (const GLdouble *p);
GLAPI void GLAPIENTRY glWindowPos3fv (const GLfloat *p);
GLAPI void GLAPIENTRY glWindowPos3iv (const GLint *p);
GLAPI void GLAPIENTRY glWindowPos3sv (const GLshort *p);
GLAPI void GLAPIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void GLAPIENTRY glFogCoordd (GLdouble fog);
GLAPI void GLAPIENTRY glFogCoorddv (const GLdouble *fog);
GLAPI void GLAPIENTRY glFogCoordf (GLfloat fog);
GLAPI void GLAPIENTRY glFogCoordfv (const GLfloat *fog);
GLAPI void GLAPIENTRY glFogCoordPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
GLAPI void GLAPIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
GLAPI void GLAPIENTRY glSecondaryColor3b (GLbyte red, GLbyte green, GLbyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3bv (const GLbyte *v);
GLAPI void GLAPIENTRY glSecondaryColor3d (GLdouble red, GLdouble green, GLdouble blue);
GLAPI void GLAPIENTRY glSecondaryColor3dv (const GLdouble *v);
GLAPI void GLAPIENTRY glSecondaryColor3f (GLfloat red, GLfloat green, GLfloat blue);
GLAPI void GLAPIENTRY glSecondaryColor3fv (const GLfloat *v);
GLAPI void GLAPIENTRY glSecondaryColor3i (GLint red, GLint green, GLint blue);
GLAPI void GLAPIENTRY glSecondaryColor3iv (const GLint *v);
GLAPI void GLAPIENTRY glSecondaryColor3s (GLshort red, GLshort green, GLshort blue);
GLAPI void GLAPIENTRY glSecondaryColor3sv (const GLshort *v);
GLAPI void GLAPIENTRY glSecondaryColor3ub (GLubyte red, GLubyte green, GLubyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3ubv (const GLubyte *v);
GLAPI void GLAPIENTRY glSecondaryColor3ui (GLuint red, GLuint green, GLuint blue);
GLAPI void GLAPIENTRY glSecondaryColor3uiv (const GLuint *v);
GLAPI void GLAPIENTRY glSecondaryColor3us (GLushort red, GLushort green, GLushort blue);
GLAPI void GLAPIENTRY glSecondaryColor3usv (const GLushort *v);
GLAPI void GLAPIENTRY glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DVPROC) (const GLdouble *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FVPROC) (const GLfloat *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IVPROC) (const GLint *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SVPROC) (const GLshort *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DVPROC) (const GLdouble *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FVPROC) (const GLfloat *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IVPROC) (const GLint *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SVPROC) (const GLshort *p);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDPROC) (GLdouble fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDVPROC) (const GLdouble *fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFPROC) (GLfloat fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFVPROC) (const GLfloat *fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IVPROC) (const GLint *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USVPROC) (const GLushort *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#endif


#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glArrayElementEXT (GLint i);
GLAPI void GLAPIENTRY glColorPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GLAPI void GLAPIENTRY glEdgeFlagPointerEXT (GLsizei stride, GLsizei count, const GLboolean *pointer);
GLAPI void GLAPIENTRY glGetPointervEXT (GLenum pname, GLvoid* *params);
GLAPI void GLAPIENTRY glIndexPointerEXT (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GLAPI void GLAPIENTRY glNormalPointerEXT (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GLAPI void GLAPIENTRY glTexCoordPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GLAPI void GLAPIENTRY glVertexPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GLAPI void GLAPIENTRY glDrawArraysEXT (GLenum mode, GLint first, GLsizei count);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLARRAYELEMENTEXTPROC) (GLint i);
typedef void (GLAPIENTRYP PFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean *pointer);
typedef void (GLAPIENTRYP PFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid* *params);
typedef void (GLAPIENTRYP PFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
#endif


#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glAreTexturesResidentEXT (GLsizei n, const GLuint *textures, GLboolean *residences);
GLAPI void GLAPIENTRY glBindTextureEXT (GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glDeleteTexturesEXT (GLsizei n, const GLuint *textures);
GLAPI void GLAPIENTRY glGenTexturesEXT (GLsizei n, GLuint *textures);
GLAPI GLboolean GLAPIENTRY glIsTextureEXT (GLuint texture);
GLAPI void GLAPIENTRY glPrioritizeTexturesEXT (GLsizei n, const GLuint *textures, const GLclampf *priorities);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLARETEXTURESRESIDENTEXTPROC) (GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (GLAPIENTRYP PFNGLBINDTEXTUREEXTPROC) (GLenum target, GLuint texture);
typedef void (GLAPIENTRYP PFNGLDELETETEXTURESEXTPROC) (GLsizei n, const GLuint *textures);
typedef void (GLAPIENTRYP PFNGLGENTEXTURESEXTPROC) (GLsizei n, GLuint *textures);
typedef GLboolean (GLAPIENTRYP PFNGLISTEXTUREEXTPROC) (GLuint texture);
typedef void (GLAPIENTRYP PFNGLPRIORITIZETEXTURESEXTPROC) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
#endif


#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLockArraysEXT (GLint first, GLsizei count);
GLAPI void GLAPIENTRY glUnlockArraysEXT (void);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOCKARRAYSEXTPROC) (GLint first, GLsizei count);
typedef void (GLAPIENTRYP PFNGLUNLOCKARRAYSEXTPROC) (void);
#endif


#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveTextureARB (GLenum texture);
GLAPI void GLAPIENTRY glClientActiveTextureARB (GLenum texture);
GLAPI void GLAPIENTRY glMultiTexCoord1dARB (GLenum target, GLdouble s);
GLAPI void GLAPIENTRY glMultiTexCoord1dvARB (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord1fARB (GLenum target, GLfloat s);
GLAPI void GLAPIENTRY glMultiTexCoord1fvARB (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord1iARB (GLenum target, GLint s);
GLAPI void GLAPIENTRY glMultiTexCoord1ivARB (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord1sARB (GLenum target, GLshort s);
GLAPI void GLAPIENTRY glMultiTexCoord1svARB (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord2dARB (GLenum target, GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glMultiTexCoord2dvARB (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord2fARB (GLenum target, GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glMultiTexCoord2fvARB (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord2iARB (GLenum target, GLint s, GLint t);
GLAPI void GLAPIENTRY glMultiTexCoord2ivARB (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord2sARB (GLenum target, GLshort s, GLshort t);
GLAPI void GLAPIENTRY glMultiTexCoord2svARB (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord3dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glMultiTexCoord3dvARB (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord3fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glMultiTexCoord3fvARB (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord3iARB (GLenum target, GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glMultiTexCoord3ivARB (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord3sARB (GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glMultiTexCoord3svARB (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord4dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glMultiTexCoord4dvARB (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord4fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glMultiTexCoord4fvARB (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord4iARB (GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glMultiTexCoord4ivARB (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord4sARB (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glMultiTexCoord4svARB (GLenum target, const GLshort *v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (GLAPIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort *v);
#endif


#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glWindowPos2dARB (GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glWindowPos2fARB (GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glWindowPos2iARB (GLint x, GLint y);
GLAPI void GLAPIENTRY glWindowPos2sARB (GLshort x, GLshort y);
GLAPI void GLAPIENTRY glWindowPos2dvARB (const GLdouble *p);
GLAPI void GLAPIENTRY glWindowPos2fvARB (const GLfloat *p);
GLAPI void GLAPIENTRY glWindowPos2ivARB (const GLint *p);
GLAPI void GLAPIENTRY glWindowPos2svARB (const GLshort *p);
GLAPI void GLAPIENTRY glWindowPos3dARB (GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glWindowPos3fARB (GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glWindowPos3iARB (GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glWindowPos3sARB (GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glWindowPos3dvARB (const GLdouble *p);
GLAPI void GLAPIENTRY glWindowPos3fvARB (const GLfloat *p);
GLAPI void GLAPIENTRY glWindowPos3ivARB (const GLint *p);
GLAPI void GLAPIENTRY glWindowPos3svARB (const GLshort *p);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DARBPROC) (GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FARBPROC) (GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IARBPROC) (GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SARBPROC) (GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2DVARBPROC) (const GLdouble *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2FVARBPROC) (const GLfloat *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2IVARBPROC) (const GLint *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS2SVARBPROC) (const GLshort *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DARBPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FARBPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IARBPROC) (GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SARBPROC) (GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3DVARBPROC) (const GLdouble *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3FVARBPROC) (const GLfloat *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3IVARBPROC) (const GLint *p);
typedef void (GLAPIENTRYP PFNGLWINDOWPOS3SVARBPROC) (const GLshort *p);
#endif


#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexImage3DEXT (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glCopyTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXIMAGE3DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GLAPIENTRYP PFNGLTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GLAPIENTRYP PFNGLCOPYTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendColorEXT (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDCOLOREXTPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#endif


#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationEXT (GLenum mode);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONEXTPROC) (GLenum mode);
#endif


#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterfEXT (GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfvEXT (GLenum pname, const GLfloat *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFEXTPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVEXTPROC) (GLenum pname, const GLfloat *params);
#endif


#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorSubTableEXT (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *table);
GLAPI void GLAPIENTRY glColorTableEXT (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
GLAPI void GLAPIENTRY glGetColorTableEXT (GLenum target, GLenum format, GLenum type, GLvoid *table);
GLAPI void GLAPIENTRY glGetColorTableParameterfvEXT (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetColorTableParameterivEXT (GLenum target, GLenum pname, GLint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *table);
typedef void (GLAPIENTRYP PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEEXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid *table);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint *params);
#endif


#ifndef GL_WIN_swap_hint
#define GL_WIN_swap_hint 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glAddSwapHintRectWIN (GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLADDSWAPHINTRECTWINPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_SGIS_multitexture
#define GL_SGIS_multitexture 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiTexCoord1dSGIS (GLenum target, GLdouble s);
GLAPI void GLAPIENTRY glMultiTexCoord1dvSGIS (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord1fSGIS (GLenum target, GLfloat s);
GLAPI void GLAPIENTRY glMultiTexCoord1fvSGIS (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord1iSGIS (GLenum target, GLint s);
GLAPI void GLAPIENTRY glMultiTexCoord1ivSGIS (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord1sSGIS (GLenum target, GLshort s);
GLAPI void GLAPIENTRY glMultiTexCoord1svSGIS (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord2dSGIS (GLenum target, GLdouble s, GLdouble t);
GLAPI void GLAPIENTRY glMultiTexCoord2dvSGIS (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord2fSGIS (GLenum target, GLfloat s, GLfloat t);
GLAPI void GLAPIENTRY glMultiTexCoord2fvSGIS (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord2iSGIS (GLenum target, GLint s, GLint t);
GLAPI void GLAPIENTRY glMultiTexCoord2ivSGIS (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord2sSGIS (GLenum target, GLshort s, GLshort t);
GLAPI void GLAPIENTRY glMultiTexCoord2svSGIS (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord3dSGIS (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void GLAPIENTRY glMultiTexCoord3dvSGIS (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord3fSGIS (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void GLAPIENTRY glMultiTexCoord3fvSGIS (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord3iSGIS (GLenum target, GLint s, GLint t, GLint r);
GLAPI void GLAPIENTRY glMultiTexCoord3ivSGIS (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord3sSGIS (GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void GLAPIENTRY glMultiTexCoord3svSGIS (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoord4dSGIS (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void GLAPIENTRY glMultiTexCoord4dvSGIS (GLenum target, const GLdouble *v);
GLAPI void GLAPIENTRY glMultiTexCoord4fSGIS (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void GLAPIENTRY glMultiTexCoord4fvSGIS (GLenum target, const GLfloat *v);
GLAPI void GLAPIENTRY glMultiTexCoord4iSGIS (GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void GLAPIENTRY glMultiTexCoord4ivSGIS (GLenum target, const GLint *v);
GLAPI void GLAPIENTRY glMultiTexCoord4sSGIS (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void GLAPIENTRY glMultiTexCoord4svSGIS (GLenum target, const GLshort *v);
GLAPI void GLAPIENTRY glMultiTexCoordPointerSGIS (GLenum target, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glSelectTextureSGIS (GLenum target);
GLAPI void GLAPIENTRY glSelectTextureCoordSetSGIS (GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DSGISPROC) (GLenum target, GLdouble s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1DVSGISPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FSGISPROC) (GLenum target, GLfloat s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1FVSGISPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1ISGISPROC) (GLenum target, GLint s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1IVSGISPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SSGISPROC) (GLenum target, GLshort s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1SVSGISPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DSGISPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2DVSGISPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FSGISPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2FVSGISPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2ISGISPROC) (GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2IVSGISPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SSGISPROC) (GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2SVSGISPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DSGISPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3DVSGISPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FSGISPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3FVSGISPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3ISGISPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3IVSGISPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SSGISPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3SVSGISPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DSGISPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4DVSGISPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FSGISPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4FVSGISPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4ISGISPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4IVSGISPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SSGISPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4SVSGISPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORDPOINTERSGISPROC) (GLenum target, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLSELECTTEXTURESGISPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLSELECTTEXTURECOORDSETSGISPROC) (GLenum target);
#endif


#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFogCoorddEXT (GLdouble fog);
GLAPI void GLAPIENTRY glFogCoorddvEXT (const GLdouble *fog);
GLAPI void GLAPIENTRY glFogCoordfEXT (GLfloat fog);
GLAPI void GLAPIENTRY glFogCoordfvEXT (const GLfloat *fog);
GLAPI void GLAPIENTRY glFogCoordPointerEXT (GLenum type, GLsizei stride, const GLvoid *pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFOGCOORDDEXTPROC) (GLdouble fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDDVEXTPROC) (const GLdouble *fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFEXTPROC) (GLfloat fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDFVEXTPROC) (const GLfloat *fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);
#endif


#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSecondaryColor3bEXT (GLbyte red, GLbyte green, GLbyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3bvEXT (const GLbyte *v);
GLAPI void GLAPIENTRY glSecondaryColor3dEXT (GLdouble red, GLdouble green, GLdouble blue);
GLAPI void GLAPIENTRY glSecondaryColor3dvEXT (const GLdouble *v);
GLAPI void GLAPIENTRY glSecondaryColor3fEXT (GLfloat red, GLfloat green, GLfloat blue);
GLAPI void GLAPIENTRY glSecondaryColor3fvEXT (const GLfloat *v);
GLAPI void GLAPIENTRY glSecondaryColor3iEXT (GLint red, GLint green, GLint blue);
GLAPI void GLAPIENTRY glSecondaryColor3ivEXT (const GLint *v);
GLAPI void GLAPIENTRY glSecondaryColor3sEXT (GLshort red, GLshort green, GLshort blue);
GLAPI void GLAPIENTRY glSecondaryColor3svEXT (const GLshort *v);
GLAPI void GLAPIENTRY glSecondaryColor3ubEXT (GLubyte red, GLubyte green, GLubyte blue);
GLAPI void GLAPIENTRY glSecondaryColor3ubvEXT (const GLubyte *v);
GLAPI void GLAPIENTRY glSecondaryColor3uiEXT (GLuint red, GLuint green, GLuint blue);
GLAPI void GLAPIENTRY glSecondaryColor3uivEXT (const GLuint *v);
GLAPI void GLAPIENTRY glSecondaryColor3usEXT (GLushort red, GLushort green, GLushort blue);
GLAPI void GLAPIENTRY glSecondaryColor3usvEXT (const GLushort *v);
GLAPI void GLAPIENTRY glSecondaryColorPointerEXT (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BEXTPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3BVEXTPROC) (const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DEXTPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3DVEXTPROC) (const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FEXTPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3FVEXTPROC) (const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IEXTPROC) (GLint red, GLint green, GLint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3IVEXTPROC) (const GLint *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SEXTPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3SVEXTPROC) (const GLshort *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBEXTPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UBVEXTPROC) (const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIEXTPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3UIVEXTPROC) (const GLuint *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USEXTPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3USVEXTPROC) (const GLushort *v);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#endif


#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFlushVertexArrayRangeNV (void);
GLAPI void GLAPIENTRY glVertexArrayRangeNV (GLsizei size, const GLvoid *pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFLUSHVERTEXARRAYRANGENVPROC) (void);
typedef void (GLAPIENTRYP PFNGLVERTEXARRAYRANGENVPROC) (GLsizei size, const GLvoid *pointer);
#endif


#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCombinerParameterfvNV (GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glCombinerParameterfNV (GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glCombinerParameterivNV (GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glCombinerParameteriNV (GLenum pname, GLint param);
GLAPI void GLAPIENTRY glCombinerInputNV (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI void GLAPIENTRY glCombinerOutputNV (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
GLAPI void GLAPIENTRY glFinalCombinerInputNV (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GLAPI void GLAPIENTRY glGetCombinerInputParameterfvNV (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetCombinerInputParameterivNV (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetCombinerOutputParameterfvNV (GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetCombinerOutputParameterivNV (GLenum stage, GLenum portion, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetFinalCombinerInputParameterfvNV (GLenum variable, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetFinalCombinerInputParameterivNV (GLenum variable, GLenum pname, GLint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERFVNVPROC) (GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERFNVPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERIVNVPROC) (GLenum pname, const GLint *params);
typedef void (GLAPIENTRYP PFNGLCOMBINERPARAMETERINVPROC) (GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLCOMBINERINPUTNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRYP PFNGLCOMBINEROUTPUTNVPROC) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (GLAPIENTRYP PFNGLFINALCOMBINERINPUTNVPROC) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint *params);
#endif


#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLoadTransposeMatrixfARB (const GLfloat *m);
GLAPI void GLAPIENTRY glLoadTransposeMatrixdARB (const GLdouble *m);
GLAPI void GLAPIENTRY glMultTransposeMatrixfARB (const GLfloat *m);
GLAPI void GLAPIENTRY glMultTransposeMatrixdARB (const GLdouble *m);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXFARBPROC) (const GLfloat *m);
typedef void (GLAPIENTRYP PFNGLLOADTRANSPOSEMATRIXDARBPROC) (const GLdouble *m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXFARBPROC) (const GLfloat *m);
typedef void (GLAPIENTRYP PFNGLMULTTRANSPOSEMATRIXDARBPROC) (const GLdouble *m);
#endif


#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCompressedTexImage3DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexImage2DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexImage1DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage3DARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage2DARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glCompressedTexSubImage1DARB (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
GLAPI void GLAPIENTRY glGetCompressedTexImageARB (GLenum target, GLint lod, GLvoid *img);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLvoid *img);
#endif


#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glAreProgramsResidentNV (GLsizei n, const GLuint *programs, GLboolean *residences);
GLAPI void GLAPIENTRY glBindProgramNV (GLenum target, GLuint id);
GLAPI void GLAPIENTRY glDeleteProgramsNV (GLsizei n, const GLuint *programs);
GLAPI void GLAPIENTRY glExecuteProgramNV (GLenum target, GLuint id, const GLfloat *params);
GLAPI void GLAPIENTRY glGenProgramsNV (GLsizei n, GLuint *programs);
GLAPI void GLAPIENTRY glGetProgramParameterdvNV (GLenum target, GLuint index, GLenum pname, GLdouble *params);
GLAPI void GLAPIENTRY glGetProgramParameterfvNV (GLenum target, GLuint index, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetProgramivNV (GLuint id, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetProgramStringNV (GLuint id, GLenum pname, GLubyte *program);
GLAPI void GLAPIENTRY glGetTrackMatrixivNV (GLenum target, GLuint address, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetVertexAttribdvNV (GLuint index, GLenum pname, GLdouble *params);
GLAPI void GLAPIENTRY glGetVertexAttribfvNV (GLuint index, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetVertexAttribivNV (GLuint index, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetVertexAttribPointervNV (GLuint index, GLenum pname, GLvoid* *pointer);
GLAPI GLboolean GLAPIENTRY glIsProgramNV (GLuint id);
GLAPI void GLAPIENTRY glLoadProgramNV (GLenum target, GLuint id, GLsizei len, const GLubyte *program);
GLAPI void GLAPIENTRY glProgramParameter4dNV (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramParameter4dvNV (GLenum target, GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glProgramParameter4fNV (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramParameter4fvNV (GLenum target, GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glProgramParameters4dvNV (GLenum target, GLuint index, GLsizei count, const GLdouble *v);
GLAPI void GLAPIENTRY glProgramParameters4fvNV (GLenum target, GLuint index, GLsizei count, const GLfloat *v);
GLAPI void GLAPIENTRY glRequestResidentProgramsNV (GLsizei n, const GLuint *programs);
GLAPI void GLAPIENTRY glTrackMatrixNV (GLenum target, GLuint address, GLenum matrix, GLenum transform);
GLAPI void GLAPIENTRY glVertexAttribPointerNV (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glVertexAttrib1dNV (GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dvNV (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib1fNV (GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fvNV (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib1sNV (GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1svNV (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib2dNV (GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dvNV (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib2fNV (GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fvNV (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib2sNV (GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2svNV (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib3dNV (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dvNV (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib3fNV (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fvNV (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib3sNV (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3svNV (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4dNV (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dvNV (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib4fNV (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fvNV (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib4sNV (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4svNV (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4ubNV (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4ubvNV (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttribs1dvNV (GLuint index, GLsizei count, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttribs1fvNV (GLuint index, GLsizei count, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttribs1svNV (GLuint index, GLsizei count, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttribs2dvNV (GLuint index, GLsizei count, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttribs2fvNV (GLuint index, GLsizei count, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttribs2svNV (GLuint index, GLsizei count, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttribs3dvNV (GLuint index, GLsizei count, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttribs3fvNV (GLuint index, GLsizei count, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttribs3svNV (GLuint index, GLsizei count, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttribs4dvNV (GLuint index, GLsizei count, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttribs4fvNV (GLuint index, GLsizei count, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttribs4svNV (GLuint index, GLsizei count, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttribs4ubvNV (GLuint index, GLsizei count, const GLubyte *v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLAREPROGRAMSRESIDENTNVPROC) (GLsizei n, const GLuint *programs, GLboolean *residences);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMNVPROC) (GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMSNVPROC) (GLsizei n, const GLuint *programs);
typedef void (GLAPIENTRYP PFNGLEXECUTEPROGRAMNVPROC) (GLenum target, GLuint id, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMSNVPROC) (GLsizei n, GLuint *programs);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPARAMETERDVNVPROC) (GLenum target, GLuint index, GLenum pname, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVNVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSTRINGNVPROC) (GLuint id, GLenum pname, GLubyte *program);
typedef void (GLAPIENTRYP PFNGLGETTRACKMATRIXIVNVPROC) (GLenum target, GLuint address, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVNVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVNVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVNVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVNVPROC) (GLuint index, GLenum pname, GLvoid* *pointer);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMNVPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLLOADPROGRAMNVPROC) (GLenum target, GLuint id, GLsizei len, const GLubyte *program);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4DNVPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4DVNVPROC) (GLenum target, GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4FNVPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETER4FVNVPROC) (GLenum target, GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERS4DVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERS4FVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLREQUESTRESIDENTPROGRAMSNVPROC) (GLsizei n, const GLuint *programs);
typedef void (GLAPIENTRYP PFNGLTRACKMATRIXNVPROC) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERNVPROC) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DNVPROC) (GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVNVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FNVPROC) (GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVNVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SNVPROC) (GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVNVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DNVPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVNVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FNVPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVNVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SNVPROC) (GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVNVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVNVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVNVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVNVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVNVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVNVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVNVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBNVPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVNVPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1DVNVPROC) (GLuint index, GLsizei count, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1FVNVPROC) (GLuint index, GLsizei count, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1SVNVPROC) (GLuint index, GLsizei count, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2DVNVPROC) (GLuint index, GLsizei count, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2FVNVPROC) (GLuint index, GLsizei count, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2SVNVPROC) (GLuint index, GLsizei count, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3DVNVPROC) (GLuint index, GLsizei count, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3FVNVPROC) (GLuint index, GLsizei count, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3SVNVPROC) (GLuint index, GLsizei count, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4DVNVPROC) (GLuint index, GLsizei count, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4FVNVPROC) (GLuint index, GLsizei count, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4SVNVPROC) (GLuint index, GLsizei count, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4UBVNVPROC) (GLuint index, GLsizei count, const GLubyte *v);
#endif


#ifndef GL_NV_fence
#define GL_NV_fence 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDeleteFencesNV (GLsizei n, const GLuint *fences);
GLAPI void GLAPIENTRY glGenFencesNV (GLsizei n, GLuint *fences);
GLAPI GLboolean GLAPIENTRY glIsFenceNV (GLuint fence);
GLAPI GLboolean GLAPIENTRY glTestFenceNV (GLuint fence);
GLAPI void GLAPIENTRY glGetFenceivNV (GLuint fence, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glFinishFenceNV (GLuint fence);
GLAPI void GLAPIENTRY glSetFenceNV (GLuint fence, GLenum condition);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDELETEFENCESNVPROC) (GLsizei n, const GLuint *fences);
typedef void (GLAPIENTRYP PFNGLGENFENCESNVPROC) (GLsizei n, GLuint *fences);
typedef GLboolean (GLAPIENTRYP PFNGLISFENCENVPROC) (GLuint fence);
typedef GLboolean (GLAPIENTRYP PFNGLTESTFENCENVPROC) (GLuint fence);
typedef void (GLAPIENTRYP PFNGLGETFENCEIVNVPROC) (GLuint fence, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLFINISHFENCENVPROC) (GLuint fence);
typedef void (GLAPIENTRYP PFNGLSETFENCENVPROC) (GLuint fence, GLenum condition);
#endif


#ifndef GL_NV_draw_mesh
#define GL_NV_draw_mesh 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawMeshNV (GLenum mode, GLsizei count, GLenum type, GLsizei stride, const GLvoid *indicesTexCoord, const GLvoid *indicesNormal, const GLvoid *indicesVertex);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWMESHNVPROC) (GLenum mode, GLsizei count, GLenum type, GLsizei stride, const GLvoid *indicesTexCoord, const GLvoid *indicesNormal, const GLvoid *indicesVertex);
#endif


#ifndef GL_Autodesk_valid_back_buffer_hint
#define GL_Autodesk_valid_back_buffer_hint 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glWindowBackBufferHintAutodesk (void);
GLAPI GLboolean GLAPIENTRY glValidBackBufferHintAutodesk (GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLWINDOWBACKBUFFERHINTAUTODESKPROC) (void);
typedef GLboolean (GLAPIENTRYP PFNGLVALIDBACKBUFFERHINTAUTODESKPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#endif


#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glCombinerStageParameterfvNV (GLenum stage, GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glGetCombinerStageParameterfvNV (GLenum stage, GLenum pname, GLfloat *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, GLfloat *params);
#endif


#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glSampleCoverageARB (GLclampf value, GLboolean invert);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLSAMPLECOVERAGEARBPROC) (GLclampf value, GLboolean invert);
#endif


#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawRangeElementsEXT (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWRANGEELEMENTSEXTPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
#endif


#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glFlushPixelDataRangeNV (GLenum target);
GLAPI void GLAPIENTRY glPixelDataRangeNV (GLenum target, GLsizei size, const GLvoid *pointer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLFLUSHPIXELDATARANGENVPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLPIXELDATARANGENVPROC) (GLenum target, GLsizei size, const GLvoid *pointer);
#endif


#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetProgramNamedParameterdvNV (GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
GLAPI void GLAPIENTRY glGetProgramNamedParameterfvNV (GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
GLAPI void GLAPIENTRY glProgramNamedParameter4dNV (GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramNamedParameter4dvNV (GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
GLAPI void GLAPIENTRY glProgramNamedParameter4fNV (GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramNamedParameter4fvNV (GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC) (GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC) (GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DNVPROC) (GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC) (GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FNVPROC) (GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC) (GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
#endif


#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenOcclusionQueriesNV (GLsizei n, GLuint *ids);
GLAPI void GLAPIENTRY glDeleteOcclusionQueriesNV (GLsizei n, const GLuint *ids);
GLAPI GLboolean GLAPIENTRY glIsOcclusionQueryNV (GLuint id);
GLAPI void GLAPIENTRY glBeginOcclusionQueryNV (GLuint id);
GLAPI void GLAPIENTRY glEndOcclusionQueryNV (void);
GLAPI void GLAPIENTRY glGetOcclusionQueryivNV (GLuint id, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetOcclusionQueryuivNV (GLuint id, GLenum pname, GLuint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENOCCLUSIONQUERIESNVPROC) (GLsizei n, GLuint *ids);
typedef void (GLAPIENTRYP PFNGLDELETEOCCLUSIONQUERIESNVPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (GLAPIENTRYP PFNGLISOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLENDOCCLUSIONQUERYNVPROC) (void);
typedef void (GLAPIENTRYP PFNGLGETOCCLUSIONQUERYIVNVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETOCCLUSIONQUERYUIVNVPROC) (GLuint id, GLenum pname, GLuint *params);
#endif


#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameteriNV (GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPointParameterivNV (GLenum pname, const GLint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERINVPROC) (GLenum pname, GLint param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERIVNVPROC) (GLenum pname, const GLint *params);
#endif


#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glMultiDrawArraysEXT (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
GLAPI void GLAPIENTRY glMultiDrawElementsEXT (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLMULTIDRAWARRAYSEXTPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLMULTIDRAWELEMENTSEXTPROC) (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
#endif


#ifndef GL_NV_half_float
#define GL_NV_half_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertex2hNV (GLhalf x, GLhalf y);
GLAPI void GLAPIENTRY glVertex2hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glVertex3hNV (GLhalf x, GLhalf y, GLhalf z);
GLAPI void GLAPIENTRY glVertex3hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glVertex4hNV (GLhalf x, GLhalf y, GLhalf z, GLhalf w);
GLAPI void GLAPIENTRY glVertex4hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glNormal3hNV (GLhalf nx, GLhalf ny, GLhalf nz);
GLAPI void GLAPIENTRY glNormal3hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glColor3hNV (GLhalf red, GLhalf green, GLhalf blue);
GLAPI void GLAPIENTRY glColor3hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glColor4hNV (GLhalf red, GLhalf green, GLhalf blue, GLhalf alpha);
GLAPI void GLAPIENTRY glColor4hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glTexCoord1hNV (GLhalf s);
GLAPI void GLAPIENTRY glTexCoord1hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glTexCoord2hNV (GLhalf s, GLhalf t);
GLAPI void GLAPIENTRY glTexCoord2hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glTexCoord3hNV (GLhalf s, GLhalf t, GLhalf r);
GLAPI void GLAPIENTRY glTexCoord3hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glTexCoord4hNV (GLhalf s, GLhalf t, GLhalf r, GLhalf q);
GLAPI void GLAPIENTRY glTexCoord4hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glMultiTexCoord1hNV (GLenum target, GLhalf s);
GLAPI void GLAPIENTRY glMultiTexCoord1hvNV (GLenum target, const GLhalf *v);
GLAPI void GLAPIENTRY glMultiTexCoord2hNV (GLenum target, GLhalf s, GLhalf t);
GLAPI void GLAPIENTRY glMultiTexCoord2hvNV (GLenum target, const GLhalf *v);
GLAPI void GLAPIENTRY glMultiTexCoord3hNV (GLenum target, GLhalf s, GLhalf t, GLhalf r);
GLAPI void GLAPIENTRY glMultiTexCoord3hvNV (GLenum target, const GLhalf *v);
GLAPI void GLAPIENTRY glMultiTexCoord4hNV (GLenum target, GLhalf s, GLhalf t, GLhalf r, GLhalf q);
GLAPI void GLAPIENTRY glMultiTexCoord4hvNV (GLenum target, const GLhalf *v);
GLAPI void GLAPIENTRY glFogCoordhNV (GLhalf fog);
GLAPI void GLAPIENTRY glFogCoordhvNV (const GLhalf *fog);
GLAPI void GLAPIENTRY glSecondaryColor3hNV (GLhalf red, GLhalf green, GLhalf blue);
GLAPI void GLAPIENTRY glSecondaryColor3hvNV (const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttrib1hNV (GLuint index, GLhalf x);
GLAPI void GLAPIENTRY glVertexAttrib1hvNV (GLuint index, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttrib2hNV (GLuint index, GLhalf x, GLhalf y);
GLAPI void GLAPIENTRY glVertexAttrib2hvNV (GLuint index, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttrib3hNV (GLuint index, GLhalf x, GLhalf y, GLhalf z);
GLAPI void GLAPIENTRY glVertexAttrib3hvNV (GLuint index, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttrib4hNV (GLuint index, GLhalf x, GLhalf y, GLhalf z, GLhalf w);
GLAPI void GLAPIENTRY glVertexAttrib4hvNV (GLuint index, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttribs1hvNV (GLuint index, GLsizei count, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttribs2hvNV (GLuint index, GLsizei count, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttribs3hvNV (GLuint index, GLsizei count, const GLhalf *v);
GLAPI void GLAPIENTRY glVertexAttribs4hvNV (GLuint index, GLsizei count, const GLhalf *v);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEX2HNVPROC) (GLhalf x, GLhalf y);
typedef void (GLAPIENTRYP PFNGLVERTEX2HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEX3HNVPROC) (GLhalf x, GLhalf y, GLhalf z);
typedef void (GLAPIENTRYP PFNGLVERTEX3HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEX4HNVPROC) (GLhalf x, GLhalf y, GLhalf z, GLhalf w);
typedef void (GLAPIENTRYP PFNGLVERTEX4HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLNORMAL3HNVPROC) (GLhalf nx, GLhalf ny, GLhalf nz);
typedef void (GLAPIENTRYP PFNGLNORMAL3HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLCOLOR3HNVPROC) (GLhalf red, GLhalf green, GLhalf blue);
typedef void (GLAPIENTRYP PFNGLCOLOR3HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLCOLOR4HNVPROC) (GLhalf red, GLhalf green, GLhalf blue, GLhalf alpha);
typedef void (GLAPIENTRYP PFNGLCOLOR4HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1HNVPROC) (GLhalf s);
typedef void (GLAPIENTRYP PFNGLTEXCOORD1HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2HNVPROC) (GLhalf s, GLhalf t);
typedef void (GLAPIENTRYP PFNGLTEXCOORD2HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3HNVPROC) (GLhalf s, GLhalf t, GLhalf r);
typedef void (GLAPIENTRYP PFNGLTEXCOORD3HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4HNVPROC) (GLhalf s, GLhalf t, GLhalf r, GLhalf q);
typedef void (GLAPIENTRYP PFNGLTEXCOORD4HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1HNVPROC) (GLenum target, GLhalf s);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD1HVNVPROC) (GLenum target, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2HNVPROC) (GLenum target, GLhalf s, GLhalf t);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD2HVNVPROC) (GLenum target, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3HNVPROC) (GLenum target, GLhalf s, GLhalf t, GLhalf r);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD3HVNVPROC) (GLenum target, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4HNVPROC) (GLenum target, GLhalf s, GLhalf t, GLhalf r, GLhalf q);
typedef void (GLAPIENTRYP PFNGLMULTITEXCOORD4HVNVPROC) (GLenum target, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLFOGCOORDHNVPROC) (GLhalf fog);
typedef void (GLAPIENTRYP PFNGLFOGCOORDHVNVPROC) (const GLhalf *fog);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3HNVPROC) (GLhalf red, GLhalf green, GLhalf blue);
typedef void (GLAPIENTRYP PFNGLSECONDARYCOLOR3HVNVPROC) (const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1HNVPROC) (GLuint index, GLhalf x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1HVNVPROC) (GLuint index, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2HNVPROC) (GLuint index, GLhalf x, GLhalf y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2HVNVPROC) (GLuint index, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3HNVPROC) (GLuint index, GLhalf x, GLhalf y, GLhalf z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3HVNVPROC) (GLuint index, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4HNVPROC) (GLuint index, GLhalf x, GLhalf y, GLhalf z, GLhalf w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4HVNVPROC) (GLuint index, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS1HVNVPROC) (GLuint index, GLsizei count, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS2HVNVPROC) (GLuint index, GLsizei count, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS3HVNVPROC) (GLuint index, GLsizei count, const GLhalf *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBS4HVNVPROC) (GLuint index, GLsizei count, const GLhalf *v);
#endif


#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glActiveStencilFaceEXT (GLenum face);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLACTIVESTENCILFACEEXTPROC) (GLenum face);
#endif


#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEEXTPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#endif


#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPointParameterfARB (GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPointParameterfvARB (GLenum pname, const GLfloat *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFARBPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRYP PFNGLPOINTPARAMETERFVARBPROC) (GLenum pname, const GLfloat *params);
#endif


#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDepthBoundsEXT (GLclampd zmin, GLclampd zmax);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEPTHBOUNDSEXTPROC) (GLclampd zmin, GLclampd zmax);
#endif


#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttrib1dARB (GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dvARB (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib1fARB (GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fvARB (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib1sARB (GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1svARB (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib2dARB (GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dvARB (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib2fARB (GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fvARB (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib2sARB (GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2svARB (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib3dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dvARB (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib3fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fvARB (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib3sARB (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3svARB (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4NbvARB (GLuint index, const GLbyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4NivARB (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttrib4NsvARB (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4NubARB (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4NubvARB (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4NuivARB (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttrib4NusvARB (GLuint index, const GLushort *v);
GLAPI void GLAPIENTRY glVertexAttrib4bvARB (GLuint index, const GLbyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dvARB (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib4fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fvARB (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib4ivARB (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttrib4sARB (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4svARB (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4ubvARB (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4uivARB (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttrib4usvARB (GLuint index, const GLushort *v);
GLAPI void GLAPIENTRY glVertexAttribPointerARB (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glEnableVertexAttribArrayARB (GLuint index);
GLAPI void GLAPIENTRY glDisableVertexAttribArrayARB (GLuint index);
GLAPI void GLAPIENTRY glProgramStringARB (GLenum target, GLenum format, GLsizei len, const GLvoid *string);
GLAPI void GLAPIENTRY glBindProgramARB (GLenum target, GLuint program);
GLAPI void GLAPIENTRY glDeleteProgramsARB (GLsizei n, const GLuint *programs);
GLAPI void GLAPIENTRY glGenProgramsARB (GLsizei n, GLuint *programs);
GLAPI void GLAPIENTRY glProgramEnvParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramEnvParameter4dvARB (GLenum target, GLuint index, const GLdouble *params);
GLAPI void GLAPIENTRY glProgramEnvParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
GLAPI void GLAPIENTRY glProgramLocalParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glProgramLocalParameter4dvARB (GLenum target, GLuint index, const GLdouble *params);
GLAPI void GLAPIENTRY glProgramLocalParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterdvARB (GLenum target, GLuint index, GLdouble *params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterfvARB (GLenum target, GLuint index, GLfloat *params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterdvARB (GLenum target, GLuint index, GLdouble *params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterfvARB (GLenum target, GLuint index, GLfloat *params);
GLAPI void GLAPIENTRY glGetProgramivARB (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetProgramStringARB (GLenum target, GLenum pname, GLvoid *string);
GLAPI void GLAPIENTRY glGetVertexAttribdvARB (GLuint index, GLenum pname, GLdouble *params);
GLAPI void GLAPIENTRY glGetVertexAttribfvARB (GLuint index, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetVertexAttribivARB (GLuint index, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetVertexAttribPointervARB (GLuint index, GLenum pname, GLvoid* *pointer);
GLAPI GLboolean GLAPIENTRY glIsProgramARB (GLuint program);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DARBPROC) (GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVARBPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FARBPROC) (GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVARBPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SARBPROC) (GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVARBPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DARBPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVARBPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FARBPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVARBPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SARBPROC) (GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVARBPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVARBPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVARBPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVARBPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NBVARBPROC) (GLuint index, const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NIVARBPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NSVARBPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBARBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBVARBPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUIVARBPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUSVARBPROC) (GLuint index, const GLushort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4BVARBPROC) (GLuint index, const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DARBPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVARBPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FARBPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVARBPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4IVARBPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SARBPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVARBPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVARBPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UIVARBPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4USVARBPROC) (GLuint index, const GLushort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERARBPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
typedef void (GLAPIENTRYP PFNGLPROGRAMSTRINGARBPROC) (GLenum target, GLenum format, GLsizei len, const GLvoid *string);
typedef void (GLAPIENTRYP PFNGLBINDPROGRAMARBPROC) (GLenum target, GLuint program);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMSARBPROC) (GLsizei n, const GLuint *programs);
typedef void (GLAPIENTRYP PFNGLGENPROGRAMSARBPROC) (GLsizei n, GLuint *programs);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVARBPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMSTRINGARBPROC) (GLenum target, GLenum pname, GLvoid *string);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVARBPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVARBPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVARBPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVARBPROC) (GLuint index, GLenum pname, GLvoid* *pointer);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMARBPROC) (GLuint program);
#endif


#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glPrimitiveRestartNV (void);
GLAPI void GLAPIENTRY glPrimitiveRestartIndexNV (GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTNVPROC) (void);
typedef void (GLAPIENTRYP PFNGLPRIMITIVERESTARTINDEXNVPROC) (GLuint index);
#endif


#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindBufferARB (GLenum target, GLuint buffer);
GLAPI void GLAPIENTRY glBufferDataARB (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
GLAPI void GLAPIENTRY glBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
GLAPI void GLAPIENTRY glDeleteBuffersARB (GLsizei n, const GLuint *buffers);
GLAPI void GLAPIENTRY glGenBuffersARB (GLsizei n, GLuint *buffers);
GLAPI void GLAPIENTRY glGetBufferParameterivARB (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetBufferPointervARB (GLenum target, GLenum pname, GLvoid* *params);
GLAPI void GLAPIENTRY glGetBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
GLAPI GLboolean GLAPIENTRY glIsBufferARB (GLuint buffer);
GLAPI GLvoid* GLAPIENTRY glMapBufferARB (GLenum target, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapBufferARB (GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDBUFFERARBPROC) (GLenum target, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLBUFFERDATAARBPROC) (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint *buffers);
typedef void (GLAPIENTRYP PFNGLGENBUFFERSARBPROC) (GLsizei n, GLuint *buffers);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPOINTERVARBPROC) (GLenum target, GLenum pname, GLvoid* *params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERSUBDATAARBPROC) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
typedef GLboolean (GLAPIENTRYP PFNGLISBUFFERARBPROC) (GLuint buffer);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERARBPROC) (GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPBUFFERARBPROC) (GLenum target);
#endif


#ifndef GL_ARB_vertex_array_set_object
#define GL_ARB_vertex_array_set_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindArraySetARB (GLuint buffer);
GLAPI void GLAPIENTRY glDeleteArraySetsARB (GLsizei n, const GLuint *buffers);
GLAPI void GLAPIENTRY glGenArraySetsARB (GLsizei n, GLuint *buffers);
GLAPI GLboolean GLAPIENTRY glIsArraySetARB (GLuint buffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDARRAYSETARBPROC) (GLuint buffer);
typedef void (GLAPIENTRYP PFNGLDELETEARRAYSETSARBPROC) (GLsizei n, const GLuint *buffers);
typedef void (GLAPIENTRYP PFNGLGENARRAYSETSARBPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (GLAPIENTRYP PFNGLISARRAYSETARBPROC) (GLuint buffer);
#endif


#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenQueriesARB (GLsizei n, GLuint *ids);
GLAPI void GLAPIENTRY glDeleteQueriesARB (GLsizei n, const GLuint *ids);
GLAPI GLboolean GLAPIENTRY glIsQueryARB (GLuint id);
GLAPI void GLAPIENTRY glBeginQueryARB (GLenum target, GLuint id);
GLAPI void GLAPIENTRY glEndQueryARB (GLenum target);
GLAPI void GLAPIENTRY glGetQueryObjectivARB (GLuint id, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetQueryObjectuivARB (GLuint id, GLenum pname, GLuint *params);
GLAPI void GLAPIENTRY glGetQueryivARB (GLenum target, GLenum pname, GLint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENQUERIESARBPROC) (GLsizei n, GLuint *ids);
typedef void (GLAPIENTRYP PFNGLDELETEQUERIESARBPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (GLAPIENTRYP PFNGLISQUERYARBPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYARBPROC) (GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYARBPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTIVARBPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUIVARBPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (GLAPIENTRYP PFNGLGETQUERYIVARBPROC) (GLenum target, GLenum pname, GLint *params);
#endif


#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffersATI (GLsizei n, const GLenum *bufs);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSATIPROC) (GLsizei n, const GLenum *bufs);
#endif


#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffersARB (GLsizei n, const GLenum *bufs);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSARBPROC) (GLsizei n, const GLenum *bufs);
#endif


#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationSeparateEXT (GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEEXTPROC) (GLenum modeRGB, GLenum modeAlpha);
#endif


#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDeleteObjectARB (GLhandleARB obj);
GLAPI GLhandleARB GLAPIENTRY glGetHandleARB (GLenum pname);
GLAPI void GLAPIENTRY glDetachObjectARB (GLhandleARB containerObj, GLhandleARB attachedObj);
GLAPI GLhandleARB GLAPIENTRY glCreateShaderObjectARB (GLenum shaderType);
GLAPI void GLAPIENTRY glShaderSourceARB (GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
GLAPI void GLAPIENTRY glCompileShaderARB (GLhandleARB shaderObj);
GLAPI GLhandleARB GLAPIENTRY glCreateProgramObjectARB (void);
GLAPI void GLAPIENTRY glAttachObjectARB (GLhandleARB containerObj, GLhandleARB attachedObj);
GLAPI void GLAPIENTRY glLinkProgramARB (GLhandleARB programObj);
GLAPI void GLAPIENTRY glUseProgramObjectARB (GLhandleARB programObj);
GLAPI void GLAPIENTRY glValidateProgramARB (GLhandleARB programObj);
GLAPI void GLAPIENTRY glUniform1fARB (GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glUniform2fARB (GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glUniform3fARB (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glUniform4fARB (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glUniform1iARB (GLint location, GLint v0);
GLAPI void GLAPIENTRY glUniform2iARB (GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glUniform3iARB (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glUniform4iARB (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glUniform1fvARB (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform2fvARB (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform3fvARB (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform4fvARB (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform1ivARB (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform2ivARB (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform3ivARB (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform4ivARB (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniformMatrix2fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix3fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix4fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glGetObjectParameterfvARB (GLhandleARB obj, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetObjectParameterivARB (GLhandleARB obj, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetInfoLogARB (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
GLAPI void GLAPIENTRY glGetAttachedObjectsARB (GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
GLAPI GLint GLAPIENTRY glGetUniformLocationARB (GLhandleARB programObj, const GLcharARB *name);
GLAPI void GLAPIENTRY glGetActiveUniformARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLsizei *size, GLenum *type, GLcharARB *name);
GLAPI void GLAPIENTRY glGetUniformfvARB (GLhandleARB programObj, GLint location, GLfloat *params);
GLAPI void GLAPIENTRY glGetUniformivARB (GLhandleARB programObj, GLint location, GLint *params);
GLAPI void GLAPIENTRY glGetShaderSourceARB (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDELETEOBJECTARBPROC) (GLhandleARB obj);
typedef GLhandleARB (GLAPIENTRYP PFNGLGETHANDLEARBPROC) (GLenum pname);
typedef void (GLAPIENTRYP PFNGLDETACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB attachedObj);
typedef GLhandleARB (GLAPIENTRYP PFNGLCREATESHADEROBJECTARBPROC) (GLenum shaderType);
typedef void (GLAPIENTRYP PFNGLSHADERSOURCEARBPROC) (GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
typedef void (GLAPIENTRYP PFNGLCOMPILESHADERARBPROC) (GLhandleARB shaderObj);
typedef GLhandleARB (GLAPIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC) (void);
typedef void (GLAPIENTRYP PFNGLATTACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB attachedObj);
typedef void (GLAPIENTRYP PFNGLLINKPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC) (GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FARBPROC) (GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FARBPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IARBPROC) (GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IARBPROC) (GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC) (GLhandleARB obj, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC) (GLhandleARB obj, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETINFOLOGARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
typedef void (GLAPIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC) (GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB *name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLsizei *size, GLenum *type, GLcharARB *name);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMFVARBPROC) (GLhandleARB programObj, GLint location, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMIVARBPROC) (GLhandleARB programObj, GLint location, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETSHADERSOURCEARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
#endif


#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindAttribLocationARB (GLhandleARB programObj, GLuint index, const GLcharARB *name);
GLAPI void GLAPIENTRY glGetActiveAttribARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLsizei *size, GLenum *type, GLcharARB *name);
GLAPI GLint GLAPIENTRY glGetAttribLocationARB (GLhandleARB programObj, const GLcharARB *name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC) (GLhandleARB programObj, GLuint index, const GLcharARB *name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEATTRIBARBPROC) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLsizei *size, GLenum *type, GLcharARB *name);
typedef GLint (GLAPIENTRYP PFNGLGETATTRIBLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB *name);
#endif


#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBindBuffer (GLenum target, GLuint buffer);
GLAPI void GLAPIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
GLAPI void GLAPIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
GLAPI void GLAPIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void GLAPIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI void GLAPIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetBufferPointerv (GLenum target, GLenum pname, GLvoid* *params);
GLAPI void GLAPIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
GLAPI GLboolean GLAPIENTRY glIsBuffer (GLuint buffer);
GLAPI GLvoid* GLAPIENTRY glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean GLAPIENTRY glUnmapBuffer (GLenum target);
GLAPI void GLAPIENTRY glGenQueries (GLsizei n, GLuint *ids);
GLAPI void GLAPIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean GLAPIENTRY glIsQuery (GLuint id);
GLAPI void GLAPIENTRY glBeginQuery (GLenum target, GLuint id);
GLAPI void GLAPIENTRY glEndQuery (GLenum target);
GLAPI void GLAPIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void GLAPIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
typedef void (GLAPIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
typedef void (GLAPIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (GLAPIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, GLvoid* *params);
typedef void (GLAPIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
typedef GLboolean (GLAPIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef GLvoid* (GLAPIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (GLAPIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (GLAPIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (GLAPIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (GLAPIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
#endif


#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
GLAPI void GLAPIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
GLAPI void GLAPIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
GLAPI void GLAPIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib1s (GLuint index, GLshort x);
GLAPI void GLAPIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void GLAPIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
GLAPI void GLAPIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
GLAPI void GLAPIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void GLAPIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void GLAPIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void GLAPIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void GLAPIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
GLAPI void GLAPIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void GLAPIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
GLAPI void GLAPIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void GLAPIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
GLAPI void GLAPIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void GLAPIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
GLAPI void GLAPIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glEnableVertexAttribArray (GLuint index);
GLAPI void GLAPIENTRY glDisableVertexAttribArray (GLuint index);
GLAPI void GLAPIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void GLAPIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid* *pointer);
GLAPI void GLAPIENTRY glDeleteShader (GLuint shader);
GLAPI void GLAPIENTRY glDetachShader (GLuint program, GLuint shader);
GLAPI GLuint GLAPIENTRY glCreateShader (GLenum type);
GLAPI void GLAPIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
GLAPI void GLAPIENTRY glCompileShader (GLuint shader);
GLAPI GLuint GLAPIENTRY glCreateProgram (void);
GLAPI void GLAPIENTRY glAttachShader (GLuint program, GLuint shader);
GLAPI void GLAPIENTRY glLinkProgram (GLuint program);
GLAPI void GLAPIENTRY glUseProgram (GLuint program);
GLAPI void GLAPIENTRY glDeleteProgram (GLuint program);
GLAPI void GLAPIENTRY glValidateProgram (GLuint program);
GLAPI void GLAPIENTRY glUniform1f (GLint location, GLfloat v0);
GLAPI void GLAPIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
GLAPI void GLAPIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void GLAPIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void GLAPIENTRY glUniform1i (GLint location, GLint v0);
GLAPI void GLAPIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
GLAPI void GLAPIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void GLAPIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void GLAPIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void GLAPIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
GLAPI void GLAPIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI GLboolean GLAPIENTRY glIsShader (GLuint shader);
GLAPI GLboolean GLAPIENTRY glIsProgram (GLuint program);
GLAPI void GLAPIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI void GLAPIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void GLAPIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI GLint GLAPIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
GLAPI void GLAPIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void GLAPIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
GLAPI void GLAPIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
GLAPI void GLAPIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI void GLAPIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
GLAPI void GLAPIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI GLint GLAPIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
GLAPI void GLAPIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void GLAPIENTRY glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void GLAPIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
GLAPI void GLAPIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, GLvoid* *pointer);
typedef void (GLAPIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (GLAPIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef GLuint (GLAPIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (GLAPIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
typedef void (GLAPIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (GLAPIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef void (GLAPIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (GLAPIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef GLboolean (GLAPIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef GLboolean (GLAPIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef void (GLAPIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (GLAPIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef void (GLAPIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef GLint (GLAPIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (GLAPIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (GLAPIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
typedef void (GLAPIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
#endif


#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginConditionalRenderNVX (GLuint id);
GLAPI void GLAPIENTRY glEndConditionalRenderNVX (void);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINCONDITIONALRENDERNVXPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLENDCONDITIONALRENDERNVXPROC) (void);
#endif


#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginConditionalRenderNV (GLuint id, GLenum mode);
GLAPI void GLAPIENTRY glEndConditionalRenderNV (void);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC) (GLuint id, GLenum mode);
typedef void (GLAPIENTRYP PFNGLENDCONDITIONALRENDERNVPROC) (void);
#endif


#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLboolean GLAPIENTRY glIsRenderbufferEXT (GLuint renderbuffer);
GLAPI void GLAPIENTRY glBindRenderbufferEXT (GLenum target, GLuint renderbuffer);
GLAPI void GLAPIENTRY glDeleteRenderbuffersEXT (GLsizei n, const GLuint *renderbuffers);
GLAPI void GLAPIENTRY glGenRenderbuffersEXT (GLsizei n, GLuint *renderbuffers);
GLAPI void GLAPIENTRY glRenderbufferStorageEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glGetRenderbufferParameterivEXT (GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean GLAPIENTRY glIsFramebufferEXT (GLuint framebuffer);
GLAPI void GLAPIENTRY glBindFramebufferEXT (GLenum target, GLuint framebuffer);
GLAPI void GLAPIENTRY glDeleteFramebuffersEXT (GLsizei n, const GLuint *framebuffers);
GLAPI void GLAPIENTRY glGenFramebuffersEXT (GLsizei n, GLuint *framebuffers);
GLAPI GLenum GLAPIENTRY glCheckFramebufferStatusEXT (GLenum target);
GLAPI void GLAPIENTRY glFramebufferTexture1DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture2DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTexture3DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void GLAPIENTRY glFramebufferRenderbufferEXT (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void GLAPIENTRY glGetFramebufferAttachmentParameterivEXT (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGenerateMipmapEXT (GLenum target);
#endif /* GL_GLEXT_PROTOTYPES */
typedef GLboolean (GLAPIENTRYP PFNGLISRENDERBUFFEREXTPROC) (GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLBINDRENDERBUFFEREXTPROC) (GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLDELETERENDERBUFFERSEXTPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void (GLAPIENTRYP PFNGLGENRENDERBUFFERSEXTPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean (GLAPIENTRYP PFNGLISFRAMEBUFFEREXTPROC) (GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLBINDFRAMEBUFFEREXTPROC) (GLenum target, GLuint framebuffer);
typedef void (GLAPIENTRYP PFNGLDELETEFRAMEBUFFERSEXTPROC) (GLsizei n, const GLuint *framebuffers);
typedef void (GLAPIENTRYP PFNGLGENFRAMEBUFFERSEXTPROC) (GLsizei n, GLuint *framebuffers);
typedef GLenum (GLAPIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) (GLenum target);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE1DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURE3DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGENERATEMIPMAPEXTPROC) (GLenum target);
#endif


#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glClampColorARB (GLenum target, GLenum clamp);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCLAMPCOLORARBPROC) (GLenum target, GLenum clamp);
#endif


#ifndef GL_EXT_ycbcr_422
#define GL_EXT_ycbcr_422 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glLoadTransformEXT (GLenum transform);
GLAPI void GLAPIENTRY glMultTransformEXT (GLenum transform);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLLOADTRANSFORMEXTPROC) (GLenum transform);
typedef void (GLAPIENTRYP PFNGLMULTTRANSFORMEXTPROC) (GLenum transform);
#endif


#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBeginTransformFeedbackNV (GLenum primitiveMode);
GLAPI void GLAPIENTRY glEndTransformFeedbackNV (void);
GLAPI void GLAPIENTRY glTransformFeedbackAttribsNV (GLuint count, const GLint *attribs, GLenum bufferMode);
GLAPI void GLAPIENTRY glBindBufferRangeNV (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void GLAPIENTRY glBindBufferOffsetNV (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
GLAPI void GLAPIENTRY glBindBufferBaseNV (GLenum target, GLuint index, GLuint buffer);
GLAPI void GLAPIENTRY glTransformFeedbackVaryingsNV (GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
GLAPI void GLAPIENTRY glActiveVaryingNV (GLuint program, const GLchar *name);
GLAPI GLint GLAPIENTRY glGetVaryingLocationNV (GLuint program, const GLchar *name);
GLAPI void GLAPIENTRY glGetActiveVaryingNV (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void GLAPIENTRY glGetTransformFeedbackVaryingNV (GLuint program, GLuint index, GLint *location);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBEGINTRANSFORMFEEDBACKNVPROC) (GLenum primitiveMode);
typedef void (GLAPIENTRYP PFNGLENDTRANSFORMFEEDBACKNVPROC) (void);
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC) (GLuint count, const GLint *attribs, GLenum bufferMode);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERRANGENVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRYP PFNGLBINDBUFFEROFFSETNVPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef void (GLAPIENTRYP PFNGLBINDBUFFERBASENVPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (GLAPIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC) (GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
typedef void (GLAPIENTRYP PFNGLACTIVEVARYINGNVPROC) (GLuint program, const GLchar *name);
typedef GLint (GLAPIENTRYP PFNGLGETVARYINGLOCATIONNVPROC) (GLuint program, const GLchar *name);
typedef void (GLAPIENTRYP PFNGLGETACTIVEVARYINGNVPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (GLAPIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC) (GLuint program, GLuint index, GLint *location);
#endif


#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGenTransformFeedbacksNV (GLsizei n, GLuint *ids);
GLAPI void GLAPIENTRY glDeleteTransformFeedbacksNV (GLsizei n, const GLuint *ids);
GLAPI void GLAPIENTRY glBindTransformFeedbackNV (GLenum target, GLuint id);
GLAPI GLboolean GLAPIENTRY glIsTransformFeedbackNV (GLuint id);
GLAPI void GLAPIENTRY glPauseTransformFeedbackNV (void);
GLAPI void GLAPIENTRY glResumeTransformFeedbackNV (void);
GLAPI void GLAPIENTRY glDrawTransformFeedbackNV (GLenum mode, GLuint name);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGENTRANSFORMFEEDBACKSNVPROC) (GLsizei n, GLuint *ids);
typedef void (GLAPIENTRYP PFNGLDELETETRANSFORMFEEDBACKSNVPROC) (GLsizei n, const GLuint *ids);
typedef void (GLAPIENTRYP PFNGLBINDTRANSFORMFEEDBACKNVPROC) (GLenum target, GLuint id);
typedef GLboolean (GLAPIENTRYP PFNGLISTRANSFORMFEEDBACKNVPROC) (GLuint id);
typedef void (GLAPIENTRYP PFNGLPAUSETRANSFORMFEEDBACKNVPROC) (void);
typedef void (GLAPIENTRYP PFNGLRESUMETRANSFORMFEEDBACKNVPROC) (void);
typedef void (GLAPIENTRYP PFNGLDRAWTRANSFORMFEEDBACKNVPROC) (GLenum mode, GLuint name);
#endif


#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDepthRangedNV (GLdouble zNear, GLdouble zFar);
GLAPI void GLAPIENTRY glClearDepthdNV (GLdouble depth);
GLAPI void GLAPIENTRY glDepthBoundsdNV (GLdouble zmin, GLdouble zmax);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDEPTHRANGEDNVPROC) (GLdouble zNear, GLdouble zFar);
typedef void (GLAPIENTRYP PFNGLCLEARDEPTHDNVPROC) (GLdouble depth);
typedef void (GLAPIENTRYP PFNGLDEPTHBOUNDSDNVPROC) (GLdouble zmin, GLdouble zmax);
#endif


#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glColorMaskIndexedEXT (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void GLAPIENTRY glGetBooleanIndexedvEXT (GLenum target, GLuint index, GLboolean *data);
GLAPI void GLAPIENTRY glGetIntegerIndexedvEXT (GLenum target, GLuint index, GLint *data);
GLAPI void GLAPIENTRY glEnableIndexedEXT (GLenum target, GLuint index);
GLAPI void GLAPIENTRY glDisableIndexedEXT (GLenum target, GLuint index);
GLAPI GLboolean GLAPIENTRY glIsEnabledIndexedEXT (GLenum target, GLuint index);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLCOLORMASKINDEXEDEXTPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (GLAPIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (GLAPIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint *data);
typedef void (GLAPIENTRYP PFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (GLAPIENTRYP PFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef GLboolean (GLAPIENTRYP PFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
#endif


#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetQueryObjecti64vEXT (GLuint id, GLenum pname, GLint64EXT *params);
GLAPI void GLAPIENTRY glGetQueryObjectui64vEXT (GLuint id, GLenum pname, GLuint64EXT *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC) (GLuint id, GLenum pname, GLint64EXT *params);
typedef void (GLAPIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC) (GLuint id, GLenum pname, GLuint64EXT *params);
#endif


#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramLocalParameterI4iNV (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glProgramLocalParameterI4ivNV (GLenum target, GLuint index, const GLint *params);
GLAPI void GLAPIENTRY glProgramLocalParametersI4ivNV (GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI void GLAPIENTRY glProgramLocalParameterI4uiNV (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glProgramLocalParameterI4uivNV (GLenum target, GLuint index, const GLuint *params);
GLAPI void GLAPIENTRY glProgramLocalParametersI4uivNV (GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI void GLAPIENTRY glProgramEnvParameterI4iNV (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glProgramEnvParameterI4ivNV (GLenum target, GLuint index, const GLint *params);
GLAPI void GLAPIENTRY glProgramEnvParametersI4ivNV (GLenum target, GLuint index, GLsizei count, const GLint *params);
GLAPI void GLAPIENTRY glProgramEnvParameterI4uiNV (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glProgramEnvParameterI4uivNV (GLenum target, GLuint index, const GLuint *params);
GLAPI void GLAPIENTRY glProgramEnvParametersI4uivNV (GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterIivNV (GLenum target, GLuint index, GLint *params);
GLAPI void GLAPIENTRY glGetProgramLocalParameterIuivNV (GLenum target, GLuint index, GLuint *params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterIivNV (GLenum target, GLuint index, GLint *params);
GLAPI void GLAPIENTRY glGetProgramEnvParameterIuivNV (GLenum target, GLuint index, GLuint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4INVPROC) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4IVNVPROC) (GLenum target, GLuint index, const GLint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERSI4IVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4UINVPROC) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERI4UIVNVPROC) (GLenum target, GLuint index, const GLuint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERIIVNVPROC) (GLenum target, GLuint index, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC) (GLenum target, GLuint index, GLuint *params);
#endif


#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramBufferParametersfvNV (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params);
GLAPI void GLAPIENTRY glProgramBufferParametersIivNV (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params);
GLAPI void GLAPIENTRY glProgramBufferParametersIuivNV (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC) (GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params);
#endif


#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexParameterIivEXT (GLenum target, GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glTexParameterIuivEXT (GLenum target, GLenum pname, const GLuint *params);
GLAPI void GLAPIENTRY glGetTexParameterIivEXT (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetTexParameterIuivEXT (GLenum target, GLenum pname, GLuint *params);
GLAPI void GLAPIENTRY glClearColorIiEXT (GLint red, GLint green, GLint blue, GLint alpha);
GLAPI void GLAPIENTRY glClearColorIuiEXT (GLuint red, GLuint green, GLuint blue, GLuint alpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (GLAPIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, const GLuint *params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC) (GLenum target, GLenum pname, GLuint *params);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORIIEXTPROC) (GLint red, GLint green, GLint blue, GLint alpha);
typedef void (GLAPIENTRYP PFNGLCLEARCOLORIUIEXTPROC) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
#endif


#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlitFramebufferEXT (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif


#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleEXT (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glVertexAttribI1iEXT (GLuint index, GLint x);
GLAPI void GLAPIENTRY glVertexAttribI2iEXT (GLuint index, GLint x, GLint y);
GLAPI void GLAPIENTRY glVertexAttribI3iEXT (GLuint index, GLint x, GLint y, GLint z);
GLAPI void GLAPIENTRY glVertexAttribI4iEXT (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void GLAPIENTRY glVertexAttribI1uiEXT (GLuint index, GLuint x);
GLAPI void GLAPIENTRY glVertexAttribI2uiEXT (GLuint index, GLuint x, GLuint y);
GLAPI void GLAPIENTRY glVertexAttribI3uiEXT (GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void GLAPIENTRY glVertexAttribI4uiEXT (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void GLAPIENTRY glVertexAttribI1ivEXT (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttribI2ivEXT (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttribI3ivEXT (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttribI4ivEXT (GLuint index, const GLint *v);
GLAPI void GLAPIENTRY glVertexAttribI1uivEXT (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttribI2uivEXT (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttribI3uivEXT (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttribI4uivEXT (GLuint index, const GLuint *v);
GLAPI void GLAPIENTRY glVertexAttribI4bvEXT (GLuint index, const GLbyte *v);
GLAPI void GLAPIENTRY glVertexAttribI4svEXT (GLuint index, const GLshort *v);
GLAPI void GLAPIENTRY glVertexAttribI4ubvEXT (GLuint index, const GLubyte *v);
GLAPI void GLAPIENTRY glVertexAttribI4usvEXT (GLuint index, const GLushort *v);
GLAPI void GLAPIENTRY glVertexAttribIPointerEXT (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GLAPI void GLAPIENTRY glGetVertexAttribIivEXT (GLuint index, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetVertexAttribIuivEXT (GLuint index, GLenum pname, GLuint *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IEXTPROC) (GLuint index, GLint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IEXTPROC) (GLuint index, GLint x, GLint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IEXTPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IEXTPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIEXTPROC) (GLuint index, GLuint x);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIEXTPROC) (GLuint index, GLuint x, GLuint y);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIEXTPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1IVEXTPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2IVEXTPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3IVEXTPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4IVEXTPROC) (GLuint index, const GLint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI1UIVEXTPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI2UIVEXTPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI3UIVEXTPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UIVEXTPROC) (GLuint index, const GLuint *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4BVEXTPROC) (GLuint index, const GLbyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4SVEXTPROC) (GLuint index, const GLshort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4UBVEXTPROC) (GLuint index, const GLubyte *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBI4USVEXTPROC) (GLuint index, const GLushort *v);
typedef void (GLAPIENTRYP PFNGLVERTEXATTRIBIPOINTEREXTPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIIVEXTPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (GLAPIENTRYP PFNGLGETVERTEXATTRIBIUIVEXTPROC) (GLuint index, GLenum pname, GLuint *params);
#endif


#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramEnvParameters4fvEXT (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLAPI void GLAPIENTRY glProgramLocalParameters4fvEXT (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMENVPARAMETERS4FVEXTPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (GLAPIENTRYP PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
#endif


#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glDrawArraysInstancedEXT (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
GLAPI void GLAPIENTRY glDrawElementsInstancedEXT (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (GLAPIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
#endif


#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glTexBufferEXT (GLenum target, GLenum internalformat, GLuint buffer);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLTEXBUFFEREXTPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif


#ifndef GL_NVX_gpu_sync_buffer
#define GL_NVX_gpu_sync_buffer 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGpuSyncGetHandleSizeNVX (GLuint *initSize, GLuint *mapSize);
GLAPI void GLAPIENTRY glGpuSyncInitNVX (GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncEndNVX (GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncMapBufferNVX (GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncUnmapBufferNVX (GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncCopyBufferNVX (GLuint offset, GLuint size, GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncAcquireNVX (GLvoid* syncData);
GLAPI void GLAPIENTRY glGpuSyncReleaseNVX (GLvoid* syncData);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGPUSYNCGETHANDLESIZENVXPROC) (GLuint *initSize, GLuint *mapSize);
typedef void (GLAPIENTRYP PFNGLGPUSYNCINITNVXPROC) (GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCENDNVXPROC) (GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCMAPBUFFERNVXPROC) (GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCUNMAPBUFFERNVXPROC) (GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCCOPYBUFFERNVXPROC) (GLuint offset, GLuint size, GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCACQUIRENVXPROC) (GLvoid* syncData);
typedef void (GLAPIENTRYP PFNGLGPUSYNCRELEASENVXPROC) (GLvoid* syncData);
#endif


#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramVertexLimitNV (GLenum target, GLint limit);
GLAPI void GLAPIENTRY glFramebufferTextureEXT (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void GLAPIENTRY glFramebufferTextureLayerEXT (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void GLAPIENTRY glFramebufferTextureFaceEXT (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMVERTEXLIMITNVPROC) (GLenum target, GLint limit);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif


#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glGetUniformuivEXT (GLuint program, GLint location, GLuint *params);
GLAPI void GLAPIENTRY glBindFragDataLocationEXT (GLuint program, GLuint color, const GLchar *name);
GLAPI GLint GLAPIENTRY glGetFragDataLocationEXT (GLuint program, const GLchar *name);
GLAPI void GLAPIENTRY glUniform1uiEXT (GLint location, GLuint v0);
GLAPI void GLAPIENTRY glUniform2uiEXT (GLint location, GLuint v0, GLuint v1);
GLAPI void GLAPIENTRY glUniform3uiEXT (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void GLAPIENTRY glUniform4uiEXT (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void GLAPIENTRY glUniform1uivEXT (GLint location, GLsizei count, const GLuint *value);
GLAPI void GLAPIENTRY glUniform2uivEXT (GLint location, GLsizei count, const GLuint *value);
GLAPI void GLAPIENTRY glUniform3uivEXT (GLint location, GLsizei count, const GLuint *value);
GLAPI void GLAPIENTRY glUniform4uivEXT (GLint location, GLsizei count, const GLuint *value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLGETUNIFORMUIVEXTPROC) (GLuint program, GLint location, GLuint *params);
typedef void (GLAPIENTRYP PFNGLBINDFRAGDATALOCATIONEXTPROC) (GLuint program, GLuint color, const GLchar *name);
typedef GLint (GLAPIENTRYP PFNGLGETFRAGDATALOCATIONEXTPROC) (GLuint program, const GLchar *name);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIEXTPROC) (GLint location, GLuint v0);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIEXTPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIEXTPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAPIENTRYP PFNGLUNIFORM1UIVEXTPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM2UIVEXTPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM3UIVEXTPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (GLAPIENTRYP PFNGLUNIFORM4UIVEXTPROC) (GLint location, GLsizei count, const GLuint *value);
#endif


#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glProgramParameteriEXT (GLuint program, GLenum pname, GLint value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC) (GLuint program, GLenum pname, GLint value);
#endif


#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniformBufferEXT (GLuint program, GLint location, GLuint buffer);
GLAPI GLint GLAPIENTRY glGetUniformBufferSizeEXT (GLuint program, GLint location);
GLAPI GLintptr GLAPIENTRY glGetUniformOffsetEXT (GLuint program, GLint location);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORMBUFFEREXTPROC) (GLuint program, GLint location, GLuint buffer);
typedef GLint (GLAPIENTRYP PFNGLGETUNIFORMBUFFERSIZEEXTPROC) (GLuint program, GLint location);
typedef GLintptr (GLAPIENTRYP PFNGLGETUNIFORMOFFSETEXTPROC) (GLuint program, GLint location);
#endif


#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void GLAPIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif


#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glRenderbufferStorageMultisampleCoverageNV (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif


#ifndef GL_NV_draw_buffers3
#define GL_NV_draw_buffers3 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void GLAPIENTRY glBlendEquationIndexedNV (GLuint buf, GLenum mode);
GLAPI void GLAPIENTRY glBlendEquationSeparateIndexedNV (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void GLAPIENTRY glBlendFuncIndexedNV (GLuint buf, GLenum src, GLenum dst);
GLAPI void GLAPIENTRY glBlendFuncSeparateIndexedNV (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONINDEXEDNVPROC) (GLuint buf, GLenum mode);
typedef void (GLAPIENTRYP PFNGLBLENDEQUATIONSEPARATEINDEXEDNVPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCINDEXEDNVPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (GLAPIENTRYP PFNGLBLENDFUNCSEPARATEINDEXEDNVPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif

/*************************************************************/

/* Version */
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2                    1
#endif
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3                    1
#endif
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4                    1
#endif
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5                    1
#endif
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0                    1
#endif
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1                    1
#endif

/* Extensions */
#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint           1
#endif
#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float         1
#endif
#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture              1
#endif
#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers               1
#endif
#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program           1
#endif
#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow    1
#endif
#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader            1
#endif
#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel           1
#endif
#ifndef GL_ARB_imaging
#define GL_ARB_imaging                    1
#endif
#ifndef GL_ARB_multisample
#define GL_ARB_multisample                1
#endif
#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture               1
#endif
#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query            1
#endif
#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object        1
#endif
#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters           1
#endif
#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite               1
#endif
#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects             1
#endif
#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100       1
#endif
#ifndef GL_ARB_shadow
#define GL_ARB_shadow                     1
#endif
#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient             1
#endif
#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp       1
#endif
#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression        1
#endif
#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map           1
#endif
#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add            1
#endif
#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine        1
#endif
#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3           1
#endif
#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float              1
#endif
#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat    1
#endif
#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two   1
#endif
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle          1
#endif
#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix           1
#endif
#ifndef GL_ARB_vertex_array_set_object
#define GL_ARB_vertex_array_set_object    1
#endif
#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object       1
#endif
#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program             1
#endif
#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader              1
#endif
#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos                 1
#endif
#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers               1
#endif
#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float         1
#endif
#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float              1
#endif
#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once        1
#endif
#ifndef GL_Autodesk_valid_back_buffer_hint
#define GL_Autodesk_valid_back_buffer_hint 1
#endif
#ifndef GL_EXT_Cg_shader
#define GL_EXT_Cg_shader                  1
#endif
#ifndef GL_EXT_abgr
#define GL_EXT_abgr                       1
#endif
#ifndef GL_EXT_bgra
#define GL_EXT_bgra                       1
#endif
#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform           1
#endif
#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color                1
#endif
#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate    1
#endif
#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate        1
#endif
#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax               1
#endif
#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract             1
#endif
#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint           1
#endif
#ifndef GL_EXT_color_table
#define GL_EXT_color_table                1
#endif
#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array      1
#endif
#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test          1
#endif
#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2              1
#endif
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced             1
#endif
#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements        1
#endif
#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord                  1
#endif
#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit           1
#endif
#ifndef GL_EXT_framebuffer_mixed_formats
#define GL_EXT_framebuffer_mixed_formats  1
#endif
#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample    1
#endif
#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object         1
#endif
#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB           1
#endif
#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4           1
#endif
#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters     1
#endif
#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4                1
#endif
#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays          1
#endif
#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil       1
#endif
#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float               1
#endif
#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels              1
#endif
#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture           1
#endif
#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object        1
#endif
#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters           1
#endif
#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal             1
#endif
#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color            1
#endif
#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color    1
#endif
#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs               1
#endif
#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette     1
#endif
#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side           1
#endif
#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap               1
#endif
#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D                  1
#endif
#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array              1
#endif
#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object      1
#endif
#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc   1
#endif
#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc   1
#endif
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc   1
#endif
#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map           1
#endif
#ifndef GL_EXT_texture_edge_clamp
#define GL_EXT_texture_edge_clamp         1
#endif
#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add            1
#endif
#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine        1
#endif
#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3           1
#endif
#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
#endif
#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer            1
#endif
#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias           1
#endif
#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp       1
#endif
#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object             1
#endif
#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent    1
#endif
#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB               1
#endif
#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query                1
#endif
#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array               1
#endif
#ifndef GL_EXT_ycbcr_422
#define GL_EXT_ycbcr_422                  1
#endif
#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test              1
#endif
#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip             1
#endif
#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat    1
#endif
#ifndef GL_NV_blend_square
#define GL_NV_blend_square                1
#endif
#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render          1
#endif
#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color         1
#endif
#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float          1
#endif
#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp                 1
#endif
#ifndef GL_NV_draw_mesh
#define GL_NV_draw_mesh                   1
#endif
#ifndef GL_NV_draw_buffers3
#define GL_NV_draw_buffers3               1
#endif
#ifndef GL_NV_extended_combiner_program
#define GL_NV_extended_combiner_program   1
#endif
#ifndef GL_NV_fence
#define GL_NV_fence                       1
#endif
#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer                1
#endif
#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance                1
#endif
#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program            1
#endif
#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2           1
#endif
#ifndef GL_NV_fragment_program4
#define GL_NV_fragment_program4           1
#endif
#ifndef GL_NV_fragment_program4_1
#define GL_NV_fragment_program4_1         1
#endif
#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#endif
#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4           1
#endif
#ifndef GL_NV_geometry_program4_1
#define GL_NV_geometry_program4_1         1
#endif
#ifndef GL_NV_geometry_shader4
#define GL_NV_geometry_shader4            1
#endif
#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4                1
#endif
#ifndef GL_NV_gpu_program4_1
#define GL_NV_gpu_program4_1              1
#endif
#ifndef GL_NV_half_float
#define GL_NV_half_float                  1
#endif
#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent          1
#endif
#ifndef GL_NV_mac_get_proc_address
#define GL_NV_mac_get_proc_address        1
#endif
#ifndef GL_NV_multisample_coverage
#define GL_NV_multisample_coverage        1
#endif
#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint     1
#endif
#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query             1
#endif
#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil        1
#endif
#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object     1
#endif
#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range            1
#endif
#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite                1
#endif
#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart           1
#endif
#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners          1
#endif
#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2         1
#endif
#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection           1
#endif
#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc     1
#endif
#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4        1
#endif
#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal       1
#endif
#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle           1
#endif
#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader              1
#endif
#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2             1
#endif
#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3             1
#endif
#ifndef GL_NV_texture_cube_map_array
#define GL_NV_texture_cube_map_array      1
#endif
#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback          1
#endif
#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2         1
#endif
#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range          1
#endif
#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2         1
#endif
#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program              1
#endif
#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1           1
#endif
#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2             1
#endif
#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3             1
#endif
#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4             1
#endif
#ifndef GL_NV_vertex_program4_1
#define GL_NV_vertex_program4_1           1
#endif
#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render         1
#endif
#ifndef GL_NVX_gpu_sync_buffer
#define GL_NVX_gpu_sync_buffer            1
#endif
#ifndef GL_NVX_volatile_texture
#define GL_NVX_volatile_texture           1
#endif
#ifndef GL_S3_s3tc
#define GL_S3_s3tc                        1
#endif
#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap           1
#endif
#ifndef GL_SGIS_multitexture
#define GL_SGIS_multitexture              1
#endif
#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod               1
#endif
#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture             1
#endif
#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow                    1
#endif
#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum                1
#endif
#ifndef GL_WIN_swap_hint
#define GL_WIN_swap_hint                  1
#endif

/* PixelFormat */
/*      GL_BGR_EXT */
/*      GL_BGRA_EXT */

/* GetPName */
/*      GL_ARRAY_ELEMENT_LOCK_COUNT_EXT */
/*      GL_ARRAY_ELEMENT_LOCK_FIRST_EXT */

/* GetColorTableParameterPNameEXT */
/*      GL_COLOR_TABLE_FORMAT_EXT */
/*      GL_COLOR_TABLE_WIDTH_EXT */
/*      GL_COLOR_TABLE_RED_SIZE_EXT */
/*      GL_COLOR_TABLE_GREEN_SIZE_EXT */
/*      GL_COLOR_TABLE_BLUE_SIZE_EXT */
/*      GL_COLOR_TABLE_ALPHA_SIZE_EXT */
/*      GL_COLOR_TABLE_LUMINANCE_SIZE_EXT */
/*      GL_COLOR_TABLE_INTENSITY_SIZE_EXT */

/* PixelInternalFormat */
/*      GL_COLOR_INDEX1_EXT */
/*      GL_COLOR_INDEX2_EXT */
/*      GL_COLOR_INDEX4_EXT */
/*      GL_COLOR_INDEX8_EXT */
/*      GL_COLOR_INDEX12_EXT */
/*      GL_COLOR_INDEX16_EXT */

/* OpenGL12 */
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_RESCALE_NORMAL                 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL      0x81F8
#define GL_SINGLE_COLOR                   0x81F9
#define GL_SEPARATE_SPECULAR_COLOR        0x81FA
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_ALIASED_POINT_SIZE_RANGE       0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E

/* OpenGL13 */
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1
#define GL_MAX_TEXTURE_UNITS              0x84E2
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMBINE                        0x8570
#define GL_COMBINE_RGB                    0x8571
#define GL_COMBINE_ALPHA                  0x8572
#define GL_RGB_SCALE                      0x8573
#define GL_ADD_SIGNED                     0x8574
#define GL_INTERPOLATE                    0x8575
#define GL_CONSTANT                       0x8576
#define GL_PRIMARY_COLOR                  0x8577
#define GL_PREVIOUS                       0x8578
#define GL_SOURCE0_RGB                    0x8580
#define GL_SOURCE1_RGB                    0x8581
#define GL_SOURCE2_RGB                    0x8582
#define GL_SOURCE0_ALPHA                  0x8588
#define GL_SOURCE1_ALPHA                  0x8589
#define GL_SOURCE2_ALPHA                  0x858A
#define GL_OPERAND0_RGB                   0x8590
#define GL_OPERAND1_RGB                   0x8591
#define GL_OPERAND2_RGB                   0x8592
#define GL_OPERAND0_ALPHA                 0x8598
#define GL_OPERAND1_ALPHA                 0x8599
#define GL_OPERAND2_ALPHA                 0x859A
#define GL_SUBTRACT                       0x84E7
#define GL_TRANSPOSE_MODELVIEW_MATRIX     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX         0x84E6
#define GL_COMPRESSED_ALPHA               0x84E9
#define GL_COMPRESSED_LUMINANCE           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA     0x84EB
#define GL_COMPRESSED_INTENSITY           0x84EC
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_DOT3_RGB                       0x86AE
#define GL_DOT3_RGBA                      0x86AF
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_MULTISAMPLE_BIT                0x20000000

/* EXT_bgra */
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1

/* EXT_blend_color */
#define GL_CONSTANT_COLOR_EXT             0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT   0x8002
#define GL_CONSTANT_ALPHA_EXT             0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT   0x8004
#define GL_BLEND_COLOR_EXT                0x8005

/* EXT_blend_minmax */
#define GL_FUNC_ADD_EXT                   0x8006
#define GL_MIN_EXT                        0x8007
#define GL_MAX_EXT                        0x8008
#define GL_BLEND_EQUATION_EXT             0x8009

/* EXT_color_table */
#define GL_TABLE_TOO_LARGE_EXT            0x8031
#define GL_COLOR_TABLE_FORMAT_EXT         0x80D8
#define GL_COLOR_TABLE_WIDTH_EXT          0x80D9
#define GL_COLOR_TABLE_RED_SIZE_EXT       0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_EXT     0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_EXT      0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_EXT     0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_EXT 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_EXT 0x80DF

/* EXT_paletted_texture */
#define GL_COLOR_INDEX1_EXT               0x80E2
#define GL_COLOR_INDEX2_EXT               0x80E3
#define GL_COLOR_INDEX4_EXT               0x80E4
#define GL_COLOR_INDEX8_EXT               0x80E5
#define GL_COLOR_INDEX12_EXT              0x80E6
#define GL_COLOR_INDEX16_EXT              0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT         0x80ED

/* EXT_texture3D */
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_SKIP_IMAGES_EXT           0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_PACK_IMAGE_HEIGHT_EXT          0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_SKIP_IMAGES_EXT         0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_UNPACK_IMAGE_HEIGHT_EXT        0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_TEXTURE_3D_EXT                 0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_PROXY_TEXTURE_3D_EXT           0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_DEPTH_EXT              0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_TEXTURE_WRAP_R_EXT             0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_MAX_3D_TEXTURE_SIZE_EXT        0x8073

/* EXT_vertex_array */
#define GL_VERTEX_ARRAY_EXT               0x8074
#define GL_NORMAL_ARRAY_EXT               0x8075
#define GL_COLOR_ARRAY_EXT                0x8076
#define GL_INDEX_ARRAY_EXT                0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT        0x8078
#define GL_EDGE_FLAG_ARRAY_EXT            0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT          0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT          0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT        0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT         0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT          0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT        0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT         0x8080
#define GL_COLOR_ARRAY_SIZE_EXT           0x8081
#define GL_COLOR_ARRAY_TYPE_EXT           0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT         0x8083
#define GL_COLOR_ARRAY_COUNT_EXT          0x8084
#define GL_INDEX_ARRAY_TYPE_EXT           0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT         0x8086
#define GL_INDEX_ARRAY_COUNT_EXT          0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT   0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT   0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT  0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT     0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT      0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT       0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT       0x808F
#define GL_COLOR_ARRAY_POINTER_EXT        0x8090
#define GL_INDEX_ARRAY_POINTER_EXT        0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT    0x8093

/* ARB_imaging */
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_BLEND_COLOR                    0x8005
#define GL_FUNC_ADD                       0x8006
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_BLEND_EQUATION                 0x8009
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_COLOR_MATRIX                   0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH       0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH   0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE    0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE  0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE   0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE  0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS     0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS   0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS    0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS   0x80BB
#define GL_COLOR_TABLE                    0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE   0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE  0x80D2
#define GL_PROXY_COLOR_TABLE              0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE              0x80D6
#define GL_COLOR_TABLE_BIAS               0x80D7
#define GL_COLOR_TABLE_FORMAT             0x80D8
#define GL_COLOR_TABLE_WIDTH              0x80D9
#define GL_COLOR_TABLE_RED_SIZE           0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE         0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE          0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE         0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE     0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE     0x80DF
#define GL_CONVOLUTION_1D                 0x8010
#define GL_CONVOLUTION_2D                 0x8011
#define GL_SEPARABLE_2D                   0x8012
#define GL_CONVOLUTION_BORDER_MODE        0x8013
#define GL_CONVOLUTION_FILTER_SCALE       0x8014
#define GL_CONVOLUTION_FILTER_BIAS        0x8015
#define GL_REDUCE                         0x8016
#define GL_CONVOLUTION_FORMAT             0x8017
#define GL_CONVOLUTION_WIDTH              0x8018
#define GL_CONVOLUTION_HEIGHT             0x8019
#define GL_MAX_CONVOLUTION_WIDTH          0x801A
#define GL_MAX_CONVOLUTION_HEIGHT         0x801B
#define GL_POST_CONVOLUTION_RED_SCALE     0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE   0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE    0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE   0x801F
#define GL_POST_CONVOLUTION_RED_BIAS      0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS    0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS     0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS    0x8023
#define GL_IGNORE_BORDER                  0x8150
#define GL_CONSTANT_BORDER                0x8151
#define GL_REPLICATE_BORDER               0x8153
#define GL_CONVOLUTION_BORDER_COLOR       0x8154
#define GL_HISTOGRAM                      0x8024
#define GL_PROXY_HISTOGRAM                0x8025
#define GL_HISTOGRAM_WIDTH                0x8026
#define GL_HISTOGRAM_FORMAT               0x8027
#define GL_HISTOGRAM_RED_SIZE             0x8028
#define GL_HISTOGRAM_GREEN_SIZE           0x8029
#define GL_HISTOGRAM_BLUE_SIZE            0x802A
#define GL_HISTOGRAM_ALPHA_SIZE           0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE       0x802C
#define GL_HISTOGRAM_SINK                 0x802D
#define GL_MINMAX                         0x802E
#define GL_MINMAX_FORMAT                  0x802F
#define GL_MINMAX_SINK                    0x8030

/* EXT_clip_volume_hint */
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT  0x80F0

/* EXT_point_parameters */
#define GL_POINT_SIZE_MIN_EXT             0x8126
#define GL_POINT_SIZE_MAX_EXT             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT  0x8128
#define GL_DISTANCE_ATTENUATION_EXT       0x8129

/* EXT_compiled_vertex_array */
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT   0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT   0x81A9

/* SGIS_multitexture */
#define GL_SELECTED_TEXTURE_SGIS          0x835C
#define GL_MAX_TEXTURES_SGIS              0x835D
#define GL_TEXTURE0_SGIS                  0x835E
#define GL_TEXTURE1_SGIS                  0x835F
#define GL_TEXTURE2_SGIS                  0x8360
#define GL_TEXTURE3_SGIS                  0x8361

/* ARB_multitexture */
#define GL_ACTIVE_TEXTURE_ARB             0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB      0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB          0x84E2
#define GL_TEXTURE0_ARB                   0x84C0
#define GL_TEXTURE1_ARB                   0x84C1
#define GL_TEXTURE2_ARB                   0x84C2
#define GL_TEXTURE3_ARB                   0x84C3
#define GL_TEXTURE4_ARB                   0x84C4
#define GL_TEXTURE5_ARB                   0x84C5
#define GL_TEXTURE6_ARB                   0x84C6
#define GL_TEXTURE7_ARB                   0x84C7
#define GL_TEXTURE8_ARB                   0x84C8
#define GL_TEXTURE9_ARB                   0x84C9
#define GL_TEXTURE10_ARB                  0x84CA
#define GL_TEXTURE11_ARB                  0x84CB
#define GL_TEXTURE12_ARB                  0x84CC
#define GL_TEXTURE13_ARB                  0x84CD
#define GL_TEXTURE14_ARB                  0x84CE
#define GL_TEXTURE15_ARB                  0x84CF
#define GL_TEXTURE16_ARB                  0x84D0
#define GL_TEXTURE17_ARB                  0x84D1
#define GL_TEXTURE18_ARB                  0x84D2
#define GL_TEXTURE19_ARB                  0x84D3
#define GL_TEXTURE20_ARB                  0x84D4
#define GL_TEXTURE21_ARB                  0x84D5
#define GL_TEXTURE22_ARB                  0x84D6
#define GL_TEXTURE23_ARB                  0x84D7
#define GL_TEXTURE24_ARB                  0x84D8
#define GL_TEXTURE25_ARB                  0x84D9
#define GL_TEXTURE26_ARB                  0x84DA
#define GL_TEXTURE27_ARB                  0x84DB
#define GL_TEXTURE28_ARB                  0x84DC
#define GL_TEXTURE29_ARB                  0x84DD
#define GL_TEXTURE30_ARB                  0x84DE
#define GL_TEXTURE31_ARB                  0x84DF

/* EXT_fog_coord */
#define GL_FOG_COORDINATE_SOURCE_EXT      0x8450
#define GL_FOG_COORDINATE_EXT             0x8451
#define GL_FRAGMENT_DEPTH_EXT             0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT     0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT  0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT       0x8457

/* EXT_secondary_color */
#define GL_COLOR_SUM_EXT                  0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT    0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT      0x845E

/* EXT_separate_specular_color */
#define GL_SINGLE_COLOR_EXT               0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT    0x81FA
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT  0x81F8

/* EXT_stencil_wrap */
#define GL_INCR_WRAP_EXT                  0x8507
#define GL_DECR_WRAP_EXT                  0x8508

/* NV_texgen_reflection */
#define GL_NORMAL_MAP_NV                  0x8511
#define GL_REFLECTION_MAP_NV              0x8512

/* EXT_texture_cube_map */
#define GL_NORMAL_MAP_EXT                 0x8511
#define GL_REFLECTION_MAP_EXT             0x8512
#define GL_TEXTURE_CUBE_MAP_EXT           0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT   0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT     0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT  0x851C

/* ARB_texture_cube_map */
#define GL_NORMAL_MAP_ARB                 0x8511
#define GL_REFLECTION_MAP_ARB             0x8512
#define GL_TEXTURE_CUBE_MAP_ARB           0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB   0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB     0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB  0x851C

/* NV_vertex_array_range */
#define GL_VERTEX_ARRAY_RANGE_NV          0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV   0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV    0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV  0x8521

/* NV_vertex_array_range2 */
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533

/* NV_register_combiners */
#define GL_REGISTER_COMBINERS_NV          0x8522
#define GL_COMBINER0_NV                   0x8550
#define GL_COMBINER1_NV                   0x8551
#define GL_COMBINER2_NV                   0x8552
#define GL_COMBINER3_NV                   0x8553
#define GL_COMBINER4_NV                   0x8554
#define GL_COMBINER5_NV                   0x8555
#define GL_COMBINER6_NV                   0x8556
#define GL_COMBINER7_NV                   0x8557
#define GL_VARIABLE_A_NV                  0x8523
#define GL_VARIABLE_B_NV                  0x8524
#define GL_VARIABLE_C_NV                  0x8525
#define GL_VARIABLE_D_NV                  0x8526
#define GL_VARIABLE_E_NV                  0x8527
#define GL_VARIABLE_F_NV                  0x8528
#define GL_VARIABLE_G_NV                  0x8529
#define GL_CONSTANT_COLOR0_NV             0x852A
#define GL_CONSTANT_COLOR1_NV             0x852B
#define GL_PRIMARY_COLOR_NV               0x852C
#define GL_SECONDARY_COLOR_NV             0x852D
#define GL_SPARE0_NV                      0x852E
#define GL_SPARE1_NV                      0x852F
/*      GL_TEXTURE0_ARB */
/*      GL_TEXTURE1_ARB */
#define GL_UNSIGNED_IDENTITY_NV           0x8536
#define GL_UNSIGNED_INVERT_NV             0x8537
#define GL_EXPAND_NORMAL_NV               0x8538
#define GL_EXPAND_NEGATE_NV               0x8539
#define GL_HALF_BIAS_NORMAL_NV            0x853A
#define GL_HALF_BIAS_NEGATE_NV            0x853B
#define GL_SIGNED_IDENTITY_NV             0x853C
#define GL_SIGNED_NEGATE_NV               0x853D
#define GL_E_TIMES_F_NV                   0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_SCALE_BY_TWO_NV                0x853E
#define GL_SCALE_BY_FOUR_NV               0x853F
#define GL_SCALE_BY_ONE_HALF_NV           0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV   0x8541
#define GL_DISCARD_NV                     0x8530
#define GL_COMBINER_INPUT_NV              0x8542
#define GL_COMBINER_MAPPING_NV            0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV    0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV     0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV     0x8546
#define GL_COMBINER_MUX_SUM_NV            0x8547
#define GL_COMBINER_SCALE_NV              0x8548
#define GL_COMBINER_BIAS_NV               0x8549
#define GL_COMBINER_AB_OUTPUT_NV          0x854A
#define GL_COMBINER_CD_OUTPUT_NV          0x854B
#define GL_COMBINER_SUM_OUTPUT_NV         0x854C
#define GL_MAX_GENERAL_COMBINERS_NV       0x854D
#define GL_NUM_GENERAL_COMBINERS_NV       0x854E
#define GL_COLOR_SUM_CLAMP_NV             0x854F

/* NV_fog_distance */
#define GL_FOG_DISTANCE_MODE_NV           0x855A
#define GL_EYE_RADIAL_NV                  0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV          0x855C

/* NV_fragment_program */
#define GL_FRAGMENT_PROGRAM_NV            0x8870
#define GL_MAX_TEXTURE_COORDS_NV          0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV     0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV    0x8873
#define GL_PROGRAM_ERROR_STRING_NV        0x8874
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868

/* NV_light_max_exponent */
#define GL_MAX_SHININESS_NV               0x8504
#define GL_MAX_SPOT_EXPONENT_NV           0x8505

/* ARB_texture_env_combine */
#define GL_COMBINE_ARB                    0x8570
#define GL_COMBINE_RGB_ARB                0x8571
#define GL_COMBINE_ALPHA_ARB              0x8572
#define GL_RGB_SCALE_ARB                  0x8573
#define GL_ADD_SIGNED_ARB                 0x8574
#define GL_INTERPOLATE_ARB                0x8575
#define GL_CONSTANT_ARB                   0x8576
#define GL_PRIMARY_COLOR_ARB              0x8577
#define GL_PREVIOUS_ARB                   0x8578
#define GL_SOURCE0_RGB_ARB                0x8580
#define GL_SOURCE1_RGB_ARB                0x8581
#define GL_SOURCE2_RGB_ARB                0x8582
#define GL_SOURCE0_ALPHA_ARB              0x8588
#define GL_SOURCE1_ALPHA_ARB              0x8589
#define GL_SOURCE2_ALPHA_ARB              0x858A
#define GL_OPERAND0_RGB_ARB               0x8590
#define GL_OPERAND1_RGB_ARB               0x8591
#define GL_OPERAND2_RGB_ARB               0x8592
#define GL_OPERAND0_ALPHA_ARB             0x8598
#define GL_OPERAND1_ALPHA_ARB             0x8599
#define GL_OPERAND2_ALPHA_ARB             0x859A
#define GL_SUBTRACT_ARB                   0x84E7

/* EXT_texture_env_combine */
#define GL_COMBINE_EXT                    0x8570
#define GL_COMBINE_RGB_EXT                0x8571
#define GL_COMBINE_ALPHA_EXT              0x8572
#define GL_RGB_SCALE_EXT                  0x8573
#define GL_ADD_SIGNED_EXT                 0x8574
#define GL_INTERPOLATE_EXT                0x8575
#define GL_CONSTANT_EXT                   0x8576
#define GL_PRIMARY_COLOR_EXT              0x8577
#define GL_PREVIOUS_EXT                   0x8578
#define GL_SOURCE0_RGB_EXT                0x8580
#define GL_SOURCE1_RGB_EXT                0x8581
#define GL_SOURCE2_RGB_EXT                0x8582
#define GL_SOURCE0_ALPHA_EXT              0x8588
#define GL_SOURCE1_ALPHA_EXT              0x8589
#define GL_SOURCE2_ALPHA_EXT              0x858A
#define GL_OPERAND0_RGB_EXT               0x8590
#define GL_OPERAND1_RGB_EXT               0x8591
#define GL_OPERAND2_RGB_EXT               0x8592
#define GL_OPERAND0_ALPHA_EXT             0x8598
#define GL_OPERAND1_ALPHA_EXT             0x8599
#define GL_OPERAND2_ALPHA_EXT             0x859A

/* NV_texture_env_combine4 */
#define GL_COMBINE4_NV                    0x8503
#define GL_SOURCE3_RGB_NV                 0x8583
#define GL_SOURCE3_ALPHA_NV               0x858B
#define GL_OPERAND3_RGB_NV                0x8593
#define GL_OPERAND3_ALPHA_NV              0x859B

/* SUN_slice_accum */
#define GL_SLICE_ACCUM_SUN                0x85CC

/* EXT_texture_filter_anisotropic */
#define GL_TEXTURE_MAX_ANISOTROPY_EXT     0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

/* EXT_texture_lod_bias */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
#define GL_TEXTURE_LOD_BIAS_EXT           0x8501

/* EXT_texture_edge_clamp */
#define GL_CLAMP_TO_EDGE_EXT              0x812F

/* S3_s3tc */
#define GL_RGB_S3TC                       0x83A0
#define GL_RGB4_S3TC                      0x83A1
#define GL_RGBA_S3TC                      0x83A2
#define GL_RGBA4_S3TC                     0x83A3
#define GL_RGBA_DXT5_S3TC                 0x83A4
#define GL_RGBA4_DXT5_S3TC                0x83A5

/* ARB_transpose_matrix */
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB   0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB     0x84E6

/* ARB_texture_compression */
#define GL_COMPRESSED_ALPHA_ARB           0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB       0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB       0x84EC
#define GL_COMPRESSED_RGB_ARB             0x84ED
#define GL_COMPRESSED_RGBA_ARB            0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB   0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB         0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3

/* EXT_texture_compression_s3tc */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3

/* EXT_texture_compression_latc */
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73

/* EXT_texture_compression_rgtc */
#define GL_COMPRESSED_RED_RGTC1_EXT       0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE

/* NV_fence */
#define GL_ALL_COMPLETED_NV               0x84F2
#define GL_FENCE_STATUS_NV                0x84F3
#define GL_FENCE_CONDITION_NV             0x84F4

/* NV_mac_get_proc_address */
#define GL_ALL_EXTENSIONS_NV              0x84FB
#define GL_MAC_GET_PROC_ADDRESS_NV        0x84FC

/* NV_vertex_program */
#define GL_VERTEX_PROGRAM_NV              0x8620
#define GL_VERTEX_STATE_PROGRAM_NV        0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV           0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV         0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV           0x8625
#define GL_CURRENT_ATTRIB_NV              0x8626
#define GL_PROGRAM_LENGTH_NV              0x8627
#define GL_PROGRAM_STRING_NV              0x8628
#define GL_MODELVIEW_PROJECTION_NV        0x8629
#define GL_IDENTITY_NV                    0x862A
#define GL_INVERSE_NV                     0x862B
#define GL_TRANSPOSE_NV                   0x862C
#define GL_INVERSE_TRANSPOSE_NV           0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MAX_TRACK_MATRICES_NV          0x862F
#define GL_MATRIX0_NV                     0x8630
#define GL_MATRIX1_NV                     0x8631
#define GL_MATRIX2_NV                     0x8632
#define GL_MATRIX3_NV                     0x8633
#define GL_MATRIX4_NV                     0x8634
#define GL_MATRIX5_NV                     0x8635
#define GL_MATRIX6_NV                     0x8636
#define GL_MATRIX7_NV                     0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV  0x8640
#define GL_CURRENT_MATRIX_NV              0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV   0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV     0x8643
#define GL_PROGRAM_PARAMETER_NV           0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV        0x8645
#define GL_PROGRAM_TARGET_NV              0x8646
#define GL_PROGRAM_RESIDENT_NV            0x8647
#define GL_TRACK_MATRIX_NV                0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV      0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV      0x864A
#define GL_PROGRAM_ERROR_POSITION_NV      0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV        0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV        0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV        0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV        0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV        0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV        0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV        0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV        0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV        0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV        0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV       0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV       0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV       0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV       0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV       0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV       0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV       0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV       0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV       0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV       0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV       0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV       0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV       0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV       0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV       0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV       0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV      0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV      0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV      0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV      0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV      0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV      0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV       0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV       0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV       0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV       0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV       0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV       0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV       0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV       0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV       0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV       0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV      0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV      0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV      0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV      0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV      0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV      0x867F

/* NV_texture_shader */
#define GL_OFFSET_TEXTURE_RECTANGLE_NV    0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV      0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV  0x86DB
#define GL_DSDT_MAG_INTENSITY_NV          0x86DC
#define GL_SHADER_CONSISTENT_NV           0x86DD
#define GL_TEXTURE_SHADER_NV              0x86DE
#define GL_SHADER_OPERATION_NV            0x86DF
#define GL_CULL_MODES_NV                  0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV       0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV        0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV         0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV    GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV     GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV      GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV      0x86E4
#define GL_CONST_EYE_NV                   0x86E5
#define GL_PASS_THROUGH_NV                0x86E6
#define GL_CULL_FRAGMENT_NV               0x86E7
#define GL_OFFSET_TEXTURE_2D_NV           0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV     0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV     0x86EA
#define GL_DOT_PRODUCT_NV                 0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV   0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV      0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_HILO_NV                        0x86F4
#define GL_DSDT_NV                        0x86F5
#define GL_DSDT_MAG_NV                    0x86F6
#define GL_DSDT_MAG_VIB_NV                0x86F7
#define GL_HILO16_NV                      0x86F8
#define GL_SIGNED_HILO_NV                 0x86F9
#define GL_SIGNED_HILO16_NV               0x86FA
#define GL_SIGNED_RGBA_NV                 0x86FB
#define GL_SIGNED_RGBA8_NV                0x86FC
#define GL_SIGNED_RGB_NV                  0x86FE
#define GL_SIGNED_RGB8_NV                 0x86FF
#define GL_SIGNED_LUMINANCE_NV            0x8701
#define GL_SIGNED_LUMINANCE8_NV           0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV      0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV    0x8704
#define GL_SIGNED_ALPHA_NV                0x8705
#define GL_SIGNED_ALPHA8_NV               0x8706
#define GL_SIGNED_INTENSITY_NV            0x8707
#define GL_SIGNED_INTENSITY8_NV           0x8708
#define GL_DSDT8_NV                       0x8709
#define GL_DSDT8_MAG8_NV                  0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV       0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV   0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_HI_SCALE_NV                    0x870E
#define GL_LO_SCALE_NV                    0x870F
#define GL_DS_SCALE_NV                    0x8710
#define GL_DT_SCALE_NV                    0x8711
#define GL_MAGNITUDE_SCALE_NV             0x8712
#define GL_VIBRANCE_SCALE_NV              0x8713
#define GL_HI_BIAS_NV                     0x8714
#define GL_LO_BIAS_NV                     0x8715
#define GL_DS_BIAS_NV                     0x8716
#define GL_DT_BIAS_NV                     0x8717
#define GL_MAGNITUDE_BIAS_NV              0x8718
#define GL_VIBRANCE_BIAS_NV               0x8719
#define GL_TEXTURE_BORDER_VALUES_NV       0x871A
#define GL_TEXTURE_HI_SIZE_NV             0x871B
#define GL_TEXTURE_LO_SIZE_NV             0x871C
#define GL_TEXTURE_DS_SIZE_NV             0x871D
#define GL_TEXTURE_DT_SIZE_NV             0x871E
#define GL_TEXTURE_MAG_SIZE_NV            0x871F

/* NV_texture_shader2 */
#define GL_DOT_PRODUCT_TEXTURE_3D_NV      0x86EF

/* NV_texture_shader3 */
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV      0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV   0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV    0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV    0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV      0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_HILO8_NV                       0x885E
#define GL_SIGNED_HILO8_NV                0x885F
#define GL_FORCE_BLUE_TO_ONE_NV           0x8860

/* NV_register_combiners2 */
#define GL_PER_STAGE_CONSTANTS_NV         0x8535

/* IBM_texture_mirrored_repeat */
#define GL_MIRRORED_REPEAT_IBM            0x8370

/* ARB_texture_env_dot3 */
#define GL_DOT3_RGB_ARB                   0x86AE
#define GL_DOT3_RGBA_ARB                  0x86AF

/* EXT_texture_env_dot3 */
#define GL_DOT3_RGB_EXT                   0x8740
#define GL_DOT3_RGBA_EXT                  0x8741

/* APPLE_transform_hint */
#define GL_TRANSFORM_HINT_APPLE           0x85B1

/* ARB_texture_border_clamp */
#define GL_CLAMP_TO_BORDER_ARB            0x812D

/* NV_texture_rectangle */
#define GL_TEXTURE_RECTANGLE_NV           0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV   0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV     0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV  0x84F8

/* ARB_texture_rectangle */
#define GL_TEXTURE_RECTANGLE_ARB          0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB  0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB    0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8

/* ARB_multisample */
#define GL_MULTISAMPLE_ARB                0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB   0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB        0x809F
#define GL_SAMPLE_COVERAGE_ARB            0x80A0
#define GL_SAMPLE_BUFFERS_ARB             0x80A8
#define GL_SAMPLES_ARB                    0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB      0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB     0x80AB
#define GL_MULTISAMPLE_BIT_ARB            0x20000000

/* NV_multisample_filter_hint */
#define GL_MULTISAMPLE_FILTER_HINT_NV     0x8534

/* NV_packed_depth_stencil */
#define GL_DEPTH_STENCIL_NV               0x84F9
#define GL_UNSIGNED_INT_24_8_NV           0x84FA

/* EXT_packed_depth_stencil */
#define GL_DEPTH_STENCIL_EXT              0x84F9
#define GL_DEPTH24_STENCIL8_EXT           0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT       0x88F1
#define GL_UNSIGNED_INT_24_8_EXT          0x84FA

/* EXT_draw_range_elements */
#define GL_MAX_ELEMENTS_VERTICES_EXT      0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT       0x80E9

/* NV_pixel_data_range */
#define GL_WRITE_PIXEL_DATA_RANGE_NV      0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV       0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D

/* NV_packed_normal */
#define GL_UNSIGNED_INT_S10_S11_S11_REV_NV 0x886B

/* NV_half_float */
#define GL_HALF_FLOAT_NV                  0x140B

/* NV_copy_depth_to_color */
#define GL_DEPTH_STENCIL_TO_RGBA_NV       0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV       0x886F

/* HP_occlusion_test */
#define GL_OCCLUSION_TEST_HP              0x8165
#define GL_OCCLUSION_TEST_RESULT_HP       0x8166

/* NV_occlusion_query */
#define GL_PIXEL_COUNTER_BITS_NV          0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV  0x8865
#define GL_PIXEL_COUNT_NV                 0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV       0x8867

/* ARB_occlusion_query */
#define GL_QUERY_COUNTER_BITS_ARB         0x8864
#define GL_CURRENT_QUERY_ARB              0x8865
#define GL_QUERY_RESULT_ARB               0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB     0x8867
#define GL_SAMPLES_PASSED_ARB             0x8914

/* ARB_point_sprite */
#define GL_POINT_SPRITE_ARB               0x8861
#define GL_COORD_REPLACE_ARB              0x8862

/* NV_point_sprite */
#define GL_POINT_SPRITE_NV                0x8861
#define GL_COORD_REPLACE_NV               0x8862
#define GL_POINT_SPRITE_R_MODE_NV         0x8863

/* 3DFX_tbuffer */
#define GL_TBUFFER_WRITE_MASK_3DFX        0x86D8

/* NV_depth_clamp */
#define GL_DEPTH_CLAMP_NV                 0x864F

/* NV_float_buffer */
#define GL_FLOAT_R_NV                     0x8880
#define GL_FLOAT_RG_NV                    0x8881
#define GL_FLOAT_RGB_NV                   0x8882
#define GL_FLOAT_RGBA_NV                  0x8883
#define GL_FLOAT_R16_NV                   0x8884
#define GL_FLOAT_R32_NV                   0x8885
#define GL_FLOAT_RG16_NV                  0x8886
#define GL_FLOAT_RG32_NV                  0x8887
#define GL_FLOAT_RGB16_NV                 0x8888
#define GL_FLOAT_RGB32_NV                 0x8889
#define GL_FLOAT_RGBA16_NV                0x888A
#define GL_FLOAT_RGBA32_NV                0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV    0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV     0x888D
#define GL_FLOAT_RGBA_MODE_NV             0x888E

/* EXT_stencil_two_side */
#define GL_STENCIL_TEST_TWO_SIDE_EXT      0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT        0x8911

/* EXT_blend_func_separate */
#define GL_BLEND_DST_RGB_EXT              0x80C8
#define GL_BLEND_SRC_RGB_EXT              0x80C9
#define GL_BLEND_DST_ALPHA_EXT            0x80CA
#define GL_BLEND_SRC_ALPHA_EXT            0x80CB

/* ARB_texture_mirrored_repeat */
#define GL_MIRRORED_REPEAT_ARB            0x8370

/* ARB_depth_texture */
#define GL_DEPTH_COMPONENT16_ARB          0x81A5
#define GL_DEPTH_COMPONENT24_ARB          0x81A6
#define GL_DEPTH_COMPONENT32_ARB          0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB         0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB         0x884B

/* ARB_shadow */
#define GL_TEXTURE_COMPARE_MODE_ARB       0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB       0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB       0x884E

/* ARB_shadow_ambient */
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF

/* NV_force_software */
#define GL_FORCE_SOFTWARE_NV              0x6007

/* ARB_point_parameters */
#define GL_POINT_SIZE_MIN_ARB             0x8126
#define GL_POINT_SIZE_MAX_ARB             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB  0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129

/* EXT_depth_bounds_test */
#define GL_DEPTH_BOUNDS_TEST_EXT          0x8890
#define GL_DEPTH_BOUNDS_EXT               0x8891

/* ARB_vertex_program */
#define GL_VERTEX_PROGRAM_ARB             0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB  0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB    0x8643
#define GL_COLOR_SUM_ARB                  0x8458
#define GL_PROGRAM_FORMAT_ASCII_ARB       0x8875
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB   0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB   0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_CURRENT_VERTEX_ATTRIB_ARB      0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_PROGRAM_LENGTH_ARB             0x8627
#define GL_PROGRAM_FORMAT_ARB             0x8876
#define GL_PROGRAM_BINDING_ARB            0x8677
#define GL_PROGRAM_INSTRUCTIONS_ARB       0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB   0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB        0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB    0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB         0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB     0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB  0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB            0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB        0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB     0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB  0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_PROGRAM_STRING_ARB             0x8628
#define GL_PROGRAM_ERROR_POSITION_ARB     0x864B
#define GL_CURRENT_MATRIX_ARB             0x8641
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB   0x88B7
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_MAX_VERTEX_ATTRIBS_ARB         0x8869
#define GL_MAX_PROGRAM_MATRICES_ARB       0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_PROGRAM_ERROR_STRING_ARB       0x8874
#define GL_MATRIX0_ARB                    0x88C0
#define GL_MATRIX1_ARB                    0x88C1
#define GL_MATRIX2_ARB                    0x88C2
#define GL_MATRIX3_ARB                    0x88C3
#define GL_MATRIX4_ARB                    0x88C4
#define GL_MATRIX5_ARB                    0x88C5
#define GL_MATRIX6_ARB                    0x88C6
#define GL_MATRIX7_ARB                    0x88C7
#define GL_MATRIX8_ARB                    0x88C8
#define GL_MATRIX9_ARB                    0x88C9
#define GL_MATRIX10_ARB                   0x88CA
#define GL_MATRIX11_ARB                   0x88CB
#define GL_MATRIX12_ARB                   0x88CC
#define GL_MATRIX13_ARB                   0x88CD
#define GL_MATRIX14_ARB                   0x88CE
#define GL_MATRIX15_ARB                   0x88CF
#define GL_MATRIX16_ARB                   0x88D0
#define GL_MATRIX17_ARB                   0x88D1
#define GL_MATRIX18_ARB                   0x88D2
#define GL_MATRIX19_ARB                   0x88D3
#define GL_MATRIX20_ARB                   0x88D4
#define GL_MATRIX21_ARB                   0x88D5
#define GL_MATRIX22_ARB                   0x88D6
#define GL_MATRIX23_ARB                   0x88D7
#define GL_MATRIX24_ARB                   0x88D8
#define GL_MATRIX25_ARB                   0x88D9
#define GL_MATRIX26_ARB                   0x88DA
#define GL_MATRIX27_ARB                   0x88DB
#define GL_MATRIX28_ARB                   0x88DC
#define GL_MATRIX29_ARB                   0x88DD
#define GL_MATRIX30_ARB                   0x88DE
#define GL_MATRIX31_ARB                   0x88DF

/* OpenGL14 */
#define GL_POINT_SIZE_MIN                 0x8126
#define GL_POINT_SIZE_MAX                 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_POINT_DISTANCE_ATTENUATION     0x8129
#define GL_FOG_COORDINATE_SOURCE          0x8450
#define GL_FOG_COORDINATE                 0x8451
#define GL_FRAGMENT_DEPTH                 0x8452
#define GL_CURRENT_FOG_COORDINATE         0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE      0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE    0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER   0x8456
#define GL_FOG_COORDINATE_ARRAY           0x8457
#define GL_COLOR_SUM                      0x8458
#define GL_CURRENT_SECONDARY_COLOR        0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE     0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE     0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE   0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER  0x845D
#define GL_SECONDARY_COLOR_ARRAY          0x845E
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_FILTER_CONTROL         0x8500
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_GENERATE_MIPMAP_SGIS           0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS      0x8192
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_MIRRORED_REPEAT                0x8370
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_DEPTH_TEXTURE_MODE             0x884B
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_COMPARE_R_TO_TEXTURE           0x884E

/* NV_primitive_restart */
#define GL_PRIMITIVE_RESTART_NV           0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV     0x8559

/* SGIS_texture_color_mask */
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS   0x81EF

/* NV_texture_expand_normal */
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F

/* ARB_fragment_program */
#define GL_FRAGMENT_PROGRAM_ARB           0x8804
/*      GL_PROGRAM_FORMAT_ASCII_ARB */
/*      GL_PROGRAM_LENGTH_ARB */
/*      GL_PROGRAM_FORMAT_ARB */
/*      GL_PROGRAM_BINDING_ARB */
/*      GL_PROGRAM_INSTRUCTIONS_ARB */
/*      GL_MAX_PROGRAM_INSTRUCTIONS_ARB */
/*      GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB */
/*      GL_PROGRAM_TEMPORARIES_ARB */
/*      GL_MAX_PROGRAM_TEMPORARIES_ARB */
/*      GL_PROGRAM_NATIVE_TEMPORARIES_ARB */
/*      GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB */
/*      GL_PROGRAM_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_PARAMETERS_ARB */
/*      GL_PROGRAM_NATIVE_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB */
/*      GL_PROGRAM_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_ATTRIBS_ARB */
/*      GL_PROGRAM_NATIVE_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB */
/*      GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB */
/*      GL_MAX_PROGRAM_ENV_PARAMETERS_ARB */
/*      GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB */
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB   0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB   0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB   0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
/*      GL_PROGRAM_STRING_ARB */
/*      GL_PROGRAM_ERROR_POSITION_ARB */
/*      GL_CURRENT_MATRIX_ARB */
/*      GL_TRANSPOSE_CURRENT_MATRIX_ARB */
/*      GL_CURRENT_MATRIX_STACK_DEPTH_ARB */
/*      GL_MAX_PROGRAM_MATRICES_ARB */
/*      GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB */
#define GL_MAX_TEXTURE_COORDS_ARB         0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB    0x8872
/*      GL_PROGRAM_ERROR_STRING_ARB */
/*      GL_MATRIX0_ARB */
/*      GL_MATRIX1_ARB */
/*      GL_MATRIX2_ARB */
/*      GL_MATRIX3_ARB */
/*      GL_MATRIX4_ARB */
/*      GL_MATRIX5_ARB */
/*      GL_MATRIX6_ARB */
/*      GL_MATRIX7_ARB */
/*      GL_MATRIX8_ARB */
/*      GL_MATRIX9_ARB */
/*      GL_MATRIX10_ARB */
/*      GL_MATRIX11_ARB */
/*      GL_MATRIX12_ARB */
/*      GL_MATRIX13_ARB */
/*      GL_MATRIX14_ARB */
/*      GL_MATRIX15_ARB */
/*      GL_MATRIX16_ARB */
/*      GL_MATRIX17_ARB */
/*      GL_MATRIX18_ARB */
/*      GL_MATRIX19_ARB */
/*      GL_MATRIX20_ARB */
/*      GL_MATRIX21_ARB */
/*      GL_MATRIX22_ARB */
/*      GL_MATRIX23_ARB */
/*      GL_MATRIX24_ARB */
/*      GL_MATRIX25_ARB */
/*      GL_MATRIX26_ARB */
/*      GL_MATRIX27_ARB */
/*      GL_MATRIX28_ARB */
/*      GL_MATRIX29_ARB */
/*      GL_MATRIX30_ARB */
/*      GL_MATRIX31_ARB */
/*      GL_PROGRAM_ERROR_STRING_ARB */
/*      GL_MATRIX0_ARB */
/*      GL_MATRIX1_ARB */
/*      GL_MATRIX2_ARB */
/*      GL_MATRIX3_ARB */
/*      GL_MATRIX4_ARB */
/*      GL_MATRIX5_ARB */
/*      GL_MATRIX6_ARB */
/*      GL_MATRIX7_ARB */
/*      GL_MATRIX8_ARB */
/*      GL_MATRIX9_ARB */
/*      GL_MATRIX10_ARB */
/*      GL_MATRIX11_ARB */
/*      GL_MATRIX12_ARB */
/*      GL_MATRIX13_ARB */
/*      GL_MATRIX14_ARB */
/*      GL_MATRIX15_ARB */
/*      GL_MATRIX16_ARB */
/*      GL_MATRIX17_ARB */
/*      GL_MATRIX18_ARB */
/*      GL_MATRIX19_ARB */
/*      GL_MATRIX20_ARB */
/*      GL_MATRIX21_ARB */
/*      GL_MATRIX22_ARB */
/*      GL_MATRIX23_ARB */
/*      GL_MATRIX24_ARB */
/*      GL_MATRIX25_ARB */
/*      GL_MATRIX26_ARB */
/*      GL_MATRIX27_ARB */
/*      GL_MATRIX28_ARB */
/*      GL_MATRIX29_ARB */
/*      GL_MATRIX30_ARB */
/*      GL_MATRIX31_ARB */

/* ARB_vertex_buffer_object */
#define GL_ARRAY_BUFFER_ARB               0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB       0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB       0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_STREAM_DRAW_ARB                0x88E0
#define GL_STREAM_READ_ARB                0x88E1
#define GL_STREAM_COPY_ARB                0x88E2
#define GL_STATIC_DRAW_ARB                0x88E4
#define GL_STATIC_READ_ARB                0x88E5
#define GL_STATIC_COPY_ARB                0x88E6
#define GL_DYNAMIC_DRAW_ARB               0x88E8
#define GL_DYNAMIC_READ_ARB               0x88E9
#define GL_DYNAMIC_COPY_ARB               0x88EA
#define GL_READ_ONLY_ARB                  0x88B8
#define GL_WRITE_ONLY_ARB                 0x88B9
#define GL_READ_WRITE_ARB                 0x88BA
#define GL_BUFFER_SIZE_ARB                0x8764
#define GL_BUFFER_USAGE_ARB               0x8765
#define GL_BUFFER_ACCESS_ARB              0x88BB
#define GL_BUFFER_MAPPED_ARB              0x88BC
#define GL_BUFFER_MAP_POINTER_ARB         0x88BD

/* EXT_pixel_buffer_object */
#define GL_PIXEL_PACK_BUFFER_EXT          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF

/* NV_transform_feedback */
#define GL_BACK_PRIMARY_COLOR_NV          0x8C77
#define GL_BACK_SECONDARY_COLOR_NV        0x8C78
#define GL_TEXTURE_COORD_NV               0x8C79
#define GL_CLIP_DISTANCE_NV               0x8C7A
#define GL_VERTEX_ID_NV                   0x8C7B
#define GL_PRIMITIVE_ID_NV                0x8C7C
#define GL_GENERIC_ATTRIB_NV              0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV  0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_ACTIVE_VARYINGS_NV             0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV   0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV   0x8C86
#define GL_PRIMITIVES_GENERATED_NV        0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_RASTERIZER_DISCARD_NV          0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV         0x8C8C
#define GL_SEPARATE_ATTRIBS_NV            0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV   0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F

/* NV_transform_feedback2 */
#define GL_TRANSFORM_FEEDBACK_NV          0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV  0x8E25

/* IBM_rasterpos_clip */
#define GL_RASTER_POSITION_UNCLIPPED_IBM  0x19262

/* ATI_texture_mirror_once */
#define GL_MIRROR_CLAMP_ATI               0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI       0x8743

/* ATI_texture_env_combine3 */
#define GL_MODULATE_ADD_ATI               0x8744
#define GL_MODULATE_SIGNED_ADD_ATI        0x8745
#define GL_MODULATE_SUBTRACT_ATI          0x8746

/* ATI_texture_float */
#define GL_RGBA_FLOAT32_ATI               0x8814
#define GL_RGB_FLOAT32_ATI                0x8815
#define GL_ALPHA_FLOAT32_ATI              0x8816
#define GL_INTENSITY_FLOAT32_ATI          0x8817
#define GL_LUMINANCE_FLOAT32_ATI          0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI    0x8819
#define GL_RGBA_FLOAT16_ATI               0x881A
#define GL_RGB_FLOAT16_ATI                0x881B
#define GL_ALPHA_FLOAT16_ATI              0x881C
#define GL_INTENSITY_FLOAT16_ATI          0x881D
#define GL_LUMINANCE_FLOAT16_ATI          0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI    0x881F

/* ATI_pixel_format_float */
#define GL_RGBA_FLOAT_MODE_ATI            0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835

/* ATI_draw_buffers */
#define GL_MAX_DRAW_BUFFERS_ATI           0x8824
#define GL_DRAW_BUFFER0_ATI               0x8825
#define GL_DRAW_BUFFER1_ATI               0x8826
#define GL_DRAW_BUFFER2_ATI               0x8827
#define GL_DRAW_BUFFER3_ATI               0x8828
#define GL_DRAW_BUFFER4_ATI               0x8829
#define GL_DRAW_BUFFER5_ATI               0x882A
#define GL_DRAW_BUFFER6_ATI               0x882B
#define GL_DRAW_BUFFER7_ATI               0x882C
#define GL_DRAW_BUFFER8_ATI               0x882D
#define GL_DRAW_BUFFER9_ATI               0x882E
#define GL_DRAW_BUFFER10_ATI              0x882F
#define GL_DRAW_BUFFER11_ATI              0x8830
#define GL_DRAW_BUFFER12_ATI              0x8831
#define GL_DRAW_BUFFER13_ATI              0x8832
#define GL_DRAW_BUFFER14_ATI              0x8833
#define GL_DRAW_BUFFER15_ATI              0x8834

/* ARB_draw_buffers */
#define GL_MAX_DRAW_BUFFERS_ARB           0x8824
#define GL_DRAW_BUFFER0_ARB               0x8825
#define GL_DRAW_BUFFER1_ARB               0x8826
#define GL_DRAW_BUFFER2_ARB               0x8827
#define GL_DRAW_BUFFER3_ARB               0x8828
#define GL_DRAW_BUFFER4_ARB               0x8829
#define GL_DRAW_BUFFER5_ARB               0x882A
#define GL_DRAW_BUFFER6_ARB               0x882B
#define GL_DRAW_BUFFER7_ARB               0x882C
#define GL_DRAW_BUFFER8_ARB               0x882D
#define GL_DRAW_BUFFER9_ARB               0x882E
#define GL_DRAW_BUFFER10_ARB              0x882F
#define GL_DRAW_BUFFER11_ARB              0x8830
#define GL_DRAW_BUFFER12_ARB              0x8831
#define GL_DRAW_BUFFER13_ARB              0x8832
#define GL_DRAW_BUFFER14_ARB              0x8833
#define GL_DRAW_BUFFER15_ARB              0x8834

/* NV_depth_buffer_float */
#define GL_DEPTH_COMPONENT32F_NV          0x8DAB
#define GL_DEPTH32F_STENCIL8_NV           0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV     0x8DAF

/* EXT_texture_mirror_clamp */
#define GL_MIRROR_CLAMP_EXT               0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT       0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT     0x8912

/* EXT_blend_equation_separate */
#define GL_BLEND_EQUATION_RGB_EXT         0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT       0x883D

/* ARB_shader_objects */
#define GL_PROGRAM_OBJECT_ARB             0x8B40
#define GL_SHADER_OBJECT_ARB              0x8B48
#define GL_OBJECT_TYPE_ARB                0x8B4E
#define GL_OBJECT_SUBTYPE_ARB             0x8B4F
#define GL_OBJECT_DELETE_STATUS_ARB       0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB      0x8B81
#define GL_OBJECT_LINK_STATUS_ARB         0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB     0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB     0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB    0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB     0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#define GL_FLOAT_VEC2_ARB                 0x8B50
#define GL_FLOAT_VEC3_ARB                 0x8B51
#define GL_FLOAT_VEC4_ARB                 0x8B52
#define GL_INT_VEC2_ARB                   0x8B53
#define GL_INT_VEC3_ARB                   0x8B54
#define GL_INT_VEC4_ARB                   0x8B55
#define GL_BOOL_ARB                       0x8B56
#define GL_BOOL_VEC2_ARB                  0x8B57
#define GL_BOOL_VEC3_ARB                  0x8B58
#define GL_BOOL_VEC4_ARB                  0x8B59
#define GL_FLOAT_MAT2_ARB                 0x8B5A
#define GL_FLOAT_MAT3_ARB                 0x8B5B
#define GL_FLOAT_MAT4_ARB                 0x8B5C
#define GL_SAMPLER_1D_ARB                 0x8B5D
#define GL_SAMPLER_2D_ARB                 0x8B5E
#define GL_SAMPLER_3D_ARB                 0x8B5F
#define GL_SAMPLER_CUBE_ARB               0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB          0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB          0x8B62
#define GL_SAMPLER_2D_RECT_ARB            0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB     0x8B64

/* ARB_shading_language_100 */
#define GL_SHADING_LANGUAGE_VERSION_ARB   0x8B8C

/* ARB_vertex_shader */
#define GL_VERTEX_SHADER_ARB              0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB         0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB   0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A

/* ARB_fragment_shader */
#define GL_FRAGMENT_SHADER_ARB            0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_DERIVATIVE_ACCURACY_HINT_ARB   0x8B8B

/* EXT_Cg_shader */
#define GL_CG_VERTEX_SHADER_EXT           0x890E
#define GL_CG_FRAGMENT_SHADER_EXT         0x890F

/* OpenGL15 */
#define GL_FOG_COORD_SRC                  0x8450
#define GL_FOG_COORD                      0x8451
#define GL_CURRENT_FOG_COORD              0x8453
#define GL_FOG_COORD_ARRAY_TYPE           0x8454
#define GL_FOG_COORD_ARRAY_STRIDE         0x8455
#define GL_FOG_COORD_ARRAY_POINTER        0x8456
#define GL_FOG_COORD_ARRAY                0x8457
#define GL_SRC0_RGB                       0x8580
#define GL_SRC1_RGB                       0x8581
#define GL_SRC2_RGB                       0x8582
#define GL_SRC0_ALPHA                     0x8588
#define GL_SRC1_ALPHA                     0x8589
#define GL_SRC2_ALPHA                     0x858A
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_SAMPLES_PASSED                 0x8914
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD

/* OpenGL20 */
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE        0x8643
#define GL_MAX_TEXTURE_COORDS             0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_POINT_SPRITE                   0x8861
#define GL_COORD_REPLACE                  0x8862
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5

/* NV_vertex_program2_option */
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV      0x88F5

/* NV_fragment_program2 */
/*      GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV */
/*      GL_MAX_PROGRAM_CALL_DEPTH_NV */
#define GL_MAX_PROGRAM_IF_DEPTH_NV        0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV      0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV      0x88F8

/* EXT_framebuffer_object */
#define GL_FRAMEBUFFER_EXT                0x8D40
#define GL_RENDERBUFFER_EXT               0x8D41
#define GL_STENCIL_INDEX_EXT              0x8D45
#define GL_STENCIL_INDEX1_EXT             0x8D46
#define GL_STENCIL_INDEX4_EXT             0x8D47
#define GL_STENCIL_INDEX8_EXT             0x8D48
#define GL_STENCIL_INDEX16_EXT            0x8D49
#define GL_RENDERBUFFER_WIDTH_EXT         0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT        0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_EXT      0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT    0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT     0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT    0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT    0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT  0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_COLOR_ATTACHMENT0_EXT          0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT          0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT          0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT          0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT          0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT          0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT          0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT          0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT          0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT          0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT         0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT         0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT         0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT         0x8CED
#define GL_COLOR_ATTACHMENT14_EXT         0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT         0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT           0x8D00
#define GL_STENCIL_ATTACHMENT_EXT         0x8D20
#define GL_FRAMEBUFFER_COMPLETE_EXT       0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT    0x8CDD
#define GL_FRAMEBUFFER_BINDING_EXT        0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT       0x8CA7
#define GL_MAX_COLOR_ATTACHMENTS_EXT      0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE_EXT      0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506

/* ARB_texture_float */
#define GL_TEXTURE_RED_TYPE_ARB           0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB         0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB          0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB         0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB     0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB     0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB         0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB        0x8C17
#define GL_RGBA32F_ARB                    0x8814
#define GL_RGB32F_ARB                     0x8815
#define GL_ALPHA32F_ARB                   0x8816
#define GL_INTENSITY32F_ARB               0x8817
#define GL_LUMINANCE32F_ARB               0x8818
#define GL_LUMINANCE_ALPHA32F_ARB         0x8819
#define GL_RGBA16F_ARB                    0x881A
#define GL_RGB16F_ARB                     0x881B
#define GL_ALPHA16F_ARB                   0x881C
#define GL_INTENSITY16F_ARB               0x881D
#define GL_LUMINANCE16F_ARB               0x881E
#define GL_LUMINANCE_ALPHA16F_ARB         0x881F

/* ARB_half_float_pixel */
#define GL_HALF_FLOAT_ARB                 0x140B

/* ARB_color_buffer_float */
#define GL_RGBA_FLOAT_MODE_ARB            0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB         0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB       0x891B
#define GL_CLAMP_READ_COLOR_ARB           0x891C
#define GL_FIXED_ONLY_ARB                 0x891D

/* EXT_ycbcr_422 */
#define GL_CBYCRY_422_EXT                 0x8C20
#define GL_YCBYCR_422_EXT                 0x8C21
#define GL_TRANSFORM_YUV_TO_RGB_WITH_BT_601_EXT 0x8C22
#define GL_TRANSFORM_YUV_TO_RGB_WITH_BT_709_EXT 0x8C23
#define GL_TRANSFORM_RGB_TO_YUV_WITH_BT_601_EXT 0x8C24
#define GL_TRANSFORM_RGB_TO_YUV_WITH_BT_709_EXT 0x8C25

/* ARB_pixel_buffer_object */
#define GL_PIXEL_PACK_BUFFER_ARB          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF

/* EXT_timer_query */
#define GL_TIME_ELAPSED_EXT               0x88BF

/* NV_geometry_program4 */
#define GL_GEOMETRY_PROGRAM_NV            0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT      0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT        0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT       0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_LINES_ADJACENCY_EXT            0xA
#define GL_LINE_STRIP_ADJACENCY_EXT       0xB
#define GL_TRIANGLES_ADJACENCY_EXT        0xC
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT   0xD
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT         0x8642

/* NV_vertex_program4 */
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD

/* EXT_texture_sRGB */
#define GL_SRGB_EXT                       0x8C40
#define GL_SRGB8_EXT                      0x8C41
#define GL_SRGB_ALPHA_EXT                 0x8C42
#define GL_SRGB8_ALPHA8_EXT               0x8C43
#define GL_SLUMINANCE_ALPHA_EXT           0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT         0x8C45
#define GL_SLUMINANCE_EXT                 0x8C46
#define GL_SLUMINANCE8_EXT                0x8C47
#define GL_COMPRESSED_SRGB_EXT            0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT      0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT      0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT  0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F

/* EXT_texture_shared_exponent */
#define GL_RGB9_E5_EXT                    0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT   0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT        0x8C3F

/* EXT_packed_float */
#define GL_R11F_G11F_B10F_EXT             0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT     0x8C3C

/* EXT_texture_array */
#define GL_TEXTURE_1D_ARRAY_EXT           0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT     0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT           0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT     0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT   0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT   0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT   0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
/*      GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */

/* NV_gpu_program4 */
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV    0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV    0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV   0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV   0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6

/* EXT_texture_integer */
#define GL_RGBA32UI_EXT                   0x8D70
#define GL_RGB32UI_EXT                    0x8D71
#define GL_ALPHA32UI_EXT                  0x8D72
#define GL_INTENSITY32UI_EXT              0x8D73
#define GL_LUMINANCE32UI_EXT              0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT        0x8D75
#define GL_RGBA16UI_EXT                   0x8D76
#define GL_RGB16UI_EXT                    0x8D77
#define GL_ALPHA16UI_EXT                  0x8D78
#define GL_INTENSITY16UI_EXT              0x8D79
#define GL_LUMINANCE16UI_EXT              0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT        0x8D7B
#define GL_RGBA8UI_EXT                    0x8D7C
#define GL_RGB8UI_EXT                     0x8D7D
#define GL_ALPHA8UI_EXT                   0x8D7E
#define GL_INTENSITY8UI_EXT               0x8D7F
#define GL_LUMINANCE8UI_EXT               0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT         0x8D81
#define GL_RGBA32I_EXT                    0x8D82
#define GL_RGB32I_EXT                     0x8D83
#define GL_ALPHA32I_EXT                   0x8D84
#define GL_INTENSITY32I_EXT               0x8D85
#define GL_LUMINANCE32I_EXT               0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT         0x8D87
#define GL_RGBA16I_EXT                    0x8D88
#define GL_RGB16I_EXT                     0x8D89
#define GL_ALPHA16I_EXT                   0x8D8A
#define GL_INTENSITY16I_EXT               0x8D8B
#define GL_LUMINANCE16I_EXT               0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT         0x8D8D
#define GL_RGBA8I_EXT                     0x8D8E
#define GL_RGB8I_EXT                      0x8D8F
#define GL_ALPHA8I_EXT                    0x8D90
#define GL_INTENSITY8I_EXT                0x8D91
#define GL_LUMINANCE8I_EXT                0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT          0x8D93
#define GL_RED_INTEGER_EXT                0x8D94
#define GL_GREEN_INTEGER_EXT              0x8D95
#define GL_BLUE_INTEGER_EXT               0x8D96
#define GL_ALPHA_INTEGER_EXT              0x8D97
#define GL_RGB_INTEGER_EXT                0x8D98
#define GL_RGBA_INTEGER_EXT               0x8D99
#define GL_BGR_INTEGER_EXT                0x8D9A
#define GL_BGRA_INTEGER_EXT               0x8D9B
#define GL_LUMINANCE_INTEGER_EXT          0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT    0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT          0x8D9E

/* NV_parameter_buffer_object */
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4

/* EXT_framebuffer_blit */
#define GL_READ_FRAMEBUFFER_EXT           0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT           0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT   0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT   0x8CAA

/* BlitFramebufferBufferMask */

/* BlitFramebufferFilter */

/* EXT_framebuffer_multisample */
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT                0x8D57
#define GL_RENDERBUFFER_SAMPLES_EXT       0x8CAB

/* EXT_texture_buffer_object */
#define GL_TEXTURE_BUFFER_EXT             0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT    0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT     0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT      0x8C2E

/* EXT_gpu_shader4 */
#define GL_SAMPLER_1D_ARRAY_EXT           0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT           0x8DC1
#define GL_SAMPLER_BUFFER_EXT             0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT    0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT    0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT        0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT          0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT          0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT          0x8DC8
#define GL_INT_SAMPLER_1D_EXT             0x8DC9
#define GL_INT_SAMPLER_2D_EXT             0x8DCA
#define GL_INT_SAMPLER_3D_EXT             0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT           0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT        0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT       0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT       0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT         0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT    0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT    0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT    0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT  0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8

/* EXT_geometry_shader4 */
#define GL_GEOMETRY_SHADER_EXT            0x8DD9
/*      GL_GEOMETRY_VERTICES_OUT_EXT */
/*      GL_GEOMETRY_INPUT_TYPE_EXT */
/*      GL_GEOMETRY_OUTPUT_TYPE_EXT */
/*      GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT */
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT     0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
/*      GL_LINES_ADJACENCY_EXT */
/*      GL_LINE_STRIP_ADJACENCY_EXT */
/*      GL_TRIANGLES_ADJACENCY_EXT */
/*      GL_TRIANGLE_STRIP_ADJACENCY_EXT */
/*      GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT */
/*      GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT */
/*      GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT */
/*      GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */
/*      GL_PROGRAM_POINT_SIZE_EXT */

/* EXT_bindable_uniform */
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT  0x8DED
#define GL_UNIFORM_BUFFER_EXT             0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT     0x8DEF

/* OpenGL21 */
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_SLUMINANCE_ALPHA               0x8C44
#define GL_SLUMINANCE8_ALPHA8             0x8C45
#define GL_SLUMINANCE                     0x8C46
#define GL_SLUMINANCE8                    0x8C47
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
#define GL_COMPRESSED_SLUMINANCE          0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA    0x8C4B
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F

/* EXT_framebuffer_sRGB */
#define GL_FRAMEBUFFER_SRGB_EXT           0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT   0x8DBA

/* NV_conditional_render */
#define GL_QUERY_WAIT_NV                  0x8E13
#define GL_QUERY_NO_WAIT_NV               0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV        0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV     0x8E16

/* NVX_volatile_texture */
#define GL_TEXTURE_IMMUTABLE_NVX          0x8DEB
#define GL_TEXTURE_VOLATILE_NVX           0x8DEC

/* NV_framebuffer_multisample_coverage */
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV  0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV  0x8E12

/* NV_texture_cube_map_array */
#define GL_TEXTURE_CUBE_MAP_ARRAY_NV      0x8E17
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_NV 0x8E18
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_NV 0x8E19
#define GL_SAMPLER_CUBE_MAP_ARRAY_NV      0x8E1A
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_NV 0x8E1B

/* NV_multisample_coverage */
#define GL_COVERAGE_SAMPLES_NV            0x80A9
#define GL_COLOR_SAMPLES_NV               0x8E20

/*************************************************************/



#endif /* __glext_h_ */
