#include <iostream>
// 链表节点
template <typename FirstType>
class Node
{
private:
    FirstType *value;
    Node<FirstType> *last;
    Node<FirstType> *next;

public:
    Node(FirstType newvalue) : value(newvalue), last(nullptr), next(nullptr) {}
    Node(FirstType newvalue, Node<FirstType> *newlast, Node<FirstType> *newnext) : value(newvalue), last(newlast), next(newnext) {}
    ~Node();
    FirstType getvalue()
    {
        return *value;
    }
    Node<FirstType> *getnext();
    void setnext(Node<FirstType> *newnext)
    {
        next = newnext;
    }
};
template <typename FirstType>
Node<FirstType>::~Node()
{
    delete value;
}
template <typename FirstType>
Node<FirstType> *Node<FirstType>::getnext()
{
    return next;
}
// 动态链表
template <typename FirstType>
class LinkedList
{
private:
    Node<FirstType> *head;
    int limit;

public:
    LinkedList() : head(nullptr), limit(0) {}
    ~LinkedList();
    bool isEmpty();
    int size();
    void add(FirstType value);
    void print();
};
template <typename FirstType>
LinkedList<FirstType>::~LinkedList()
{
    delete[] head;
}
template <typename FirstType>
bool LinkedList<FirstType>::isEmpty()
{
    return limit == 0;
}
template <typename FirstType>
int LinkedList<FirstType>::size()
{
    return limit;
}
template <typename FirstType>
void LinkedList<FirstType>::add(FirstType value)
{
    Node<FirstType> *temp = head;
    for (int i = 0; i < limit; i++)
    {
        temp = temp->getnext();
    }
    Node<FirstType> *newnode = new Node<FirstType>(value, temp, nullptr);
    newnode->setnext(temp);
    limit++;
}
template <typename FirstType>
void LinkedList<FirstType>::print()
{
    Node<FirstType> *temp = head;
    for (int i = 0; i < limit; i++)
    {
        temp = temp->getnext();
        std::cout << temp->getvalue() << " -> ";
    }
}

int main()
{
    LinkedList<int> mylist;
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