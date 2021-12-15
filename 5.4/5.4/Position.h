#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Position {
protected:
	int coordinateX;
	int coordinateY;
public:
	Position(); // ����������� �� ���������
	Position(const Position& temp); // ���������� �����������
	Position(int x, int y);

	~Position(); // ����������

	void inputCoordinate();
	void setCoordinate(int x, int y);

	int getX() const;
	int getY() const;
	void print() const;

	void changeCoordinate(int x, int y);
};