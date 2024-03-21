// 无需链表节点
template <typename FirstType>
class Node
{
private:
    FirstType value;
    FirstType *next;

public:
    Node();
    ~Node();
};
template <typename FirstType>
Node<FirstType>::Node()
{
    next = nullptr;
}
template <typename FirstType>
Node<FirstType>::~Node()
{
}

// 无索引列表
template <typename FirstType>
class LinkedList
{
private:
    Node head;

public:
    LinkedList();
    ~LinkedList();
};
template <typename FirstType>
LinkedList<FirstType>::LinkedList()
{
}
template <typename FirstType>
LinkedList<FirstType>::~LinkedList()
{
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
