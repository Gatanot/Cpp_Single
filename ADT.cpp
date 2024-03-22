// 无索引链表节点
template <typename FirstType>
class Node
{
private:
    FirstType value;
    Node<FirstType> *next;
    Node<FirstType> *last;

public:
    Node(FirstType item);
};
template <typename FirstType>
Node<FirstType>::Node(FirstType item)
{
    value = item;
    next = nullptr;
    last = nullptr;
}

// 无索引列表
template <typename FirstType>
class LinkedList
{
private:
    Node<FirstType> *head;

public:
    LinkedList();
    ~LinkedList();
    void add(FirstType item);    // 在head后添加元素
    bool find(FirstType item);   // 在链表中查找item
    bool remote(FirstType item); // 在链表中移除item
    bool isEmpty();              // 检查是否为空
    int size();                  // 返回链表长度
};
template <typename FirstType>
LinkedList<FirstType>::LinkedList()
{
    head->next = nullptr;
    head->last = nullptr;
}
template <typename FirstType>
LinkedList<FirstType>::~LinkedList()
{
    while (head->next != nullptr)
    {
        head = head->next;
    }
    while (head->last != nullptr)
    {
        head = head->last;
        delete head->next;
    }
    delete head;
}
template <typename FirstType>
void LinkedList<FirstType>::add(FirstType item)
{
    new Node<FirstType> *newnode;
    newnode->value = item;
    newnode->next = head->next;
    newnode->last = head;
    (newnode->next)->last = newnode;
}
template <typename FirstType>
bool LinkedList<FirstType>::find(FirstType item)
{
    bool flag = false;
    Node<FirstType> *origin = head;
    while (head->next != nullptr)
    {
        head = head->next;
        if (head->value == item)
        {
            flag = true;
            break;
        }
    }
    if (head->value == item)
    {
        flag = true;
    }
    head = origin;
    delete origin;
    return flag;
}
template <typename FirstType>
bool LinkedList<FirstType>::remote(FirstType item)
{
    bool flag = flase;
    Node<FirstType> *origin = head;
    while (head->next != nullptr)
    {
        head = head->next;
        if (head->value == item)
        {
            flag = true;
            head->last = head->next;
            (head->next)->last = head->last;
            break;
        }
    }
    if (head->value == item)
    {
        flag = true;
        head->last = nullptr;
    }
    head = origin;
    delete origin;
    return flag;
}
template <typename FirstType>
bool LinkedList<FirstType>::isEmpty()
{
    if (head->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename FirstType>
int LinkedList<FirstType>::size()
{
    int count = 0;
    while (head->next != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}
// 背包
template <typename FirstType>
class Bag
{
private:
public:
    Bag(); // 创建空背包
    ~Bag();
    void add(FirstType item); // 添加一个元素
    bool isEmpty();           // 检查背包是否为空
    int size();               // 元素数量
    void print();             // 输出背包中所有元素
};
template <typename FirstType>
Bag<FirstType>::Bag()
{
}
template <typename FirstType>
Bag<FirstType>::~Bag()
{
}
template <typename FirstType>
void Bag<FirstType>::add(FirstType item)
{
}
template <typename FirstType>
bool Bag<FirstType>::isEmpty()
{
}
template <typename FirstType>
int Bag<FirstType>::size()
{
}
template <typename FirstType>
void Bag<FirstType>::print()
{
}

// FIFO队列
template <typename FirstType>
class Queue
{
private:
public:
    Queue(); // 创建空队列
    ~Queue();
    void enqueue(FirstType item); // 添加一个元素
    FirstType dequeue();          // 删除最早添加的元素；
    bool isEmpty();               // 检查队列是否为空
    int size();                   // 返回元素数量
};
template <typename FirstType>
Queue<FirstType>::Queue()
{
}
template <typename FirstType>
Queue<FirstType>::~Queue()
{
}
template <typename FirstType>
void Queue<FirstType>::enqueue(FirstType item)
{
}
template <typename FirstType>
FirstType Queue<FirstType>::dequeue()
{
}
template <typename FirstType>
bool Queue<FirstType>::isEmpty()
{
}
template <typename FirstType>
int Queue<FirstType>::size()
{
}

// LIFO栈
template <typename FirstType>
class Stack
{
private:
public:
    Stack(); // 创建空栈
    ~Stack();
    void push(FirstType item); // 添加元素
    FirstType pop();           // 删除最近添加的元素
    bool isEmpty();            // 检查是否为空
    int size();                // 返回元素数量
};
template <typename FirstType>
Stack<FirstType>::Stack()
{
}
template <typename FirstType>
Stack<FirstType>::~Stack()
{
}
template <typename FirstType>
void Stack<FirstType>::push(FirstType item)
{
}
template <typename FirstType>
FirstType Stack<FirstType>::pop()
{
}
template <typename FirstType>
bool Stack<FirstType>::isEmpty()
{
}
template <typename FirstType>
int Stack<FirstType>::size()
{
}

// 优先队列
template <typename FirstType>
class MaxPQ
{
private:
public:
    MaxPQ();                             // 创建一个优先队列
    MaxPQ(int max);                      // 创建一个初始容量为max的优先队列
    MaxPQ(FirstType *array, int length); // 用数组a中的元素创建
    MaxPQ(std::vector<FirstType> &array);
    void insert(FirstType item); // 插入元素
    FirstType max();             // 返回最大元素
    FirstType delMax();          // 删除并返回最大元素
    bool isEmpty();
    int size(); // 返回元素个数
};

template <typename FirstType>
MaxPQ<FirstType>::MaxPQ()
{
}
