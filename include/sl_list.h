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
Node*   createNode(void const *);
List*   createList(void const **, size_t);

//destory node
int     destroyNode(Node*);
int     destroyNodeByPosition(Node*, int);
int     destroyNodeByContent(Node*, int);
int     destroyNodeList(Node*);

//destroy List
int     destroyList(List*);
int     destroyNodeListbyPosition(List*, int);
int     destroyNodeListbyContent(List*, void*);
