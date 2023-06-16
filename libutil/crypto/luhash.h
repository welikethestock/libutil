#ifndef __LIBUTIL_CRYPTO_MURMUR__
#define __LIBUTIL_CRYPTO_MURMUR__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_u32 LibUtil_LUHash(const void *Data, libutil_u32 Seed, libutil_size Length);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
