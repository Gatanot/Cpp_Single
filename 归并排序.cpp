#include <iostream>
#include <limits.h>
using namespace std;

void MergeSort(int *numlist, int left, int right);
void Merge(int *numlist, int left, int mid, int right);
int main()
{
    int n;
    cout << "enter the number ofnumbers:" << endl;
    cin >> n;
    int numlist[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> numlist[i];
    }

    MergeSort(&numlist[1], 1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << numlist[i] << " ";
    }
    cout << endl;

    return 0;
}
void MergeSort(int *numlist, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(numlist, left, mid);
        MergeSort(numlist, mid + 1, right);
        Merge(numlist, left, mid, right);
    }
}
void Merge(int *numlist, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1 + 2], R[n2 + 2];
    for (int i = 1; i < n1 + 1; i++)
    {
        L[i] = numlist[left + i - 1];
    }
    for (int i = 1; i < n2 + 1; i++)
    {
        R[i] = numlist[mid + i];
    }
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    int i = 1, j = 1;
    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            numlist[k] = L[i];
            i++;
        }
        else
        {
            numlist[k] = R[j];
            j++;
        }
    }
}