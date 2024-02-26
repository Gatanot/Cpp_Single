#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int main(void)
{
    map<string, int> MapOne;
    MapOne["zero"] = 0;
    MapOne["one"] = 1;
    MapOne["two"] = 2;
    cout << MapOne["zero"] << "\n"
         << MapOne["two"] * MapOne["one"] << endl;

    map<string, int>::iterator itr1 = MapOne.find("three");
    if (itr1 == MapOne.end())
    {
        cout << "key does not in map" << endl;
    }
    else
    {
        cout << "success" << endl;
    }
    cout<<endl;

    // map的iterator解引用后得到的是pair<key,value>
    MapOne["three"] = 3;
    map<string, int>::iterator itr2 = MapOne.find("three");
    if (itr2 == MapOne.end())
    {
        cout << "key does not in map" << endl;
    }
    else
    {
        cout << "the key " << itr2->first
             << " has the vakue " << itr2->second << endl;
    }
    cout<<endl;

    // 显然，map中作为key的string是以字母顺序排列的
    // 当map中本存在key时，insert是无效的
    MapOne.insert(make_pair("four", 4));
    map<string, int>::iterator itr3 = MapOne.begin();
    for (itr3 = MapOne.begin(); itr3 != MapOne.end(); itr3++)
    {
        cout << "the key " << itr3->first
             << " has the value " << itr3->second
             << endl;
    }
    cout<<endl;

    multimap<string, int> MapTwo;
    MapTwo.insert(make_pair("zere", 0));
    MapTwo.insert(make_pair("one", 1));
    MapTwo.insert(make_pair("two", 2));
    MapTwo.insert(make_pair("zere", 5));
    MapTwo.insert(make_pair("zere", 6));
    multimap<string, int>::iterator itr4 = MapTwo.begin();
    for (itr4 = MapTwo.begin(); itr4 != MapTwo.end(); ++itr4)
    {
        cout << "the key " << itr4->first
             << " has the value " << itr4->second
             << endl;
    }
    cout<<endl;
    pair<multimap<string, int>::iterator, multimap<string, int>::iterator> myPair = MapTwo.equal_range("zero");
    for (multimap<string, int>::iterator itr = myPair.first; itr != myPair.second; ++itr)
    {
        cout << itr->first << ":" << itr->second << endl;
    }


    return 0;
}