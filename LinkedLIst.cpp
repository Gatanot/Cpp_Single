#include <iostream>
// 链表节点

class Node
{
private:
    int value;
    Node *next;

public:
    Node(int newvalue) : value(newvalue), next(nullptr)
    {
    }
    Node(int newvalue, Node *newnext) : value(newvalue), next(newnext) {}
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
    LinkedList() : head(nullptr), limit(0)
    {
        std::cout << "build right" << std::endl;
    }
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
    std::cout << "add from " << limit;
    Node *temp = head;
    for (int i = 0; i < limit; i++)
    {
        temp = temp->getnext();
    }
    Node *newnode = new Node(value, nullptr);
    // 创建newnode后为temp的next添加出错
    temp->setnext(newnode);
    limit++;
    std::cout << " to " << limit << std::endl;
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