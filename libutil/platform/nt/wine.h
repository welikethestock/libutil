#ifndef __LIBUTIL_PLATFORM_NT_WINE__
#define __LIBUTIL_PLATFORM_NT_WINE__

#ifdef LIBUTIL_WINE

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Nt_InitializeWine();

LIBUTIL_EXTERN_C_BLOCK_END

#endif

#endif
