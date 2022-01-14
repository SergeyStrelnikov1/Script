#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() 
{
    string input;
    map<string, int> mp;

    double count = 0;
    while (cin >> input)
    {
        if (input == "1") 
        {
            break;
        }
        count++;
        if (mp.find(input) == mp.end()) 
        {
            mp[input] = 1;
        }
        else
        {
            mp[input] += 1;
        }
    }

    for (auto i : mp) 
    {
        cout << i.first << " " << (double(i.second / count) * 100) << "%" << endl;
    }
}