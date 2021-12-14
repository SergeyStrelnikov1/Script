#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool check(stack<char> stk, string input)
{
   for (int i = 0; i < input.size(); i++)
   {
        if (input[i] == '(' or input[i] == '{' or input[i] == '[')
        {
            stk.push(input[i]);
        }
        else if (input[i] == ')' or input[i] == '}' or input[i] == ']')
        {
            if (input[i] == ')' and stk.top() == '(') 
            {
                stk.pop();
            }
            else if (input[i] == '}' and stk.top() == '{') 
            {
                stk.pop();
            }
            else if (input[i] == ']' and stk.top() == '[') 
            {
                stk.pop();
            }
            else 
            {
                return 0;
            }
        }
    }

    return stk.empty();
}

int main() 
{
    setlocale(LC_ALL, "ru");
    string input;
    stack<char> stk;
    cout << "Проверка на правльное расставление скобок" << endl;
    getline(cin, input);
    if (check(stk, input)) 
    {
        cout << "Yes";
    }
    else 
    {
        cout << "No";
    }
}