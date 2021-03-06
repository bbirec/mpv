/*
 * This file is part of mpv.
 *
 * mpv is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * mpv is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with mpv.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef MP_GET_GL_WORKAROUNDS

// workaround for some gl.h headers
#ifndef GLAPIENTRY
#ifdef APIENTRY
#define GLAPIENTRY APIENTRY
#elif HAVE_GL_WIN32
#define GLAPIENTRY __stdcall
#else
#define GLAPIENTRY
#endif
#endif

#ifndef GL_TEXTURE_RECTANGLE
#define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_UNSIGNED_SHORT_8_8
#define GL_UNSIGNED_SHORT_8_8 0x85BA
#endif
#ifndef GL_UNSIGNED_SHORT_8_8_REV
#define GL_UNSIGNED_SHORT_8_8_REV 0x85BB
#endif

#if HAVE_GL_WIN32 && !defined(WGL_CONTEXT_MAJOR_VERSION_ARB)
/* these are supposed to be defined in wingdi.h but mingw's is too old */
/* only the bits actually used by mplayer are defined */
/* reference: http://www.opengl.org/registry/specs/ARB/wgl_create_context.txt */

#define WGL_CONTEXT_MAJOR_VERSION_ARB          0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB          0x2092
#define WGL_CONTEXT_FLAGS_ARB                  0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB           0x9126
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB   0x00000001
#endif

#ifndef GL_NV_vdpau_interop
#define GLvdpauSurfaceNV GLintptr
#endif

#ifndef GL_DEBUG_SEVERITY_HIGH
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#endif

#if HAVE_ANDROID_GL
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_RGB_422_APPLE 0x8A1F
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_TEXTURE_1D 0x0DE0
#define GL_WRITE_ONLY 0x88B9
#define GL_RGB16 0x8054
#define GL_RGB10 0x8052
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_R16 0x822A
#define GL_RG16 0x822C
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#endif

#undef MP_GET_GL_WORKAROUNDS

#endif // MP_GET_GL_WORKAROUNDS

#ifdef MP_GET_GLX_WORKAROUNDS

// FreeBSD 10.0-CURRENT lacks the GLX_ARB_create_context extension completely
#ifndef GLX_CONTEXT_MAJOR_VERSION_ARB
#define GLX_CONTEXT_MAJOR_VERSION_ARB           0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB           0x2092
#define GLX_CONTEXT_FLAGS_ARB                   0x2094
#define GLX_CONTEXT_PROFILE_MASK_ARB            0x9126
#ifndef __APPLE__
// These are respectively 0x00000001 and 0x00000002 on OSX
#define GLX_CONTEXT_DEBUG_BIT_ARB               0x0001
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB  0x0002
#endif
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB        0x00000001
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif
// GLX_EXT_create_context_es2_profile
#ifndef GLX_CONTEXT_ES2_PROFILE_BIT_EXT
#define GLX_CONTEXT_ES2_PROFILE_BIT_EXT         0x00000004
#endif

#undef MP_GET_GLX_WORKAROUNDS

#endif
