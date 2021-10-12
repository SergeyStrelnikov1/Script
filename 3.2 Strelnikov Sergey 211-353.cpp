#include <iostream>
void task1(int*& mas, int* size)
{
    do
    {
        std::cout << "Введите размер массива: ";
        std::cin >> *size;
    } while (*size < 0);

    mas = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        std::cout << "Введите число: " << std::endl;
        std::cin >> mas[i];
    }
}
void task2(int*& mas, int* size)
{
    if (*size != 0) {
        for (int i = 0; i < *size; i++) {
            std::cout << mas[i] << "\t";
        }
        std::cout << std::endl;
    }
}

int sumOfPlaces(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 100 / 10;
        num /= 100;
    }

    return sum;
}
void sortingForTask3(int* mas, int* size)
{
    bool check = true;

    while (check)
    {
        check = false;

        for (int i = 0; i < *size - 1; i++)
        {
            if (sumOfPlaces(mas[i]) > sumOfPlaces(mas[i + 1]) || ((sumOfPlaces(mas[i]) == sumOfPlaces(mas[i + 1])) && (mas[i] > mas[i + 1])))
            {
                int temp = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = temp;

                check = true;
            }
        }
    }
}
void task3(int*& mas, int* size)
{
    if (*size != 0)
    {
        sortingForTask3(mas, size);
        task2(mas, size);
    }
}
void task4(int*& mas, int* size)
{

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int choise = 0;
    int* mas;
    int size = 0;
    while (true)
    {
        std::cout << "1. Ввод массива \n" << "2. Вывод массива в консоль\n" << "3. Сортировка по сумме цифр, стоящих на четных местах\n" << "4. Отсортировать массив вначале по возрастанию\n" << "5. Выход" << std::endl;
        std::cin >> choise;
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
        default:
        {
            return 0;
        }
        }

    }

}
