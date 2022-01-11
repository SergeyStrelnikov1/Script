#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() 
{
    string input;
    cout << "Break: 1" << endl;
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
        cout << i.first << " " << (float(i.second / count) * 100) << "%" << endl;
    }
}