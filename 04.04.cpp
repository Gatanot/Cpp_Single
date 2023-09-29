#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (int x : v)
    {
        cout << x << '\n';
    }
    v.push_back(7);
    cout<<v[6];

    return 0;
}