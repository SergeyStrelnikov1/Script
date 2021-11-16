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

// int find_substring1 - функция возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in, поиск ведется с позиции start_position
// Вход: const char * str_for_search_in - Указатель на массив char, который является строкой ввода пользователем
// const char * substring - Ук азатель на массив char, который является подстрокой ввода пользователем
// int start_position - Позиция с которой начинается поиск подстроки в строке 
// Вывод: функция возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in, иначе -1 как результат отсутствия подстроки
// Входные данные, а точнее start_position изменяется в результате работы функции, оно может уменьшаться на 1
int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int i, j; // Счетчики для циклов
	int lenSubstring, lenStrForSearchIn; // Длины строк

	//Находим размеры строки исходника и искомого
	for (lenSubstring = 0; substring[lenSubstring]; lenSubstring++);
	for (lenStrForSearchIn = 0; str_for_search_in[lenStrForSearchIn]; lenStrForSearchIn++);

	for (i = 0; i <= lenStrForSearchIn - lenSubstring; i++) { // Пока есть возможность поиска
		for (j = 0; str_for_search_in[i + j] == substring[j]; j++); // Проверяем совпадение посимвольно
		// Если посимвольно совпадает по длине искомого
		// Вернем из функции номер ячейки, откуда начинается совпадение
		// Учитывать 0-терминатор  ( '\0' )
		if (j - lenSubstring == 1 && i == lenStrForSearchIn - lenSubstring && !(start_position - 1)) return i;
		if (j == lenSubstring)
			if (start_position - 1) start_position--;
			else return i;
	}
	// Иначе вернем -1 как результат отсутствия подстроки
	return -1;
}

int* find_substring2(const char* str_for_search_in, const char* substring) {
	int position = 0; // позиции, с которой начинается подстрока
	int counter = 0; // счетчик
	int* mas = new int[255]; // динамический массив
	for (int i = 1; position != -1; i++) {
		position = find_substring1(str_for_search_in, substring, i);

		if (position >= 0) {
			mas[counter] = position;
			counter++;
		}
	}
	return mas;
}
void task2()
{

}
void task3()
{
	char cstr3[256];
	cout << "\nВведите строку : ";
	cin.getline(cstr3, 256, '.');
	int len3;
	len3 = strlen(cstr3);
	for (int i = 0; i < len3; i++)
	{
		cstr3[i] = cstr3[i] + 3;
		cout << cstr3[i];
	}
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
		cout << "\n1. Проверка на палиндром\n" << "2. Поиск34t подстроки в строке\n" << "3. Шифрование сдвигами \n" << "4. Вывести все названия (то, что внутри кавычек) \n" << "5. Выход\n" << endl;
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
