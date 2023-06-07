#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "teb.h"

#ifdef LIBUTIL_X86_64
LIBUTIL_API
LIBUTIL_NT_TEB64 *LibUtil_Nt_GetTeb()
{
    return (LIBUTIL_NT_TEB64 *)(__readgsqword(0x30));
}
#endif

#endif

