#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    set<string> st;
    string input = "";
    while (true)
    {
        cout << "Login: " << endl;
        cin >> input;
        if (st.find(input) == st.end())
        {
            cout << "Login True: " << input << endl << endl;
            st.insert(input);
        }
        else 
        {
            cout << "Login False: " << input << endl << endl;
        }
    }
}
