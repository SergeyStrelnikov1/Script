#include <iostream>
using namespace std;
void task1(int*& mas, int* size)
{
	cout << "Введите размер массива ";
	cin >> *size;
	mas = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		cout << "Ввод массива" << endl;
		cin >> mas[i];

	}
	
}
void task2(int*& mas, int* size)
{
	if (*size != 0)
	{
		for (int i = 0; i < *size; i++)
		{
			cout << mas[i] << "\t";
		}
		cout << endl;
	}
	else
	{
		cout << "Массив не заполнен" << endl;
	}
}


int sum(int num) {
	int sum = 0;

	while (num > 0) {
		sum += num % 100 / 10;
		num /= 100;
	}

	return sum;
}

void sort(int* mas, int* size) {
	bool checkSort = true;

	while (checkSort) {
		checkSort = false;

		for (int i = 0; i < *size - 1; i++) {
			if (sum(mas[i]) > sum(mas[i + 1]) || ((sum(mas[i]) == sum(mas[i + 1])) && (mas[i] > mas[i + 1]))) 
			{
				swap(mas[i], mas[i + 1]);
				checkSort = true;
			}
		}
	}
}

void task3(int*& mas, int* size) {
	if (*size != 0) {
		sort(mas, size);
		task2(mas, size); 
	}
	else {
		cout << "Массив не заполнен" << endl;
	}
}
void sort2(int *mas, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size - i - 1; j++)
		{
			if (((mas[j % 10] > mas[j + 1] % 10)) || ((mas[j % 10] == (mas[j + 1] % 10)) && (mas[j] < mas[j + 1])))
			{
				swap(mas[i], mas[i + 1]);
			}
		}
	}
	 
}
void task4(int*& mas, int* size)
{
	if (*size != 0)
	{
		sort2(mas, size);
		task2(mas, size);
	}
	else
	{
		cout << "Массив не заполнен" << endl;
	}
	
}
int main ()
{
	setlocale(LC_ALL, "ru");
	int* mas;
	int size = 0;
	int choise = 0;
	while (true)
	{
		cout << "1. Ввод массива \n" << "2. Вывод массива в консоль\n" << "3. Сортировка по сумме цифр, стоящих на четных местах\n" << "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последнихцифр - по убыванию.\n" << "5. выход \n" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			task1(mas, &size);
			break;
		}
		case 2:
		{
			task2(mas, &size);
			break;
		}
		case 3:
		{
			task3(mas, &size);
			break;
		}
		case 4:
		{
			task4(mas, &size);
			break;
		}
		case 5:
		{
		    	delete[] mas;
			return 0;
			break;
		}
		default:
		{
			cout << "Введен не корректный номер" << endl;
		}

		}



	}
}
