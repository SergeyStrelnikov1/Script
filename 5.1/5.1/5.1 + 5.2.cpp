#include "Matrix.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    int a = 0;
    int k, i, j;
    Matrix matr1;
    Matrix matr2;
    while (a == 0) {
        std::cout << "Что вы хотите выполнить?" "\n" << "1. Ввод" "\n" << "2. Вывод" "\n" << "3. Сложение двух матриц" "\n" << "4. Умножение двух матриц" "\n" << "5. След матрицы" "\n" << "6. Умножение матрицы на число" "\n" << "7. Количество столбцов" "\n" << "8. Количество строк" "\n" << "9. Вернуть (i,j) элемент " "\n" << "10. Выход" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            //matr1(2);
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            cout << "Введите матрицу ";
            matr1.make(i, j);
            //matr1 = input();
            break;
        case 2:
            matr1.output();
            break;
        case 3:
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            cout << '\n' << "Введите матрицу ";
            matr2.make(i, j);
            matr1.sum_matrix(matr2);
            matr1.output();
            break;
        case 4:
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            cout << "Введите матрицу ";
            matr2.make(i, j);
            matr1.mult_matrix(matr2);
            matr1.output();
            break;
        case 5:
            matr1.trase();
            break;
        case 6:
            cout << "Введите множитель ";
            cin >> k;
            matr1.mult_number(k);
            break;
        case 7:
            cout << matr1.get_col() << '\n';
            break;
        case 8:
            cout << matr1.get_row() << '\n';
            break;
        case 9:
            cout << "Введите i и j ";
            cin >> i >> j;
            cout << matr1.get_elem(i, j) << '\n';
            break;
        case 10:
            cout << "Всего хорошего";
            a++;
        default:
            break;
        }
    }
}



    
