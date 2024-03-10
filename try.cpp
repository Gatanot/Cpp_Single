#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    int a = 1;
    const int & const_b = a;
    cout << const_b << endl;
    a = 2;
    cout << const_b << endl;
    return 0;
}