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
// 符号表
template <typename Key, typename Value>
class ST
{
private:
    Key *KeyData;
    Value *ValueData;
    int limit;
    int capacity;

public:
    ST() : KeyData(nullptr), ValueData(nullptr), limit(0), capacity(0) {}
    ~ST()
    {
        delete KeyData;
        delete ValueData;
    }
    void put(Key key, Value value)
    {
        for (int i = 0; i < limit; i++)
        {
            if (KeyData[i] == key)
            {
                ValueData[i] = value;

                return;
            }
        }

        limit++;
        if (capacity < limit)
        {
            if (capacity)
            {
                capacity *= 2;
            }
            else
            {
                capacity++;
            }
            Key *newkeys = new Key[capacity];
            for (int i = 0; i < limit - 1; i++)
            {
                newkeys[i] = KeyData[i];
            }
            delete KeyData;
            KeyData = newkeys;
            Value *newvalues = new Value[capacity];
            for (int i = 0; i < limit - 1; i++)
            {
                newvalues[i] = ValueData[i];
            }
            delete ValueData;
            ValueData = newvalues;
        }
        KeyData[limit - 1] = key;
        ValueData[limit - 1] = value;

        return;
    }
    Value get(Key key)
    {
        for (int i = 0; i < limit; i++)
        {
            if (key == KeyData[i])
            {
                return ValueData[i];
            }
        }
    }
    bool contains(Key key)
    {
        return get(key) == null;
    }
    bool isEmpty()
    {
        return !limit;
    }
    int size
    {
        return limit;
    }
    void keys()
    {
        for (int i = 0; i < limit; i++)
        {
            std::cout << "Key: " << KeyData[i] << ", with Value: " << ValueData[i] << std::endl;
        }
    }
};
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
