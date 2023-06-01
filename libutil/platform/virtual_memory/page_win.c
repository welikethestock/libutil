#ifdef _WIN32
#include "page.h"

LIBUTIL_API
void LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    LIBUTIL_DEBUGBREAK();
}

#endif
