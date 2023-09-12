#include <iostream>
using namespace std;

int main(void)
{
    char chara = 'a';
    cout << chara << " is " << (int)chara << '\n';
    while (chara != 'z')
    {
        chara = chara + 1;
        cout << chara << " is " << (int)chara << '\n';
    }
    return 0;
}