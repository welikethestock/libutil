#include "../common/decl.h"

LIBUTIL_NORETURN LIBUTIL_NAKED
void __stack_chk_fail()
{
    LIBUTIL_DEBUGBREAK();
}
