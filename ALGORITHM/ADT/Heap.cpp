#include <iostream>
//算法导论第六章，堆排序
//堆、维护堆的性质、建堆、堆排序算法、优先队列
class Heap
{
private:
    int *data;
    int size;
    int capacity;

public:
    Heap() : data(nullptr), size(0), capacity(0) {}
    Heap(int *array, int len)
    {
        for (int i = 0; i < len; i++)
        {
            data[i] = array[i];
        }
        size = len;
        capacity = len;
    }
    ~Heap()
    {
        delete data;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void setSize(int newsize)
    {
        size = newsize;
    }
    void exchange(int *array, int a, int b)
    {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
    int getsize()
    {
        return size;
    }
    int getcapacity()
    {
        return capacity;
    }
    void add(int value)
    {
        size++;
        if (size > capacity)
        {
            if (capacity)
            {
                capacity *= 2;
            }
            else
            {
                capacity++;
            }
            int *temp = new int[capacity];
            for (int i = 0; i < size - 1; i++)
            {
                temp[i] = data[i];
            }
            temp[size - 1] = value;
            delete data;
            data = temp;
        }
        else
        {
            data[size - 1] = value;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    int get(int i)
    {
        return data[i - 1];
    }
    int parentIndex(int i)
    {
        return i / 2;
    }
    int left(int i)
    {
        return 2 * i;
    }
    int right(int i)
    {
        return 2 * i + 1;
    }
    void maxHeapify(int *array, int index)
    {
        int l = left(index);
        int r = right(index);
        int largest = 0;
        if (l <= size && array[l - 1] > array[index - 1])
        {
            largest = l;
        }
        else
        {
            largest = index;
        }
        if (r <= size && array[r - 1] > array[largest - 1])
        {
            largest = r;
        }
        if (largest != index)
        {
            exchange(array, index - 1, largest - 1);
            maxHeapify(array, largest);
        }
    }
    void buildMaxHeap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            maxHeapify(data, i);
        }
    }
    void sort()
    {
        int temp = size;
        for (int i = temp; i >= 2; i--)
        {
            exchange(data, 0, i - 1);
            size--;
            maxHeapify(data, 1);
        }
        size = temp;
    }
    void set(int index, int value)
    {
        if (index >= 1 && index <= size)
        {
            data[index - 1] = value;
        }
        else
        {
            std::cout << "error: index overflow";
        }
    }
};
class PriorityQueue
{
private:
    Heap *data = nullptr;

public:
    PriorityQueue()
    {
        data = new Heap;
    };
    PriorityQueue(int *array, int len)
    {
        data = new Heap(array, len);
    }
    ~PriorityQueue()
    {
        delete[] data;
    }
    void insert(int value)
    {
        data->add(value);
    }
    void buildMaximum()
    {
        data->buildMaxHeap();
    }
    int maximum()
    {
        return data->get(1);
    }
    int extract_max()
    {
        int max = data->get(1);
        data->set(1, data->get(data->getsize()));
        data->setSize(data->getsize() - 1);
        data->buildMaxHeap();
        return max;
    }
    void increase_key(int index, int value)
    {
        if (value < data->get(index))
        {
            std::cout << "error: new value is smaller than current one";
        }
        else
        {
            data->set(index, value);
            data->buildMaxHeap();
        }
    }
    void print()
    {
        data->print();
    }
};

int main()
{
    Heap myheap;
    std::cout << myheap.getsize() << std::endl;
    for (int i = 0; i < 41; i++)
    {
        myheap.add(i);
    }
    myheap.print();
    myheap.buildMaxHeap();
    myheap.print();
    myheap.sort();
    myheap.print();

    PriorityQueue mypq;
    for (int i = 0; i < 41; i++)
    {
        mypq.insert(i);
    }
    mypq.print();
    mypq.buildMaximum();
    mypq.print();
    mypq.extract_max();
    mypq.print();
    return 0;
}