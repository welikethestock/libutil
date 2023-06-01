#include "libutil/containers/doubly_linked_list.h"
#include "libutil/code/patch.h"
#include "libutil/platform/syscall.h"

#include <stdio.h>

int main(int argc, const char **argv)
{
    LibUtil_Syscall3(1, 1, (libutil_size)"Hello!!", sizeof("Hello!!"));

    return 0;
}
