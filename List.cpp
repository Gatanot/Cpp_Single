#include <iostream>

template <typename FirstType>
class List
{
private:
    FirstType *data;
    int size;
    int capacity;

public:
    List() : data(nullptr), size(0), capacity(0) {}
    ~List()
    {
        delete[] data;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insert(FirstType value)
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
        }
        FirstType *newdata = new FirstType[capacity];
        for (int i = 0; i < size - 1; i++)
        {
            newdata[i] = data[i];
        }
        newdata[size] = value;
        delete[] data;
        data = newdata;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << std::endl;
        }
    }
};

int main()
{
    List<int> mylist;
    for (int i = 0; i < 10; i++)
    {
        mylist.insert(i);
    }
    mylist.print();

    return 0;
}