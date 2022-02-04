#include<iostream>
#include<fstream>
using namespace std;



int main()
{

	string path = "myFile.txt";

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open())
	{
		cout << " Ошибка открытия файла" << endl;
	}
	else
	{
		cout << " Открытия файла" << endl;
		cout<<
	}
	return 0;
}