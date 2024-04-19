#include <iostream>

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
    int *getarray()
    {
        return data;
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
    int getIndex(int i)
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
    void heapSort()
    {
        int temp = size;
        for (int i = temp; i >= 2; i--)
        {
            exchange(data, 0, i - 1);
            size--;
            maxHeapify(data, 1);
        }
        size=temp;
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
    myheap.heapSort();
    myheap.print();
}