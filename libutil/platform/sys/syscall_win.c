#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "syscall.h"

#if defined(LIBUTIL_GNUC) || defined(LIBUTIL_CLANG)
LIBUTIL_API
libutil_i64 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3)
{

}
#endif

#endif
