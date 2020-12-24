// Source: Udemy

#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = new Node;

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length()
{
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

void middleNode1(Node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }

    int index = (int)ceil(length / 2.0);
    Node *q = head;
    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }
    cout << "Middle Element (Method-I): " << q->data << endl;
}

void middleNode2(Node *p)
{
    Node *q = p;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q)
        {
            p = p->next;
        }
    }
    cout << "Middle Element (Method-II): " << p->data << endl;
}

void middleNode3(Node *p)
{
    stack<Node *> s;
    while (p)
    {
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int popLength = (int)(floor(length / 2.0));
    while (popLength)
    {
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
}

void Intersection(Node *p, Node *q)
{
    // Populate first stack
    stack<Node *> stk1;
    while (p != nullptr)
    {
        stk1.push(p);
        p = p->next;
    }

    // Populate second stack
    stack<Node *> stk2;
    while (q != nullptr)
    {
        stk2.push(q);
        q = q->next;
    }

    Node *r;
    while (stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout << "Intersecting Node: " << r->data << endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    l.Insert(3, 10);

    l.Display();

    return 0;
}