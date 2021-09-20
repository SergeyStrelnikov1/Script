#include <iostream>
#include <string>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russiаn");
    std::cout << "1." << std::endl;
    std::cout << "Strelnikov Sergey Andreevich, 211-353" << std::endl;
    std::cout << "2." << std::endl;

    double d1 = 0b01111111111111111111111111111111;
    std::cout << "Max double " << d1;
    d1 = 0b010000000000000000000000000000000;
    std::cout << " Min double " << d1;
    std::cout << "  double " << sizeof(double) << std::endl;
    std::cout << "\n3." << std::endl;
    int num = 0;
    std::cout << "\nВведите число: ";
    std::cin >> num;
    int n = num;
    unsigned long long int i = 1, bin = 0;
    while (n > 0) {
        bin += (n % 2) * i;
        n /= 2;
        i *= 10;
    }
    std::cout << "\nВ бинарном виде " << bin << std::endl;
    std::cout << "\nВ шестнадцатиричном виде " << std::hex << num << std::endl;
    std::cout << "\nbool " << bool(num) << std::endl;
    std::cout << "\ndouble " << double(num) << std::endl;
    std::cout << "\nchar " << char(num) << std::endl;
    std::cout << "\n4." << std::endl;
    std::cout << "Введите коэффициенты a * x = b:";
    int a, b;
    std::cin >> a >> b;
    std::cout << double(a) << " * x = " << double(b) << std::endl;
    std::cout << "x = " << double(b) << " / " << double(a) << std::endl;
    std::cout << "x = " << double(b) / double(a) << std::endl;
    std::cout << "Ответ : x = " << double(b) / double(a) << std::endl;
    std::cout << "5." << std::endl;
    std::cout << "Введите координаты отрезка на прямой: ";
    int c = 0;
    int d = 0;
    std::cin >> c >> d;
    std::cout << "Середина отрезка находится в точке с координатой " << (double(c) + double(d)) / 2 << std::endl;
    return 0;
}
