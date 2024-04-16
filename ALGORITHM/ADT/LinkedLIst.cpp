// 链表节点
template <typename FirstType>
class Node
{
private:
    FirstType *value;
    Node *last;
    Node *next;

public:
    Node(FirstType newvalue) : value(newvalue), last(nullptr), next(nullptr);
    ~Node();
};
template <typename FirstType>
Node<FirstType>::~Node()
{
    delete value;
}

// 动态链表
template <typename FirstType>
class LinkedList
{
private:
    Node<FirstType> *head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
};
template <typename FirstType>
LinkedList<FirstType>::~LinkedList()
{
    delete[] head;
}