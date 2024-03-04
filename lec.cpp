#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    double myfloat = 123.4578;
    int myint = 5;
    cout << fixed << showpoint << setprecision(3);
    cout << setw(10) << left << "float"
         << setw(12) << right << myfloat << endl;
    cout << setw(10) << left << "int"
         << setw(12) << right << myint << endl;

    const char *cout = "hello world";
    std::cout << (cout + 1) << endl;

    return 0;
}
