#include <vector>

template <typename FirstType>
class SORT
{
private:
    void exchange(FirstType *array, int i, int j);
    void exchange(std::vector<FirstType> &array, int i, int j);

public:
    SORT(void);

    void selection(FirstType *array, int length);
    void selection(std::vector<FirstType> &array);
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