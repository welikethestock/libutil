#include "doubly_linked_list.h"
#include "../common/memory/heap.h"

LIBUTIL_API
LIBUTIL_DOUBLY_LINKED_LIST_NODE *LibUtil_DoublyLinkedList_Create()
{
    LIBUTIL_DOUBLY_LINKED_LIST_NODE *Root = LibUtil_Heap_Allocate(sizeof(LIBUTIL_DOUBLY_LINKED_LIST_NODE));
    if(Root != NULL)
    {
        Root->Next = Root->Previous = Root->Value = NULL;
    }

    return Root;
}

LIBUTIL_API
void LibUtil_DoublyLinkedList_Destroy(LIBUTIL_DOUBLY_LINKED_LIST_NODE *Root)
{
    while(Root != NULL)
    {
        LIBUTIL_DOUBLY_LINKED_LIST_NODE *Next = Root->Next;
        LibUtil_Heap_Free(Root);

        Root = Next;
    }
}

LIBUTIL_API
void LibUtil_DoublyLinkedList_AppendNode(LIBUTIL_DOUBLY_LINKED_LIST_NODE *RootNode, LIBUTIL_DOUBLY_LINKED_LIST_NODE *Node)
{
    while(RootNode->Next != NULL)
    {
        RootNode = RootNode->Next;
    }

    RootNode->Next = Node;
    Node->Previous = RootNode;
}
