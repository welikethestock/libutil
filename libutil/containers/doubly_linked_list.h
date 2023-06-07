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
void                            LibUtil_DoublyLinkedList_Setup(LIBUTIL_DOUBLY_LINKED_LIST_NODE *Root);

LIBUTIL_API LIBUTIL_IMPORT
void                            LibUtil_DoublyLinkedList_Destroy(LIBUTIL_DOUBLY_LINKED_LIST_NODE *Root);

LIBUTIL_API LIBUTIL_IMPORT
void                            LibUtil_DoublyLinkedList_AppendNode(LIBUTIL_DOUBLY_LINKED_LIST_NODE *RootNode, LIBUTIL_DOUBLY_LINKED_LIST_NODE *Node);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_DOUBLY_LINKED_LIST_NODE     lu_doublylinkedlist, lu_doublylinkedlist_node;

    #define lu_doublylinkedlistcreate           LibUtil_DoublyLinkedList_Create
    #define lu_doublylinkedlistsetup            LibUtil_DoublyLinkedList_Setup
    #define lu_doublylinkedlistdestroy          LibUtil_DoublyLinkedList_Destroy
    #define lu_doublylinkedlistappend           LibUtil_DoublyLinkedList_AppendNode
#endif

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

    struct LibUtil::Containers::DoublyLinkedList : public LIBUTIL_DOUBLY_LINKED_LIST_NODE
    {
        LIBUTIL_FORCE_INLINE
        DoublyLinkedList()
        {
            LibUtil_DoublyLinkedList_Setup(
                this
            );
        }

        LIBUTIL_FORCE_INLINE
        static void *operator new(LibUtil::Size Size)
        {
            return LibUtil_DoublyLinkedList_Create();
        }

        LIBUTIL_FORCE_INLINE
        static void operator delete(void *Address)
        {
            LibUtil_DoublyLinkedList_Destroy((LIBUTIL_DOUBLY_LINKED_LIST_NODE *)(Address));
        }
    };
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
