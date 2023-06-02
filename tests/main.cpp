#include "libutil/common/memory/heap.h"
#include "libutil/containers/doubly_linked_list.h"
#include "libutil/code/patch.h"
#include "libutil/platform/virtual_memory/page.h"
#include "libutil/platform/sys/syscall.h"
#include "libutil/common/memory/mlib.h"

#include <errno.h>
#include <stdio.h>

char Test[512] = {};

int main(int argc, const char **argv)
{
    LibUtil::Memcpy(Test, "123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)", sizeof("123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)"));

    printf("%s\n", Test);
    //LibUtil_Syscall3(1, 1, (libutil_size)"Hello!!", sizeof("Hello!!"));

    return 0;
}
