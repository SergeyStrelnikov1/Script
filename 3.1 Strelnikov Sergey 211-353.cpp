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
		std::cout << arr[i] << std::endl;
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

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
void task2()

{

}
void task3()
{

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