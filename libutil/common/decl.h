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

    typedef libutil_u8          libutil_bool;
    #ifndef TRUE
        #define TRUE                (1)
    #endif

    #ifndef FALSE
        #define FALSE               (0)
    #endif

    typedef unsigned long       libutil_size;

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
#define LIBUTIL_ATTRIBUTE(Attribute) __attribute__((Attribute))

#ifndef LIBUTIL_API
    #define LIBUTIL_API
#endif

#ifndef LIBUTIL_IMPORT
    #if defined(__GNUC__) || defined(__clang__)
        #define LIBUTIL_IMPORT
    #else
        #define LIBUTIL_IMPORT
    #endif
#endif

#ifndef LIBUTIL_EXPORT
    #if defined(__GNUC__) || defined(__clang__)
        #define LIBUTIL_EXPORT LIBUTIL_ATTRIBUTE(visibility("default"))
    #else
        #define LIBUTIL_EXPORT
    #endif
#endif

#ifndef LIBUTIL_INLINE
    #define LIBUTIL_INLINE inline
#endif

#ifndef LIBUTIL_FORCE_INLINE
    #if defined(__GNUC__) || defined(__clang__)
        #define LIBUTIL_FORCE_INLINE LIBUTIL_INLINE LIBUTIL_ATTRIBUTE(always_inline)
    #else
        #define LIBUTIL_FORCE_INLINE LIBUTIL_INLINE
    #endif
#endif

#ifndef LIBUTIL_NAKED
    #if defined(__GNUC__) || defined(__clang__)
        #define LIBUTIL_NAKED LIBUTIL_ATTRIBUTE(naked)
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

/* intrinsics */
#include "intrinsics.h"

#endif
