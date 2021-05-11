#include "../include/sl_list.h"

Node*   sl_nodenew(void const *content)
{
    Node*  node;

    node = (Node*)malloc(sizeof(node));
    node->content = content;
    node->next = NULL;
    return node;
}

List* sl_lstnew(void const **content, size_t node_size)
{
    List*   newList;
    Node*   tmp;
    int     index;

    newList = (List*)malloc(sizeof(List));
    newList->length = node_size;

    index = 0;
    while (index < node_size)
    {
        if (index == 0)
        {
            newList->node = sl_nodenew(content[index]);
            tmp = newList->node;
        }
        else
        {
            tmp->next = sl_nodenew(content[index]);
            tmp = tmp->next;
        }
    }
    return newList;
}
