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
// 符号表
template <typename Key, typename Value>
class ST
{
private:
    Key *KeyData;
    Value *ValueData;
    int limit;

public:
    ST() : KeyData(nullptr), ValueData(nullptr), limit(0);
    ~ST();
    void put(Key key, Value value);
    Value get(Key key);
    bool contains(Key key);
    bool isEmpty();
    int size;
    void keys();
};
template <typename Key, typename Value>
ST<Key, Value>::~ST()
{
    delete KeyData;
    delete ValueData;
}
template <typename Key, typename Value>
void ST<Key, Value>::put(Key key, Value value)
{
    for (int i = 0; i < limit; i++)
    {
        if (KeyData[i] == key)
        {
            ValueData[i] = value;

            return;
        }
    }
}