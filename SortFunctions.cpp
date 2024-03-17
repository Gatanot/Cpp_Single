#include <vector>
// 排序功能的类集合。声明时需要附带数据类型，提供对数组和vector的升序排序
template <typename FirstType>
class SORT
{
private:
    // 归并排序的临时数组
    std::vector<FirstType> temparray;
    // 交换index为i与j的两个元素
    void exchange(FirstType *array, int i, int j);
    void exchange(std::vector<FirstType> &array, int i, int j);
    // 自顶向下归并排序中sort与merge的实现
    void sort(FirstType *array, int left, int right);
    void merge(FirstType *array, int left, int mid, int right);
    void sort(std::vector<FirstType> array, int left, int right);
    void merge(std::vector<FirstType> array, int left, int mid, int right);

public:
    SORT(void);

    // 选择排序
    void selection(FirstType *array, int length);
    void selection(std::vector<FirstType> &array);
    // 插入排序
    void insertion(FirstType *array, int length);
    void insertion(std::vector<FirstType> &array);
    // 希尔排序,h序列采用1/2(3^k-1)
    void shell(FirstType *array, int length);
    void shell(std::vector<FirstType> &array);
    // 自顶向下归并排序
    // 从实现上来看，归并排序似乎不适合作为一个类下的函数，或许做一个单独的类会更好些
    // 不一定，或许可以试一下
    void sort(FirstType *array, int length);
    void sort(std::vector<FirstType> &array);
};

template <typename FirstType>
void SORT<FirstType>::exchange(FirstType *array, int i, int j)
{
    array[i] = array[i] ^ array[j];
    array[j] = array[i] ^ array[j];
    array[i] = array[i] ^ array[j];
}
template <typename FirstType>
void SORT<FirstType>::exchange(std::vector<FirstType> &array, int i, int j)
{
    array[i] = array[i] ^ array[j];
    array[j] = array[i] ^ array[j];
    array[i] = array[i] ^ array[j];
}
template <typename FirstType>
void SORT<FirstType>::sort(std::vector<FirstType> array, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    sort(array, left, mid);
    sort(array, mid + 1, right);
    merge(array, left, mid, right);
}
template <typename FirstType>
void SORT<FirstType>::merge(std::vector<FirstType> array, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        temparray[k] = array[k];
    }
    for (int k = left; k <= right; k++)
    {
        if (i > mid)
        {
            array[k] = temparray[j++];
        }
        else if (j > right)
        {
            array[k] = temparray[i++];
        }
        else if (temparray[j] < temparray[i])
        {
            array[k] = temparray[j++];
        }
        else
        {
            array[k] = temparray[i++];
        }
    }
}
template <typename FirstType>
void SORT<FirstType>::sort(FirstType *array, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    sort(array, left, mid);
    sort(array, mid + 1, right);
    merge(array, left, mid, right);
}
template <typename FirstType>
void SORT<FirstType>::merge(FirstType *array, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        temparray[k] = array[k];
    }
    for (int k = left; k <= right; k++)
    {
        if (i > mid)
        {
            array[k] = temparray[j++];
        }
        else if (j > right)
        {
            array[k] = temparray[i++];
        }
        else if (temparray[j] < temparray[i])
        {
            array[k] = temparray[j++];
        }
        else
        {
            array[k] = temparray[i++];
        }
    }
}

template <typename FirstType>
SORT<FirstType>::SORT(void)
{
    return;
}

template <typename FirstType>
void SORT<FirstType>::selection(FirstType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                exchange(array, i, j);
            }
        }
    }
}
template <typename FirstType>
void SORT<FirstType>::selection(std::vector<FirstType> &array)
{
    for (long long unsigned int i = 0; i < array.size(); i++)
    {
        for (long long unsigned int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[i])
            {
                exchange(array, i, j);
            }
        }
    }
}

template <typename FirstType>
void SORT<FirstType>::insertion(FirstType *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0 && (array[j] < array[j - 1]); j--)
        {
            exchange(array, j, j - 1);
        }
    }
}
template <typename FirstType>
void SORT<FirstType>::insertion(std::vector<FirstType> &array)
{
    for (long long unsigned int i = 0; i < array.size(); i++)
    {
        for (long long unsigned int j = i; j > 0 && (array[j] < array[j - 1]); j--)
        {
            exchange(array, j, j - 1);
        }
    }
}

template <typename FirstType>
void SORT<FirstType>::shell(FirstType *array, int length)
{
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && array[j] < array[j - 1]; j -= h)
            {
                exchange(array, j, j - 1);
            }
        }
        h /= 3;
    }
}
template <typename FirstType>
void SORT<FirstType>::shell(std::vector<FirstType> &array)
{
    int length = array.size();
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && array[j] < array[j - 1]; j -= h)
            {
                exchange(array, j, j - 1);
            }
        }
        h /= 3;
    }
}

template <typename FirstType>
void SORT<FirstType>::sort(FirstType *array, int length)
{
    temparray.resize(length);
    sort(array, 0, length - 1);
}
template <typename FirstType>
void SORT<FirstType>::sort(std::vector<FirstType> &array)
{
    temparray.resize(array.size());
    sort(array, 0, array.size() - 1);
}
