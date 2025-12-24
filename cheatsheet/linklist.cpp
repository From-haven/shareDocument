// viet linklist ko co thang tail
#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    Node* pNext;
    int value;
};

struct List{
    Node* pHead;
};

void initList(List &list){
    list.pHead = NULL;
}

// add note

Node* newNode(const int value)
{
    Node* np = new Node;
    np->pNext = NULL;
    np->value = value;
    return np;
}

void addNode(List& list, const int value)
{
    Node *node = list.pHead;
    // List is notthing
    if(node == NULL)
    {
        node = newNode(value);
        list.pHead = node;
        return;  
    }

    while(node->pNext != NULL)
    {
        node = node->pNext;
    }
    node->pNext = newNode(value);
}

void addNodeAtHead(List& list, const int value)
{
    Node* np = newNode(value);
    np->pNext = list.pHead;
    list.pHead = np;
}

void addnodeAfter(List& list, const int value,Node *node)
{
    Node* prevNode = newNode(value);
    prevNode->pNext = node->pNext;
    node->pNext = prevNode;
}

// remove node
void removeNode(List& list, Node* node)
{
    if(list.pHead == NULL || node == NULL) return;

    // remove head
    if(list.pHead == node)
    {
        list.pHead = node->pNext;
        delete node;
        return;
    }

    Node* prev = list.pHead;
    while(prev->pNext != NULL && prev->pNext != node)
    {
        prev = prev->pNext;
    }

    if(prev->pNext == node)
    {
        prev->pNext = node->pNext;
        delete node;
    }
}

void removeAllNode(List& list)
{
    Node *cur = list.pHead;
    while(cur != NULL)
    {
        Node *rmNode = cur;
        cur = cur->pNext;
        delete rmNode;
    }
    list.pHead = NULL;
}

//find node

Node* findNode(List& list,const int value)
{
    Node* cur = list.pHead;
    if(cur == NULL)return cur;

    while(cur->value != value && cur->pNext != NULL)
    {
        cur = cur->pNext;
    }
    if(cur->value == value)return cur;
    else return NULL;
    // return cur; luon cx dc
}
