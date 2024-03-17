#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "SortFunctions.cpp"
using namespace std;
int main(void)
{
    int array[] = {6546, 54, 2, 651656, 648, 64, 8894, 65498, 564, 546, 849, 654984, 984, 9847};
    SORT<int> intsort;
    intsort.sort(array, 14);
    for (int i = 0; i < 14; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}