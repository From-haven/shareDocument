#include <iostream>
using namespace std;

struct Node{
    Node* pNext;
    int value;
};

struct List{
    Node* pHead;
};

Node* addNode(int n)
{
    Node* np = new Node;
    np->pNext = NULL;
    np->value = n;
    return np;
}

void addNode(List& list)
{
    Node* prev = list.pHead;
    Node* np = addNode(12);
    np->pNext = prev;
    list.pHead = np;
}



int main()
{
    
    int a;
    cin >> a;
    List list;
    list.pHead = NULL;
    for(int i=0;i<100000;i++)
    {
        for(int j=0;j<10000;j++)
        {
            addNode(list);
        }
    }
    cout << 1;
    cin >> a;
    return 0;
}