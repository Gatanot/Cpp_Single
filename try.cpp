#include <iostream>
using namespace std;
void test(int *&p)
{
    int a = 2024;
    p = &a;
    cout << p << " " << *p << endl;
}

int main(void)
{
    int *p = NULL;
    test(p);
    if (p != NULL)
        cout << "指针p不为NULL" << endl;
    return 0;
}