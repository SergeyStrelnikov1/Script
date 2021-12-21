#include <iostream>
#include <cstring>
using namespace std;

void task1()
{

	char сstr[256];
	cout << "Введите строку : ";
	cin.ignore();
	cin.getline(сstr, 256);

	for (int i = 0; i < strlen(сstr); i++)
	{
		if (сstr[i] == ' ')
		{
			for (int j = i; j < strlen(сstr); j++)
			{
				сstr[j] = сstr[j + 1];
			}

		}
		if (((сstr[i] >= 'A') && (сstr[i] <= 'Z')))
		{
			сstr[i] = сstr[i] + ' ';
		}
	}
	bool check = true;
	for (int i = 0; i < strlen(сstr) / 2; i++)
	{
		if (сstr[i] != сstr[strlen(сstr) - 1 - i])
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
int* find(int arr[], char* str_search, char* sub_str, int start_point)
{
	int c = 1;
	for (int i = start_point; i < strlen(str_search); i++)
	{
		if (str_search[i] == sub_str[0])
		{
			int k;
			int j = 0;
			k = i;
			while ((j < strlen(sub_str)) && (k < strlen(str_search)) && (sub_str[j++] == str_search[k++]))
			{
				arr[c] = i;
				c++;
			}
		}
	}
	arr[0] = c;
	return arr;
}
void task2()
{
	cout << "Введите строку : " << endl;
	char str[256];
	cin.ignore();
	cin.getline(str, 256);

	cout << "Введите подстроку : " << endl;
	char understr[256];
	cin.getline(understr, 256);

	int position;
	cout << "Введите начальную позицию : " << endl;
	cin >> position;
	int arr[256];
	int* rez;
	rez = find(arr, str, understr, position);
	for (int i = 1; i < arr[0]; i++)
	{
		cout << arr[i] << "";
	}
	cout << "\n\n";
}
void task3()
{
	char cstr2[256];
	cout << "\nВведите строку с точкой в конце : ";
	cin.getline(cstr2, 256, '.');
	int len2;
	len2 = strlen(cstr2);
	for (int i = 0; i < len2; i++)
	{
		cstr2[i] = cstr2[i] + 3;
		cout << cstr2[i];
	}
}

void task4()
{
	cout << "Введите текст : ";
	char str[256];
	cin.ignore();
	cin.getline(str, 256);

	int check = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '"')
		{
			check *= -1;
			if (check < 0)
			{
				cout << "\n";
			}
			else
			{
				if (check > 0)
				{
					cout << str[i];
				}
			}
		}
	}
	cout << "\n";
}
int main()
{
	setlocale(LC_ALL, "ru");
	int choise = 0;
	cout << "1. Проверка на палиндром\n" << "2. Поиск подстроки в строке\n" << "3. Шифрование сдвигами \n" << "4. Вывести все названия (то, что внутри кавычек) \n" << "5. Выход\n" << endl;
	cin >> choise;
	while (true)
	{
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