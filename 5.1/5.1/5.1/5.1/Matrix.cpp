#include "Matrix.h"
#include <iostream>
Matrix::Matrix()
{
}

Matrix::Matrix(int row, int col)
{
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(int size)
{
	size_col = size;
	size_row = size;
	elem = new double[size * size];
	for (int i = 0; i < size * size; i++)
	{
		elem[i] = 0;
	}
}


Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

void Matrix::output()
{
	int counter = 0;
	for (int i = 0; i < size_col * size_row; i++)
	{
		if (counter == size_col) {
			std::cout << '\n';
			counter = 0;
		}
		std::cout << elem[i] << ' ';
		counter++;
	}
	std::cout << '\n';
}

void Matrix::make(int row, int col)
{
	i1 = 0;
	j1 = 0;
	if (elem != nullptr)
		delete[]elem;
	size_col = col;
	size_row = row;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++)
	{
		std::cin >> elem[i];
	}


	//return Matrix();
}


void Matrix::sum_matrix(const Matrix& temp)
{
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = this->elem[i] + temp.elem[i];
	}
	//return Matrix();
}

void Matrix::mult_number(int number)
{
	for (int i = 0; i < size_col * size_row; i++)
	{
		this->elem[i] = this->elem[i] * number;
	}
	//return Matrix();
}

void Matrix::mult_matrix(const Matrix& temp)
{
	double** c = new double* [size_row];
	double** a = new double* [size_row];
	double** b = new double* [size_row];
	for (int i = 0; i < this->size_row; i++)
	{
		for (int k = 0; k < this->size_col; k++) {
			a[i][k] = this->elem[i * this->size_col + k];
		}
	}
	for (int i = 0; i < temp.size_row; i++)
	{
		for (int k = 0; k < temp.size_col; k++) {
			b[i][k] = temp.elem[i * temp.size_col + k];
		}
	}
	for (int i = 0; i < this->size_row; i++)
	{
		c[i] = new double[temp.size_col];
		for (int j = 0; j < temp.size_col; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < this->size_col; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	int counter = 0;
	for (int i = 0; i < this->size_row; i++) {
		for (int j = 0; j < temp.size_col; j++) {
			if (counter == size_col) {
				std::cout << '\n';
				counter = 0;
			}
			std::cout << c[i][j] << ' ';
		}
	}
	//return Matrix();
}

double Matrix::trase()
{
	double out = 0;
	for (int i = 0; i < this->size_col; i++) {
		out += this->get_elem(i, i);
	}
	return out;
}

