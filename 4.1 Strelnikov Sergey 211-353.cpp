#include <iostream>
#include <cstring>
using namespace std;
void task1()
{
	cout << "Введите строку : " << endl;
	char сstr1[256];
	cin.ignore();
	cin.getline(сstr1, 256);
	for (int i = 0; i < strlen(сstr1); i++)
	{
		if (сstr1[i] == ' ')
		{
			for (int j = i; j < strlen(сstr1); j++)
			{
				сstr1[j] = сstr1[j + 1];
			}

		}
	}
	bool check = true;
	for (int i = 0; i < strlen(сstr1) / 2; i++)
	{
		if (сstr1[i] != сstr1[strlen(сstr1) - 1 - i])
		{
			check = false;
			break;
		}
	}
	if (check)
	{
		cout << "Является полиндромом \n";
	}
	else
	{
		cout << "Не является \n";
	}

}
void task2()
{

}
void task3()
{
	char cstr3[256];
	cout << "\nВход : \n";
	cin.ignore();
	cin.getline(cstr3, 256, '.');
	int len3;
	len3 = strlen(cstr3);
	cout << "Выход : " << endl;
	for (int i = 0; i < len3; i++)
	{
		cstr3[i] = cstr3[i] + 3;
		cout<< cstr3[i];
	}
	cout << endl;
}

void foo(const char* cstr4) 
{
	for (int i = 0; i < strlen(cstr4); i++) 
	{
		if (cstr4[i] == '"') {
			char* arr = new char[256]; 
			int position = i + 1; 
			int counter = 0; 
			while (cstr4[position] != '"' && position != strlen(cstr4))
			{
				arr[counter] = cstr4[position];
				counter++;
				position++;
			}
			if (position != strlen(cstr4))
			{
				arr[counter] = '\0';
				cout << arr << " ";
			}

			i = position + 1;
			delete [] arr;
		}
	}
}
void task4()
{
	char cstr4[256];
	cout << "Вход = " << endl;
	cin.ignore();
	cin.getline(cstr4, 256);
	foo(cstr4);
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int choise = 0;
	while (true)
	{
		cout << "\n1. Проверка на палиндром\n" << "2. Поиск подстроки в строке\n" << "3. Шифрование сдвигами \n" << "4. Вывести все названия (то, что внутри кавычек) \n" << "5. Выход\n" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{

			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		}

	}
}
