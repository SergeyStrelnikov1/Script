#pragma once
#include <iostream>
class Matrix
{
public:
	int size_col, size_row;
	double* elem;
	int i1, j1;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(int size);
	~Matrix();

	void output();
	void make(int row, int col);
	void sum_matrix(const Matrix& temp);
	void mult_number(int number);
	void mult_matrix(const Matrix& temp);
	double get_elem(int i, int j) { return elem[i * size_col + j]; }
	int get_row() { return size_row; }
	int get_col() { return size_col; }
	double trase();
};

