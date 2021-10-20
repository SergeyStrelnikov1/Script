#include <iostream>
using namespace std;
int* bubbleSorting(int bubbleSortingArr[1001], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (bubbleSortingArr[j] > bubbleSortingArr[j + 1]) 
			{
				int t = bubbleSortingArr[j];
				bubbleSortingArr[j] = bubbleSortingArr[j + 1];
				bubbleSortingArr[j + 1] = t;
			}
		}
	}
	return bubbleSortingArr;
}
void task1() 
{
	int bubbleNotSortingArr[1001];
	int *sortingArrBubble;
	int size;
	
	cout << "Введите размер: " << endl;
	cin >> size;
	for (int i = 0; i < size; i++) 
	{
		cout << "Введите число: " << endl;
		cin >> bubbleNotSortingArr[i];
	}
	cout << "Массив отсартированный пузырьковой сортировкой: " << endl;
	sortingArrBubble = bubbleSorting(bubbleNotSortingArr, size);
	for (int i = 0; i < size; i++) 
	{
		cout << sortingArrBubble[i] << '\t';
	}
	cout << endl;
}
char* sortingByCounting(char byCountingNotSortingArr[1001], int size) 
{
	int numberOfDifferentElements = 26;
	int counting[numberOfDifferentElements] = { 0 };
	int j;
	for (int i = 0; i < size; i++) {
		j = (int)(byCountingNotSortingArr[i] - 'a');
		counting[j]++;
	}
	j = 0;
	int i = 0;
	while (j <= numberOfDifferentElements) 
	{
		if (counting[j] > 0) 
		{
			byCountingNotSortingArr[i] = (char)((int)('a') + j);
			i++;
			counting[j]--;
		}
		else 
		{
			j++;
		}
	}
	return byCountingNotSortingArr;
}

void task2() 
{
	char byCountingNotSortingArr[1001]; 
	char *sortingArrByCounting;

	int size;
	cout << "Введите размер: " << endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите символ: " << endl;
		cin >> byCountingNotSortingArr[i];
	}
	cout << "Массив отсартированный подсчетной сортировкой: " << endl;
	sortingArrByCounting = sortingByCounting(byCountingNotSortingArr, size);
	for (int i = 0; i < size; i++) 
	{
		cout << sortingArrByCounting[i] << '\t';
	}
	cout << endl;
}

void Merge(int *sortingArrMerge, int left, int right) 
{
	int middle, beginningOfLeftPart, beginningOfRightPart;
	int *mas = new int[1001];

	middle = (left + right) / 2;
	beginningOfLeftPart = left;
	beginningOfRightPart = middle + 1;

	for (int j = left; j <= right; j++) 
	{
		if ((beginningOfLeftPart <= middle) && ((beginningOfRightPart > right) || (sortingArrMerge[beginningOfLeftPart] < sortingArrMerge[beginningOfRightPart]))) 
		{
			mas[j] = sortingArrMerge[beginningOfLeftPart];
			beginningOfLeftPart++;
		}
		else 
		{
			mas[j] = sortingArrMerge[beginningOfRightPart];
			beginningOfRightPart++;
		}
	}

	for (int j = left; j <= right; j++) 
	{
		sortingArrMerge[j] = mas[j];
	}
}

void MergeSorting(int *sortingArrMerge, int left, int right) 
{
	if (left < right) 
	{
		int middle = (left + right) / 2;
		MergeSorting(sortingArrMerge, left, middle); 
		MergeSorting(sortingArrMerge, middle + 1, right); 
		Merge(sortingArrMerge, left, right);
	}
}

void task3() 
{
	int *sortingArrMerge = new int[1001]; 

	int size;
	cout << "Введите размер: " << endl;
	cin >> size;
	for (int i = 1; i <= size; i++) 
	{
		cout << "Введите число: " << endl;
		cin >> sortingArrMerge[i];
	}
	cout << "Массив отсартированный сортировкой слияния: " << endl;

	MergeSorting(sortingArrMerge, 1, size);

	for (int i = 1; i <= size; i++) 
	{
		cout << sortingArrMerge[i] << '\t';
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	while (true)
	{
		cout << "1. По возрастанию по алгоритму пузырьковой \n" << "2. По возрастанию по алгоритму сортировки подсчетом \n" << "3. По возрастанию по алгоритму сортировки слиянием \n" << "4. Выход \n" << endl;
		cin >> n;
		switch (n)
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
		default:
		{
			return 0;
		}
		}
	}
}
