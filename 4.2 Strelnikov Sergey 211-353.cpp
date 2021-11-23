#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string file_format(const string file_path_full)
{
    string exp;
    exp = file_path_full;
    exp.erase(0, file_path_full.rfind(".") + 1);
    return exp;
}
string file_name(const string file_path_full)
{
    string name;
    name = file_path_full;
    name.erase(0, file_path_full.rfind("\\") + 1);
    name.erase(name.rfind("."));
    return name;
}
string file_path(const string file_path_name)
{
    string path;
    path = file_path_name;
    path.erase(file_path_name.rfind("\\") + 1);
    return path;
}
char file_disk(const string file_path_name)
{
    char diskname;
    diskname = file_path_name[0];
    return diskname;
}
bool file_rename(string& file_path_name)
{
    string format, name, path;
    format = file_format(file_path_name);
    cin >> name;
    path = file_path(file_path_name);
    cout << path << name << "." << format << endl;
    file_path_name = path + name + "." + format;
    return true;
}
bool file_copy(const string file_path_full)
{
    string name, path, format, new_path_full;
    bool isopen;
    name = file_name(file_path_full);
    name.append("_copy");
    path = file_path(file_path_full);
    format = file_format(file_path_full);
    new_path_full.append(path);
    new_path_full.append(name);
    new_path_full.append(".");
    new_path_full.append(format);
    ifstream infile(file_path_full, ios::binary);
    isopen = infile.is_open();

    if (isopen == 1)
    {
        cout << "file is open\n";

        infile.seekg(0, ios_base::end);
        cout << "file volyme: " << infile.tellg() << endl;
        long size = infile.tellg();
        infile.seekg(0);

        char* buffer = new char[size];

        infile.read(buffer, size);

        ofstream outfile(new_path_full, ios::binary);

        if (outfile.is_open())
        {
            outfile.write(buffer, size);

            delete[] buffer;
            infile.close();
            outfile.close();
            return true;
        }
        else
        {
            infile.close();
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}
int main()
{
    int choise = 0;
    string file_path_full;
    bool retult;
    cout << "Input path to file : ";

    cin >> file_path_full;

    while (true)
    {
        cout << "\n1.file format \n" << "2.file_name \n" << "3.file_path \n" << "4.file_disk \n" << "5.file_rename \n" << "6.file_copy5 \n" << "7. exit\n";
        cin >> choise;
        switch (choise)
        {
            case 1:
            {
                cout << "file format  ";
                cout << file_format(file_path_full) << endl;
                break;
            }
            case 2:
            {
                cout << "file_name  ";
                cout << file_name(file_path_full) << endl;
                break;
            }
            case 3:
            {
                 cout << "file_path  ";
                 cout << file_path(file_path_full);
                 break;
            }
            case 4:
           {
                cout << "file_disk ";
                cout << file_disk(file_path_full);
                break;
           }
           case 5:
           {
                cout << "file_rename  ";
                cout << file_rename(file_path_full);
                break;
            }
            case 6:
            {
                cout << "file_copy  ";
                cout << file_copy(file_path_full);
                break;
            }
            case 7:
            {
                return 0;
                break;
            }


        }
    }

}
