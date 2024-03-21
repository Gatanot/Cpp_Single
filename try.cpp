#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "SortFunctions.cpp"
using namespace std;
int main(void)
{
    int numlist[] = {654, 46, 56, 213, 6546, 5616, 6548, 651, 684869, 564, 645};
    SORT<int> intsort;
    intsort.merge(numlist, 11);

    for (int i = 0; i < 11; i++)
    {
        cout << numlist[i] << " ";
    }
    cout << endl;
    return 0;
}