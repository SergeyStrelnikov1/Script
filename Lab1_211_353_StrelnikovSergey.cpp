    #include <iostream>
    #include <string>
    #include <locale.h>
    #include <float.h>
    #include <limits.h>
    int main()
    {
        setlocale(LC_ALL, "Russiаn");
        std::cout << "1." << std::endl;
        std::cout << "Strelnikov Sergey Andreevich, 211-353" << std::endl;
        std::cout << "2." << std::endl;

        int min_int = 0b1000000000000000000000000000000;
        int max_int = 0b0111111111111111111111111111111;
        unsigned int min_Unsigned_Int = 0b00000000000000000000000000000000;
        unsigned int max_Unsigned_Int = 0b11111111111111111111111111111111;
        short min_Short = 0b1000000000000000;
        short max_Short = 0b0111111111111111;
        unsigned short min_Unsigned_Short = 0b000000000000000;
        unsigned short max_Unsigned_Short = 0b1111111111111111;
        long long min_Long_Long = 0b1000000000000000000000000000000000000000000000000000000000000000;
        long long max_Long_Long = 0b0111111111111111111111111111111111111111111111111111111111111111;
        bool min_bool = 0b0000000;
        bool max_bool = 0b0111111;
        
      
        std::cout << "min int = " << min_int << ", max int = " << max_int << ", size of int = " <<sizeof(int) << std::endl;
        std::cout << "min unsigned int = " << min_Unsigned_Int << ", max unsigned int = " << max_Unsigned_Int << ", size of unsigned int = " <<  sizeof(unsigned int) <<std::endl;
        std::cout << "min short = " << min_Short << ", max short = " << max_Short << ", size of short = " << sizeof(short) << std::endl;
        std::cout << "min unsigned short = " << min_Unsigned_Short << ", max unsigned short = " << max_Unsigned_Short << ", size of unsigned short = " << sizeof(unsigned int)<< std::endl;
        std::cout << "min long = " << LONG_MIN << ", max long =" << LONG_MAX << ", size of long = " << sizeof(long) << std::endl;
        std::cout << "min long long = " << min_Long_Long << ", max long long = " << max_Long_Long << ", size of long long = " << sizeof(long long) << std::endl;
        std::cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ", size of double = " << sizeof(double) << std::endl;
        std::cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ", size of char = " << sizeof(char) << std::endl;
        std::cout << "min bool = " << min_bool << ", max char = " << max_bool << ", size of char = " << sizeof(bool) << std::endl;
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
