#include <iostream>
#include <string>
#include <vector>
#include "SortFunctions.cpp"
using namespace std;

int main()
{
    int number[7] = {231, 423, 1345, 344, 23, 546, 324};
    vector<int> numlist = {213, 43, 75, 234, 456, 234, 65};

    SORT<int> sortlist;
    for (int i = 0; i < 7; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
    sortlist.shell(number, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < 7; i++)
    {
        cout << numlist[i] << " ";
    }
    cout << endl;
    sortlist.shell(numlist);
    for (size_t i = 0; i < 7; i++)
    {
        cout << numlist[i] << " ";
    }
    cout << endl;
    return 0;
}

