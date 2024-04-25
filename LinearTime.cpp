// 比较排序：在排序的最终结果中，各元素的次序依赖于它们之间的比较。任何计较排序在最坏排序下都要经历nlgn次比较
#include <iostream>
// 所有的输入都是0到k之间的整数
class Counting
{
private:
    int *temp = nullptr;
    int *A = nullptr;
    int lenthA = 0;
    int *B = nullptr;
    int lenthB = 0;
    int k = 0;

public:
    Counting() : temp(nullptr) {}
    Counting(int *arrayA, int lenA, int *arrayB, int lenB, int k)
    {
        A = arrayA;
        lenthA = lenA;
        B = arrayB;
        lenthB = lenB;
        temp = new int[k + 1];
        this->k = k;
    }
    void sort()
    {
        for (int i = 0; i <= k; i++)
        {
            temp[i] = 0;
        }
        for (int i = 1; i < lenthA; i++)
        {
            temp[A[i]] = temp[A[i]] + 1;
        }
        for (int i = 1; i <= k; i++)
        {
            temp[i] = temp[i] + temp[i - 1];
        }
        for (int i = lenthA; i >= 1; i--)
        {
            B[temp[A[i]]] = A[i];
            temp[A[i]] = temp[A[i]] - 1;
        }
    }
    ~Counting()
    {
        delete[] temp;
    }
};
