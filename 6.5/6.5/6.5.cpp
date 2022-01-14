#include <iostream>
#include <string>
#include <list>

using namespace std;
int main() 

{
    setlocale(LC_ALL, "ru");


    string surname;
    int group;
    list<string> listSurname;
    list<int> listGroup;
   
    while (true) 
    {
        cout << "Номер группы, фамилия : " << endl;
        cin >> group >> surname;
        if (group == 0 || surname == "0")
        {
            break;
        }

        listSurname.push_back(to_string(group) + " " + surname);
        listGroup.push_back(group);
    }
    cout << endl;
    listGroup.sort();
    listGroup.unique();
    for (auto group : listGroup) 
    {
        cout << group << ":" << endl;
        for (auto surname : listSurname)
        {
            if (surname.find(to_string(group)) != string::npos)
            {
                cout << surname << endl;
            }
        }
        cout << endl;
    }
}