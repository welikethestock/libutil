#include "libutil/common/memory/heap.h"
#include "libutil/containers/doubly_linked_list.h"
#include "libutil/code/patch.h"
#include "libutil/platform/virtual_memory/page.h"
#include "libutil/platform/syscall.h"

#include <errno.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    printf("%d %d\n", LibUtil_Page_Protect((void *)(&main), 1, LIBUTIL_PAGE_RWX, NULL), errno);
    //LibUtil_Syscall3(1, 1, (libutil_size)"Hello!!", sizeof("Hello!!"));

    return 0;
}
