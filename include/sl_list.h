#include "sl_memory.h"

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

Node*   sl_nodenew(void const *content);
List*   sl_lstnew(void const **content, size_t node_size);
