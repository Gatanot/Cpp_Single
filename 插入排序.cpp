#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number ofnumbers:" << endl;
    cin >> n;
    int numlist[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> numlist[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int key = numlist[i];
        int j = i - 1;
        while (j >= 0 && numlist[j] > key)
        {
            numlist[j + 1] = numlist[j];
            j = j - 1;
        }
        numlist[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << numlist[i] << " ";
    }
    cout << endl;
    return 0;
}