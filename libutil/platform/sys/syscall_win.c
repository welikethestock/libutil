#ifdef _WIN32
#include "syscall.h"

#if defined(__GNUC__) || defined(__clang__)
LIBUTIL_API
libutil_i64 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3)
{

}
#endif

#endif
