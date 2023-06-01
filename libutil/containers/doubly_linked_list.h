#ifndef __LIBUTIL_CONTAINERS_DOUBLY_LINKED_LIST__
#define __LIBUTIL_CONTAINERS_DOUBLY_LINKED_LIST__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef struct _LIBUTIL_DOUBLY_LINKED_LIST_NODE
{
    struct _LIBUTIL_DOUBLY_LINKED_LIST_NODE *Previous;
    struct _LIBUTIL_DOUBLY_LINKED_LIST_NODE *Next;
    void                                    *Value;
} LIBUTIL_DOUBLY_LINKED_LIST_NODE;

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_DOUBLY_LINKED_LIST_NODE *LibUtil_DoublyLinkedList_Create();

LIBUTIL_API LIBUTIL_IMPORT
void                            LibUtil_DoublyLinkedList_Destroy(LIBUTIL_DOUBLY_LINKED_LIST_NODE *Root);

LIBUTIL_API LIBUTIL_IMPORT
void                            LibUtil_DoublyLinkedList_AppendNode(LIBUTIL_DOUBLY_LINKED_LIST_NODE *RootNode, LIBUTIL_DOUBLY_LINKED_LIST_NODE *Node);

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Containers
        {
            struct DoublyLinkedList;
        }
    }

    struct LibUtil::Containers::DoublyLinkedList
    {
        LIBUTIL_FORCE_INLINE
        static void *operator new(LibUtil::Size Size)
        {
            return LibUtil_DoublyLinkedList_Create();
        }

        LIBUTIL_DOUBLY_LINKED_LIST_NODE Root;
    };
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
