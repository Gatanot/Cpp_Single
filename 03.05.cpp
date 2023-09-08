#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    string pre = "";
    string current;
    while (cin >> current)
    {
        if (pre == current)
        {
            cout << "repeated word:" << current << "\n";
        }
        pre = current;
    }

    return 0;
}