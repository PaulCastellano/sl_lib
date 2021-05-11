#include "sl_memory.h"
#include "sl_boolean.h"

typedef struct Node
{
    void    *content;
    struct Node *next;
}               Node;

typedef struct List
{
    Node    *node;
    size_t  length;
}               List;

//create node/list
Node*   sl_nodenew(void const *content);
List*   sl_lstnew(void const **content, size_t node_size);

//destory node
int    sl_destroyNode(Node* node);
int    sl_destroyNodebyPossition(Node* node, int index);
int    sl_destroyNodeList(Node* node);

//destroy List
int    sl_destroyList(List* lst);
int    sl_destroyListNodebyPossition(List* lst, int index);
int    sl_destroeyListNodebyContent(List* lst, void* content);