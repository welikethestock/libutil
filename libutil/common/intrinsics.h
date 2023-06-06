#ifndef __LIBUTIL_COMMON_INTRINSICS__
#define __LIBUTIL_COMMON_INTRINSICS__

#include "decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

#if defined(__STDC_HOSTED__) && (__clang__)
    #define _RESTORE_STDC_HOSTED
    #undef __STDC_HOSTED_
#endif

#define __int32 int
#define __int64 long long

#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)
    #ifdef __GNUC__
        #include <x86intrin.h>
    #endif

    #ifndef _MSC_VER
        #define _MSC_VER
    #endif

    #define _NATIVE_WCHAR_T_DEFINED 1
    #define __halt      static __halt
    #define __movsb     static __movsb
    #define __movsd     static __movsd
    #define __movsw     static __movsw
    #define __stosd     static __stosd
    #define __stosw     static __stosw
    #define __movsq     static __movsq
    #define __stosq     static __stosq
    #define __nop       static __nop
    #define __readmsr   static __readmsr
    #define __readcr3   static __readcr3
    #define __writecr3  static __writecr3

    #if defined(__clang__) || defined(_WIN32) // not available with GCC
        #include <intrin.h>
    #endif

    #ifndef _WIN32
        #undef _MSC_VER
    #endif

    #undef __halt
    #undef __movsb
    #undef __movsd
    #undef __movsw
    #undef __stosd
    #undef __stosw
    #undef __movsq
    #undef __stosq
    #undef __nop
    #undef __readmsr
    #undef __readcr3
    #undef __writecr3
#endif

#ifdef _RESTORE_STDC_HOSTED
    #define __STDC_HOSTED__ 1
    #undef _RESTORE_STDC_HOSTED
#endif

#undef __int32
#undef __int64

#ifndef LIBUTIL_DEBUGBREAK
    #if defined(__GNUC__) || defined(__clang__)
        #define LIBUTIL_DEBUGBREAK()    __asm("int3")
    #else
        #define LIBUTIL_DEBUGBREAK      __debugbreak
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
