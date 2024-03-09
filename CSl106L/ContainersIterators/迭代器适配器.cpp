#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int mian(void)
{
    /* Declare an ostream_iterator that writes ints to cout. */
    ostream_iterator<int> myItr(cout, " ");
    /* Write values to the iterator. These values will be printed to cout. */
    *myItr = 137; // Prints 137 to cout
    ++myItr;
    *myItr = 42; // Prints 42 to cout
    ++myItr;

    // 将IA作为一般I使用
    vector<int> myvector = {23, 2432, 56, 124, 7, 342, 65};
    copy(myvector.begin(), myvector.end(), ostream_iterator<int>(cout, " "));
    return 0;
}