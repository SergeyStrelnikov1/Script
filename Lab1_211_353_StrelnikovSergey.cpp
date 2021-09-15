// Lab1_211_353_StrelnikovSergey.cpp : Определяет точку входа для приложения.
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello, world !" << std::endl;
    std::cout << "double\t" << sizeof(double) << std::endl;
    double temp_double;// объявление переменных (резервирование месата)
    temp_double = 0b0111111111111111111111111111111111111111111111111111111111111111111;
    std::cout << "Max double " << temp_double;
    temp_double = 0b0100000000000000000000000000000000000000000000000000000000000000000;
    std::cout << " Min double " << temp_double;
    int temp_int = 0b0111111111111111111111111111111;
    int m_temp_int = 0b0100000000000000000000000000000;



    return 0;
}
