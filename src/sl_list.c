#include "../include/sl_list.h"

Node*   createNode(void const *content)
{
    Node*  node;

    node = (Node*)malloc(sizeof(node));
    node->content = content;
    node->next = NULL;
    return node;
}

List* createList(void const **content, size_t node_size)
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


//destory node
int    destroyNode(Node* node)
{
    if (node->content != NULL)
        free(node->content);
    free(node);
    if (node == NULL)
        return TRUE;
    return FALSE;
}

int    destroyNodeByPosition(Node* node, int index)
{
    Node* tmp;
    Node* toDelete;

    tmp = node;
    toDelete = tmp;
    while (toDelete || index--) {
        tmp = toDelete;
        toDelete = tmp->next;
    }
    if (toDelete == NULL)
        return FALSE;
    tmp->next = toDelete->next;

    return destroyNode(toDelete);
}

int     destroyNodeByContent(Node* node, void *content)
{
    Node* tmp;
    Node* toDelete;

    tmp = node;
    toDelete = tmp;
    while (toDelete || toDelete->content != content) {
        tmp = toDelete;
        toDelete = tmp->next;
    }
    if (toDelete == NULL)
        return FALSE;

    tmp->next = toDelete->next;
    return destroyNode(toDelete);
}

int    destroyNodeList(Node* node)
{
    Node*   tmp;
    int     result = TRUE;

    while (node)
    {
        tmp = node->next;
        if (sl_destroyNode(node) == FALSE)
            result = FALSE;
        node = tmp;
    }
    return result;
}

//destroy List
int    destroyList(List* lst)
{
    int result;
    result = destroyNodeList(lst->node);
    if (lst)
        free(lst);
    return result && (lst != NULL);
}

int    destroyNodeListbyPosition(List* lst, int index)
{
    return destroyNodeByPosition(lst->node, index);
}

int    destroyNodeListbyContent(List* lst, void* content)
{
    return destroyNodeByContent(lst->node, content);
}