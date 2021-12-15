#pragma once
#include "Position.h"
class Square : virtual public Position {
protected:
	double sideSquare;
	double perimeterSquare;
	double areaSquare;
public:
	Square(); 
	Square(const Square& temp);
	Square(double side);

	~Square();
	void inputSide();
	void setSide(int side);

	void inputData();

	int getSide() const;
	int getPerimeter() const;
	int getArea() const;
	void printData() const;
};