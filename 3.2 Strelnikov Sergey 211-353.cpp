#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void task1(int * &mas, int * size) {
	do {
		cout << "Введите размер массива: ";
		cin >> *size;
		if (*size < 0) {
			cout << "размер должен быть положительным числом";
		}
	} while (*size < 0);
	
	mas = new int[*size];

	for (int i = 0; i < *size; i++) {
		cout << "Введите число: " << endl;
		cin >> mas[i];
	}
}

void task2(int * &mas, int * size) {
	if (*size != 0) {
		for (int i = 0; i < *size; i++) {
			cout << mas[i] << "\t";
		}
		cout << endl;
	}
	else {
		cout << "Массив не заполнен" << endl;
	}
}

int sumOfDigitInEvenPlaces(int num) {
	int sum = 0;

	while (num > 0) {
		sum += num % 100 / 10;
		num /= 100;
	}

	return sum;
}

void sortingForTask3(int * mas, int * size) {
	bool checkSort = true;

	while (checkSort) {
		checkSort = false;

		for (int i = 0; i < *size - 1; i++) {
			if (sumOfDigitInEvenPlaces(mas[i]) > sumOfDigitInEvenPlaces(mas[i + 1]) || ((sumOfDigitInEvenPlaces(mas[i]) == sumOfDigitInEvenPlaces(mas[i + 1])) && (mas[i] > mas[i + 1]))) {
				int temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;

				checkSort = true;
			}
		}
	}
}

void task3(int * &mas, int * size) {
	if (*size != 0) {
		sortingForTask3(mas, size);
		task2(mas, size); // Вывод массива в консоль
	} else {
		cout << "Массив не заполнен" << endl;
	}
}

void sortingForTask4(int * mas, int * size) {
	for (int i = 0; i < * size; i++) {
		for (int j = 0; j < * size - i - 1; j++) {
			if (((mas[j] % 10) > (mas[j + 1] % 10)) || (((mas[j] % 10) == (mas[j + 1] % 10)) && (mas[j] < mas[j + 1]))) {
				int t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
			}
		}
	}
}

void task4(int * &mas, int * size) {
	if (*size != 0) {
		sortingForTask4(mas, size);
		task2(mas, size); // Вывод массива в консоль
	}
	else {
		cout << "Массив не заполнен" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int *mas;
	int size = 0;
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) { // непрерывный цикл 
		cout << "Что Вы хотите выполнить? \n"
			<< "1. Ввод массива\n"
			<< "2. Вывод массива в консоль\n"
			<< "3. Сортировка по сумме цифр, стоящих на четных местах\n"
			<< "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию\n"
			<< "5. выход\n";
		cin >> choice;
		switch (choice) {
			case 1: {
				/*вызов функции для решения задания 1*/;
				task1(mas, &size);
				break; // если его не ставить, то после вызова task1(), начнет выполнятся task2() 
			}
			case 2: {
				/*вызов функции для решения задания 2*/;
				task2(mas, &size);
				break;
			}
			case 3: {
				/*вызов функции для решения задания 3*/;
				task3(mas, &size);
				break;
			}
			case 4: {
				/*вызов функции для решения задания 4*/;
				task4(mas, &size);
				break;
			}
			case 5: {
				/*вызов функции для решения задания 5*/;
				return 0;
				break;
			}
			default: {
				cout << "Некорректный ввод, такой функции нет!" << endl;
			}
		}
	}
}
