#ifndef __LIBUTIL_COMMON_DECL__
#define __LIBUTIL_COMMON_DECL__

/* extern "C" */
#ifndef LIBUTIL_EXTERN_C
    #ifdef __cplusplus
        #define LIBUTIL_EXTERN_C extern "C"
    #else
        #define LIBUTIL_EXTERN_C
    #endif
#endif

#ifndef LIBUTIL_EXTERN_C_BLOCK_START
    #ifdef __cplusplus
        #define LIBUTIL_EXTERN_C_BLOCK_START extern "C" {
    #else
        #define LIBUTIL_EXTERN_C_BLOCK_START
    #endif
#endif

#ifndef LIBUTIL_EXTERN_C_BLOCK_END
    #ifdef __cplusplus
        #define LIBUTIL_EXTERN_C_BLOCK_END }
    #else
        #define LIBUTIL_EXTERN_C_BLOCK_END
    #endif
#endif

#include "features.h"

LIBUTIL_EXTERN_C_BLOCK_START

/* basic types */
#ifndef LIBUTIL_COMMON_TYPES
    #define LIBUTIL_COMMON_TYPES

    typedef char                libutil_i8;
    typedef unsigned char       libutil_u8;
    typedef short               libutil_i16;
    typedef unsigned short      libutil_u16;
    typedef int                 libutil_i32;
    typedef unsigned int        libutil_u32;
    typedef long long           libutil_i64;
    typedef unsigned long long  libutil_u64;

    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        typedef libutil_i8          lu_i8;
        typedef libutil_u8          lu_u8;
        typedef libutil_i16         lu_i16;
        typedef libutil_u16         lu_u16;
        typedef libutil_i32         lu_i32;
        typedef libutil_u32         lu_u32;
        typedef libutil_i64         lu_i64;
        typedef libutil_u64         lu_u64;
    #endif

    typedef libutil_u8          libutil_bool;

    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        typedef libutil_bool        lu_bool;
    #endif

    #ifndef TRUE
        #define TRUE                (1)
    #endif

    #ifndef FALSE
        #define FALSE               (0)
    #endif

    #ifdef LIBUTIL_64_BITS
        #if defined(LIBUTIL_GNUC) || (defined(LIBUTIL_CLANG) && !defined(LIBUTIL_WINDOWS))
            typedef unsigned long       libutil_size;
            typedef signed long         libutil_ssize;
        #else
            typedef unsigned long long  libutil_size;
            typedef signed long long    libutil_ssize;
        #endif
    #else
        #if defined(LIBUTIL_MSVC) || defined(LIBUTIL_GNUC)
            typedef unsigned int        libutil_size;
            typedef signed int          libutil_ssize;
        #else
            typedef unsigned long       libutil_size;
            typedef signed long         libutil_ssize;
        #endif
    #endif

    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        typedef libutil_size        lu_size;
        typedef libutil_ssize       lu_ssize;
    #endif

    typedef libutil_u16             libutil_wchar; // microsoft garbage

    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        typedef libutil_wchar       lu_wchar;
    #endif

    #ifdef __cplusplus
    extern "C++"
    {
        namespace LibUtil
        {
            using I8    = libutil_i8;
            using U8    = libutil_u8;
            using I16   = libutil_i16;
            using U16   = libutil_u16;
            using I32   = libutil_i32;
            using U32   = libutil_u32;
            using I64   = libutil_i64;
            using U64   = libutil_u64;

            using Bool  = libutil_bool;

            using Size  = libutil_size;
        }
    }
    #endif

    #ifndef NULL
        #define NULL (0)
    #endif
#endif

/* compiler declarations */
#ifndef LIBUTIL_ATTRIBUTE
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_ATTRIBUTE(Attribute) __attribute__((Attribute))
    #else
        #define LIBUTIL_ATTRIBUTE(Attribute) __declspec(Attribute)
    #endif
#endif

#ifndef LIBUTIL_API
    #define LIBUTIL_API
#endif

#ifndef LIBUTIL_IMPORT
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_IMPORT
    #else
        #define LIBUTIL_IMPORT
    #endif
#endif

#ifndef LIBUTIL_EXPORT
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_EXPORT LIBUTIL_ATTRIBUTE(visibility("default"))
    #else
        #define LIBUTIL_EXPORT
    #endif
#endif

#ifndef LIBUTIL_INLINE
    #define LIBUTIL_INLINE inline
#endif

#ifndef LIBUTIL_FORCE_INLINE
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_FORCE_INLINE LIBUTIL_INLINE LIBUTIL_ATTRIBUTE(always_inline)
    #else
        #define LIBUTIL_FORCE_INLINE LIBUTIL_INLINE __forceinline
    #endif
#endif

#ifndef LIBUTIL_NAKED
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_NAKED LIBUTIL_ATTRIBUTE(naked)
    #else
        #ifdef LIBUTIL_X86
            #define LIBUTIL_NAKED LIBUTIL_ATTRIBUTE(naked)
        #else
            #define LIBUTIL_NAKED
        #endif
    #endif
#endif

#ifndef LIBUTIL_NORETURN
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_NORETURN LIBUTIL_ATTRIBUTE(noreturn)
    #else
        #define LIBUTIL_NORETURN LIBUTIL_ATTRIBUTE(noreturn)
    #endif
#endif

#ifndef LIBUTIL_ALIGN
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_ALIGN(Alignment) LIBUTIL_ATTRIBUTE(aligned(Alignment))
    #else
        #define LIBUTIL_ALIGN(Alignment) LIBUTIL_ATTRIBUTE(align(Alignment))
    #endif
#endif

#ifndef LIBUTIL_PACKED
    #if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
        #define LIBUTIL_PACKED LIBUTIL_ATTRIBUTE(packed)
    #else
        #define LIBUTIL_PACKED
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

/* intrinsics */
#include "intrinsics.h"

#endif
