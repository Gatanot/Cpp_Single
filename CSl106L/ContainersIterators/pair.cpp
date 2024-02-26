#include <iostream>
#include <string.h>
#include <utility>

using namespace std;

int main(void)
{
    pair<int, string> PairOne;
    PairOne.first = 137;
    PairOne.second = "fuck you nvdia";
    pair<int, string> PairTwo = make_pair(137, "NVDIA");
    cout << PairOne.first << "\n"
         << PairOne.second << "\n"
         << PairTwo.first << "\n"
         << PairTwo.second << endl;
}