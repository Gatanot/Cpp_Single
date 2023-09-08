#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    // 05.06
    int count = 0;
    string pre = "";
    string current;
    while (cin >> current)
    {
                    count++;
        if (pre == current)
        {

            cout << "word number" << count << "repeated word:" << current << "\n";
        }
        pre = current;
    }

    return 0;
}