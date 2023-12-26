#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void similar()
{
    string s;
    int n;
    cin >> n;
    string t[n];
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    int count = 0, min = 50, num = 0;
    vector<int> mark;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < (t[i]).length(); i++)
        {
            for (int k = 0; k < s.length(); k++)
            {
                if (t[i][j] == s[k])
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            num = t[i].size() + s.size();
        }
        else
        {
            num = t[i].size() + s.size() - count;
        }
        if (min < num)
        {
            min = num;
            mark = {};
            mark.push_back(i);
        }
        else if (min == num)
        {
            mark.push_back(i);
        }
    }
    for (int i = 0; i < mark.size(); i++)
    {
        cout << t[mark[i]];
    }
}