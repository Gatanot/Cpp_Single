#include <iostream>
// 链表节点

class Node
{
private:
    int value;
    Node *next;

public:
    Node(int newvalue) : value(newvalue), next(nullptr) {}
    Node(int newvalue, Node *newnext) : value(newvalue), next(newnext) {}
    ~Node() {}
    int getvalue()
    {
        return value;
    }
    Node *getnext()
    {
        return next;
    }
    void setnext(Node *newnext)
    {
        next = newnext;
    }
};

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
    ~LinkedList()
    {
        delete[] head;
    }
    bool isEmpty()
    {
        return limit == 0;
    }
    int size()
    {
        return limit;
    }
    void add_front(int value)
    {
        std::cout << "add from " << limit;
        // 创建newnode后为temp的next添加出错
        head->setnext(new Node(value, head->getnext()));
        limit++;
        std::cout << " to " << limit << std::endl;
    }
    void print()
    {
        Node *temp = head;
        for (int i = 0; i < limit; i++)
        {
            temp = temp->getnext();
            std::cout << temp->getvalue() << " -> ";
        }
    }
};
int main()
{
    LinkedList mylist;
    std::cout << mylist.size() << " " << mylist.isEmpty() << std::endl;
    for (int i = 0; i < 4; i++)
    {
        mylist.add_front(i);
    }
    std::cout << std::endl;
    std::cout << mylist.size() << " " << mylist.isEmpty() << std::endl;
    mylist.print();

    return 0;
}