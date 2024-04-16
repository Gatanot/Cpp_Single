#include <iostream>
// 链表节点

class Node
{
private:
    int value;
    Node *last;
    Node *next;

public:
    Node(int newvalue) : value(newvalue), last(nullptr), next(nullptr)
    {
    }
    Node(int newvalue, Node *newlast, Node *newnext) : value(newvalue), last(newlast), next(newnext) {}
    ~Node();
    int getvalue()
    {
        return value;
    }
    Node *getnext();
    void setnext(Node *newnext)
    {
        next = newnext;
    }
};

Node::~Node()
{
    ;
}

Node *Node::getnext()
{
    return next;
}
// 动态链表

class LinkedList
{
private:
    Node *head;
    int limit;

public:
    LinkedList() : head(nullptr), limit(0) {}
    ~LinkedList();
    bool isEmpty();
    int size();
    void add(int value);
    void print();
};

LinkedList::~LinkedList()
{
    delete[] head;
}

bool LinkedList::isEmpty()
{
    return limit == 0;
}

int LinkedList::size()
{
    return limit;
}

void LinkedList::add(int value)
{
    Node *temp = head;
    for (int i = 0; i < limit; i++)
    {
        temp = temp->getnext();
    }
    Node *newnode = new Node(value, temp, nullptr);
    temp->setnext(newnode);
    limit++;
}

void LinkedList::print()
{
    Node *temp = head;
    for (int i = 0; i < limit; i++)
    {
        temp = temp->getnext();
        std::cout << temp->getvalue() << " -> ";
    }
}

int main()
{
    LinkedList mylist;
    std::cout << mylist.size() << " " << mylist.isEmpty() << std::endl;
    for (int i = 0; i < 4; i++)
    {
        mylist.add(i);
    }
    std::cout << std::endl;
    std::cout << mylist.size() << " " << mylist.isEmpty() << std::endl;
    mylist.print();

    return 0;
}