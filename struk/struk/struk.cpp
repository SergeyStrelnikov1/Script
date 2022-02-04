#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int num_of_args(vector<bool> f)
{
	return sqrt(f.size());
}
vector<bool> read_from_file()
{
	vector<bool> file_name;
	bool bool1;
	ifstream in;
	in.open("C:\\Users\\terme\\Desktop\\test.txt");
	while (in >> bool1)
	{
		file_name.push_back(bool1);
	}
	return file_name;
		
}

bool write_to_file()
{
	vector<bool> write_to_file = { 1, 1, 0, 1, 0, 0, 1 };
	vector<bool> read_from_file;
	bool bool1;
	ofstream out;
	out.open("C:\\Users\\terme\\Desktop\\test.txt");
	for (int i = 0; i < write_to_file.size(); i++)
	{
		out << write_to_file[i]<< " ";
	}
	out.close();
	ifstream check;
	check.open("C:\\Users\\terme\\Desktop\\test.txt");
	if (check.is_open())
	{
		while (check >> bool1)
		{
			read_from_file.push_back(bool1);
		}
		for (int i = 0; i < read_from_file.size(); i++)
		{
			cout << read_from_file[i] << endl;
		}
		if (read_from_file == write_to_file)
		{
			cout << "Буль записи : ";
			return true;
			check.close();
		}
	}
}

int Pascal(int n)
{
	for (int row = 1; row <= n; ++row)
	{
		int cnk = 1;
		for (int col = 1; col <= (n - row + 1); ++col)
		{
			cout << " ";
		}
		for (int k = 1; k <= row; ++k)
		{
			cout << cnk << " ";
			cnk = cnk * (row - k) / k;
		}
		cout << "\n";
	}
	cout << "Количество " << endl;
	return n;
}
bool XOR(bool x, bool y)
{
	return (x + y) % 2;
}
std::string func_Zhegalkin(vector<bool> f)
{
	string rtrn;
	string buf;

	for (int i = 0; i < f.size(); i++)
		buf.append(std::to_string(f[i]));

	int counter = f.size();

	for (int i = 0; i < f.size(); i++)
	{
		int counter = f.size() - i;

		for (int j = 0; j < f.size() - i; j++);
		{
			buf.append(std::to_string(XOR(buf.size() - counter, buf.size() - counter + 1)));
		}

	}
	return rtrn;
}


int main()
{
	setlocale(LC_ALL, "ru");

	vector<bool> f = { 1, 1, 1, 1, 0 };
	cout << "Количество аргументов n : " << num_of_args(f) << endl;
	cout << endl;

	cout << "Вектор : ";
	for (int i = 0; i < read_from_file().size(); i++)
	{
		read_from_file().at(i);
	}
	cout << endl;
	cout << write_to_file() << endl;

	vector<bool> fa;
	int size = 4;
	bool elem;
	for (int i = 0; i < size; i++)
	{
		cout << "Таблица истиности : ";
		cin >> elem;
		fa.push_back(elem);
	}
	bool x0 = fa.at(0), x1 = fa.at(1), x2 = fa.at(2), x3 = fa.at(3);
	unsigned int z = pow(2, size);

	cout << "  Х0 " << " Х1 " << " Х2 " << " Х3 " << "      ИЛИ ";
	cout << "   И " << "  НЕ И " << "  НЕ ИЛИ\n";
	while (z--) { //в данном цикле выводится строка, в которой записана таблица истинности той или иной булевой функции (если совсем кратко)
		cout << "| " << x0 << " | " << x1 << " | " << x2 << " | " << x3 << " | -> | " << (x0 || x1 || x2 || x3);
		cout << " | " << " | " << (x0 && x1 && x2 && x3) << " | ";
		cout << " | " << !(x0 && x1 && x2 && x3) << " | " << " | ";
		cout << !(x0 || x1 || x2 || x3) << " |\n";
		{
			if (z > 8) x0 = 0;
			else x0 = 1;
		}
		{
			if (z > 12 || (z < 9 && z > 4)) x1 = 0;
			else x1 = 1;
		}
		{
			if (z > 14 || (z < 13 && z > 10) || (z < 9 && z > 6) || (z < 5 && z > 2)) x2 = 0;
			else x2 = 1;
		}
		{
			if (z % 2 == 0) x3 = 0;
			else x3 = 1;
		}
	}
	cout << "Треугольник паскаля : ";
	int n;
	cin >> n;
	cout << Pascal(n) << endl;
		
	vector<bool> temp = { 0, 0, 0, 1, 0, 0, 0, 1 };
    cout << func_Zhegalkin(temp);
	return 0;
}

