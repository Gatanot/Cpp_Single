#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void fileio(string filename);
void StreamManipulators(string filename);
void capital(string filename);

int main(void)
{
    fileio("note.txt");
    cout << endl;
    StreamManipulators("4r3l_table_data.txt");
    cout << endl;
    capital("world-capitals.txt");
    return 0;
}

void fileio(string filename)
{
    ifstream mystream(filename);
    ofstream outstream(filename);
    outstream << "24680" << endl;
    if (!mystream.is_open())
    {
        cerr << "could not open" << endl;
    }
    if (mystream.is_open())
    {
        int myinteger;
        mystream >> myinteger;
        cout << myinteger << endl;
    }
}
void StreamManipulators(string filename)
{
    ifstream mystream(filename);
    int a;
    double b;
    for (int i = 0; i < 4; i++)
    {
        mystream >> a >> b;
        cout << a << '\t' << b << endl;
    }
}
void capital(string filename)
{
    ifstream mystream(filename);
    string cap, country;
    while (getline(mystream, cap) && getline(mystream, country))
    {
        cout << cap << " is the capital of " << country << endl;
    }
}