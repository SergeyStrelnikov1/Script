#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    set<string> st;
    string input = "";
    cout << "Break: exit" << endl;
    while (true) {
        cout << "Login: " << endl;
        cin >> input;
        if (input == "exit") {
            break;
        }

        if (st.empty() || st.find(input) == st.end()) {
            cout << "Login True: " << input << endl << endl;
            st.insert(input);
        }
        else {
            cout << "Login False: " << input << endl << endl;
        }
    }
}