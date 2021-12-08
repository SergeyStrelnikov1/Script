#include <iostream>
#pragma once
#ifndef Matrix_peremennaya
#define Matrix_peremennaya
class Matr3Diag {
private:
	short n;
	double* matrix;
public:
	Matr3Diag(); 
	Matr3Diag(const Matr3Diag& temp); 

	~Matr3Diag();

	double trace() const;
	double det() const;
	void input();
	void input(int size);
	void print() const;
	short get_columns() const;

	double get_elem(short i, short j) const;
	void set_elem(short i, short j, double num);

	friend std::istream& operator>>(std::istream& in, Matr3Diag& matr1);
	friend std::ostream& operator<<(std::ostream& out, const Matr3Diag& matr1);
	friend Matr3Diag operator+(const Matr3Diag& matr1, const Matr3Diag& matr2);
	friend Matr3Diag operator-(const Matr3Diag& matr1, const Matr3Diag& matr2);
	friend Matr3Diag operator-(const Matr3Diag& matr1);
	friend Matr3Diag operator*(const Matr3Diag& matr1, const Matr3Diag& matr2);
	friend Matr3Diag operator*(const Matr3Diag& matr1, const int num);
	void operator+=(const Matr3Diag& matr2);
	void operator-=(const Matr3Diag& matr2);
};

#endif