/*
SINGLY LINKED LIST
made using c++ structure
functions: 
    insertAtBeginning
    insertAtEnd
    insertAtpos
        if pos = 0, insert at beginning. 
        if pos != 0, insert after pos 
    deleteNodeAtBeginning
    deleteNodeAtEnd
    deleteNodeAtPos
        for any position pos, node at pos will be deleted
    isEmpty
    DisplayLLI (display linked list iterative)
    DisplayLLR (display linked list recursive)

    things to note:
        -while deleting any node at end (deleteNodeAtEnd),
        traverse only through the second last node. directly
        deleting the node will cause ?memory leaks?

        -for deleting at any position, sliding pointer have 
        been used, p pointing to the node to be deleted and
        q to the previous node.
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
};

void insertAtBeginning(struct LinkedList *l, int n)
{
    struct Node *newNode = new Node;
    newNode -> data = n;
    
    if(!l -> head)
    {
        l -> head = newNode;
        newNode -> next =  NULL;
    }
    else
    {
        newNode -> next = l -> head;
        l -> head = newNode;
    }
}

void insertAtEnd(struct LinkedList *l, int n)
{
    struct Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = NULL;

    if(!l -> head)
    {
        l -> head = newNode;
    }
    else
    {
        struct Node *p = l -> head;

        while(p -> next) p = p -> next;
        p -> next = newNode;
    }
}

void insertNodeAtPos(struct LinkedList *l, int n, int pos = 0)
{
    struct Node *newNode = new Node;
    newNode -> data = n;

    if(pos == 0)
    {
        if(!l -> head)
        {
            newNode -> next = NULL;
            l -> head = newNode;
        }
        else
        {
            newNode -> next = l -> head;
            l -> head = newNode;
        }
    }
    else
    {
        if(!l -> head)
        {
            cout << "invalid postion\n";
        }
        else
        {
            struct Node *p = l -> head;

            for(int i = 1; (i <= pos - 1) && p ; i++ )
                p = p -> next;

            newNode -> next = p -> next;
            p -> next = newNode;
        }
    }
}

int deleteNodeAtBeginning(struct LinkedList *l)
{
    int x = -1;
    if(!l -> head)
    {
        cout << "underflow\n";
    }
    else
    {
        struct Node *p = l->head;

        l->head = l->head->next;
        x = p->data;
        delete p;
    }
    
    return x;
}

int deleteNodeAtEnd(struct LinkedList *l)
{
    int x = -1;

    if(!l -> head)
    {
        cout << "underflow\n";
    }
    else
    {
        struct Node *p = l -> head;
        while(p -> next -> next) p = p -> next;

        struct Node *q = p -> next;
        x = q -> data;
        p -> next = NULL;
        delete q;
    }
    return x;
}

int deleteNodeAtPos(struct LinkedList *l, int pos = 1)
{
    int x = -1;
    if (!l->head)
    {
        cout << "underflow\n";
    }
    else
    {
        if(pos == 1)
        {
            x = l -> head -> data;
            struct Node *p = l -> head;
            l -> head = l -> head -> next;
            delete p;   
        }
        else
        {
            struct Node *p = l -> head;
            struct Node *q = NULL;

            for(int i = 1; (i <= pos - 1) && p; i++)
            {
                q = p;
                p = p -> next;
            }
            
            x = p -> data;
            q -> next = p -> next;
            delete p;
        }
    }
    return x;
}

int isEmpty(struct LinkedList l)
{
    return (!l.head) ? 1 : 0;
}

void displayLLI(struct LinkedList l)
{
    struct Node *p = l.head;

    while(p)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

void displayLLR(struct Node *p)
{
    if(p)
    {
        cout << p -> data << " ";
        displayLLR(p -> next);
    }
}

int main()
{
    LinkedList l;
    l.head = NULL;

    insertAtBeginning(&l, 3);
    insertAtBeginning(&l, 2);
    insertAtBeginning(&l, 1);
    
    displayLLI(l);

    insertAtEnd(&l, 4);
    insertAtEnd(&l, 5);
    insertAtEnd(&l, 6);

    displayLLR(l.head);
    cout << endl;

    insertNodeAtPos(&l, 0);
    insertNodeAtPos(&l, 7, 4);
    insertNodeAtPos(&l, 0, 8);

    displayLLR(l.head);
    cout << endl;

    deleteNodeAtBeginning(&l);

    displayLLI(l);

    deleteNodeAtEnd(&l);

    displayLLI(l);

    deleteNodeAtPos(&l, 4);

    displayLLI(l);
}