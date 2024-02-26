#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include<iterator>

using namespace std;

int main(void)
{
    ifstream input("data.txt");
    vector<double> numvector;
    double numin;
    while (input >> numin)
    {
        numvector.push_back(numin);
        cout << numin << endl;
    }
    cout << endl;
    cout << accumulate(numvector.begin(), numvector.end(), 0.0) / numvector.size() << endl;
    cout << endl;

    // Reordering Algorithms
    sort(numvector.begin(), numvector.end());

    for (vector<double>::iterator itr = numvector.begin(); itr != numvector.end(); ++itr)
    {
        cout << *itr << endl;
    }
    cout << endl;

    rotate(numvector.begin(), numvector.begin() + 2, numvector.end());

    for (vector<double>::iterator itr = numvector.begin(); itr != numvector.end(); ++itr)
    {
        cout << *itr << endl;
    }
    cout << endl;

    random_shuffle(numvector.begin(), numvector.end());

    for (vector<double>::iterator itr = numvector.begin(); itr != numvector.end(); ++itr)
    {
        cout << *itr << endl;
    }
    cout << endl;

    // Searching Algorithms
    if (find(numvector.begin(), numvector.end(), 137) != numvector.end())
    {
        cout << "data contain 137" << endl;
    }
    else
    {
        cout << "data don't contain 137" << endl;
    }
    cout << endl;

    sort(numvector.begin(), numvector.end());
    if (binary_search(numvector.begin(), numvector.end(), 137))
    {
        cout << "data contain 137" << endl;
    }
    else
    {
        cout << "data don't contain 137" << endl;
    }
    cout << endl;
    for (vector<double>::iterator itr = numvector.begin(); itr != numvector.end(); ++itr)
    {
        cout << *itr << endl;
    }
    cout << endl;

    vector<double> numvectorcopy;
    copy(numvector.begin(), numvector.end(), numvectorcopy.begin());
    for (vector<double>::iterator itr = numvectorcopy.begin(); itr != numvectorcopy.end(); ++itr)
    {
        cout << *itr << endl;
    }
    
    return 0;
}