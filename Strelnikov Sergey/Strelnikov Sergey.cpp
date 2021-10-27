#include <iostream>
using namespace std;

int* bubblesorting(int bubblearr[1001], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (bubblearr[j] > bubblearr[j + 1])
			{
				swap(bubblearr[j + 1], bubblearr[j]);
			}
		}
	}
	return bubblearr;
}

void task1()
{
	int notsortingarr[1001];
	int* sorting;
	int size;

	cout << "Размер массива: " << endl;
	cin >> size;

	while (size < 0);

	for (int i = 0; i < size; i++)
	{
		cout << "Введите число: " << endl;
		cin >> notsortingarr[i];
	}
	cout << "Массив отсартированный пузырьком: " << endl;

	sorting = bubblesorting(notsortingarr, size);

	for (int i = 0; i < size; i++)
	{
		cout << sorting[i] << '\t';
	}
	cout << endl;
}
char* sortingcounting(char notsortarr[1001], int size)
{
	const int alf = 26;
	int counting[alf]{ 0 };
	int j;
	for (int i = 0; i < size; i++)
	{
		j = (int)(notsortarr[i] - 'a');
		counting[j]++;
	}
	j = 0;
	int i = 0;
	while (j <= alf)
	{
		if (counting[j] > 0)
		{
			notsortarr[i] = (char)((int)('a') + j);
			i++;
			counting[j]--;
		}
		else
		{
			j++;
		}
	}
	return notsortarr;
}
void task2()
{
	char notsortingarr[1001];
	char* counting;
	int size;

	cout << "Размер массива: " << endl;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Введите символ" << endl;
		cin >> notsortingarr[i];
	}
	cout << "Массив отсортированный подсчетом: " << endl;
	counting = sortingcounting(notsortingarr, size);
	for (int i = 0; i < size; i++)
	{
		cout << counting[i] << "\t";
	}
	cout << endl;

}
void Merge(int* sortingmerge, int left, int right)
{
	int middle;
	int beginofleft;
	int beginofright;
	int* arr = new int[1001];

	middle = (left + right) / 2;
	beginofleft = left;
	beginofright = middle + 1; 
	for (int i = left; i <= right; i++)
	{
		if ((beginofleft <= middle) && ((beginofright > right) || ((sortingmerge[beginofleft]) < (sortingmerge[beginofright]))))
		{
			arr[i] = sortingmerge[beginofleft];
			beginofleft++;
		}
		else
		{
			arr[i] = sortingmerge[beginofright];
			beginofright++;
		}
	}
	for (int i = left; i <= right; i++)
	{
		sortingmerge[i] = arr[i];
	}
}
void mergesort(int* sortingmerge, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergesort(sortingmerge, left, middle);
		mergesort(sortingmerge, middle + 1, right);
		Merge(sortingmerge, left, right);

	}
}
void task3()
{
	int* sortingmerge = new int[1001];
	int size;
	cout << "Введите размер: " << endl;
	cin >> size;
	while (size < 0);
	for (int i = 1; i <= size; i++)
	{
		cout << "Введите число: " << endl;
		cin >> sortingmerge[i];


	}
	cout << "Массив отсортированый слиянием: " << endl;
	Merge(sortingmerge, 1, size);
	for (int i = 1; i <= size; i++)
	{
		cout << sortingmerge[i] << "\t";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int choise = 0;
	while (true)
	{
		cout << "1. Сортировка массива пузырьком \n" << "2. Сортировка массива подсчетом \n" << "3. Сортировка массива слиянием \n" << "4. Выход \n" << endl;
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
			return 0;
			break;
		}
		default:
		{
			cout << "Некорректный ввод, такого значения нет" << endl;
		}

		}
	}
	return 0;
}