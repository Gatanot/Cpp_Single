//算法导论第七章，快速排序
//快速排序的描述，快速排序的性能，快速排序的随机化版本，快速排序分析
#include <iostream>
class QuickSort
{
private:
    int *data = nullptr;
    int begin = 0;
    int end = 0;

public:
    QuickSort() : data(nullptr), begin(0), end(0) {}
    QuickSort(int *array, int begin, int end)
    {
        data = array;
        this->begin = begin;
        this->end = end;
    }
    void sort()
    {
        sort(data, begin, end);
    }
    void sort(int *array, int l, int r)
    {
        if (l < r)
        {
            int m = partition(array, l, r);
            sort(array, l, m - 1);
            sort(array, m + 1, r);
        }
    }
    int partition(int *array, int l, int r)
    {
        int x = array[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++)
        {
            if (array[j] <= x)
            {
                i++;
                exchange(array, i, j);
            }
        }
        exchange(array, i + 1, r);
        return i + 1;
    }
    void exchange(int *array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    void print()
    {
        for (int i = begin; i <= end; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    ~QuickSort()
    {
        if (data == nullptr)
        {
            ;
        }
        else
        {
            data = nullptr;
        }
        delete[] data;
    }
};

int main()
{
    int lis[11];
    for (int i = 10; i >= 0; i--)
    {
        lis[10 - i] = i;
    }
    QuickSort list(lis, 0, 10);
    list.print();
    list.sort();
    list.print();

    return 0;
}