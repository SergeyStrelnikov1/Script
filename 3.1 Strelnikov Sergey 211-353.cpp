#include <iostream>
void task1()
{
	int size;
	int* arr;
	std::cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int k;
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
    std::cout << "Слотировка пузырьком : "<< std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
char* sortingByCounting(char byCountingNotSortingArr[1001], int size) {
	const int numberOfDifferentElements = 26;
	int counting[numberOfDifferentElements] = { 0 };
	int j;
	for (int i = 0; i < size; i++) {
		j = (int)(byCountingNotSortingArr[i] - 'a');
		counting[j]++;
	}
	j = 0;
	int i = 0;
	while (j <= numberOfDifferentElements) {
		if (counting[j] > 0) {
			byCountingNotSortingArr[i] = (char)((int)('a') + j);
			i++;
			counting[j]--;
		}
		else {
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
	do 
	{ 
		std::cin >> size;
	} 
	while (size < 0);
    for (int i = 0; i < size; i++) 
    {
		std::cin >> byCountingNotSortingArr[i];
	}
	std::cout << "Массив отсартированный подсчетной сортировкой: " << std::endl;
    sortingArrByCounting = sortingByCounting(byCountingNotSortingArr, size);
    for (int i = 0; i < size; i++)
    {
		std::cout << sortingArrByCounting[i] << '\t';
	}
	std::cout << std::endl;
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
		else {
			mas[j] = sortingArrMerge[beginningOfRightPart];
			beginningOfRightPart++;
		}
	}

	for (int j = left; j <= right; j++) {
		sortingArrMerge[j] = mas[j];
	}
}
void MergeSorting(int *sortingArrMerge, int left, int right) {
	if (left < right) {
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
	do 
	{
		std::cin >> size;
	}
	while (size < 0);
    for (int i = 1; i <= size; i++)
	{
		
		std::cin >> sortingArrMerge[i];
	}
	std::cout << "Массив отсартированный сортировкой слияния: " <<std::endl;

	MergeSorting(sortingArrMerge, 1, size);

	for (int i = 1; i <= size; i++)
	{
		std::cout << sortingArrMerge[i] << '\t';
	}
	std::cout << std::endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	while (true)
	{
		std::cout << "1. По возрастанию по алгоритму пузырьковой \n" << "2. По возрастанию по алгоритму сортировки подсчетом \n" << "3. По возрастанию по алгоритму сортировки слиянием \n" << "4. Выход \n" << std::endl;
		std::cin >> n;
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
