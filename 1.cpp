#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int numlist[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numlist[i];
    }
    int begin = n, end, mark1 = 0, mark2 = 0;
    ;
    vector<int> list;
    list.push_back(numlist[n - 1]);
    for (int i = n - 1; i > 0; i--)
    {
        if (numlist[i] <= numlist[i - 1])
        {
            end = i - 1;
            if ((begin - end) > list.size())
            {
                mark1 = begin;
                mark2 = end;
            }
        }
        else
        {
            begin = i - 1;
        }
    }
    for (int i = mark2; i < mark1; i++)
    {
        list.push_back(numlist[i]);
    }
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
}
