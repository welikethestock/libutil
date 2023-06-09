#ifndef __LIBUTIL_COMMON_WARNINGS__
#define __LIBUTIL_COMMON_WARNINGS__

#include "features.h"

#ifdef LIBUTIL_MSVC
    #pragma warning(disable: 4359) // 'x': Alignment specifier is less than actual alignment (y), and will be ignored.

    #ifdef LIBUTIL_X86
        #pragma warning(disable: 4409) // illegal instruction size
    #endif
#endif

#endif
