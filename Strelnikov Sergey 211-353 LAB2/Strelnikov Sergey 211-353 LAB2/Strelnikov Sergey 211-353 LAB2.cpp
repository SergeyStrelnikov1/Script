#include <iostream>
void task1()
{
    std::cout << "Введите число" << std::endl;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << j << "";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
void task2()
{
    int n = 0;
    std::cout << "Нахождение биномиальных коэффициентов: ";
    std::cin >> n;
    int cnk = 1;
    for (int k = 1; k <= n; k++)
    {
        std::cout << cnk << std::endl;
        cnk = cnk * (n - (k - 1)) / (k);
    }
}
void task3()
{
    int k, s = 0, q = 0;
    std::cout << "Введите набор чисел" << std::endl;
    do {
        std::cin >> k;
        s = s + k;
        if (k != 0)
            q++;
    } while (k != 0);
    std::cout << "Среднее значение : " << s / q << std::endl;

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    while (true)
    {
        std::cout << "Что вы хотите выполнить ? \n" << "1. Числовой треугольник 1\n" << "2. Нахождение биномиальных коэффициентов 2\n" << "3. Вычисление среднего арифметического введенных точек на прямой 3\n" << "4. выход\n" << std::endl;
        std::cin >> choice;
        switch (choice)
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
            task3();
            break;
        default:
        {
            return 0;
        }
        }
    }


}