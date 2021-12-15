#pragma once
#include "Position.h"
class Circle : virtual public Position {
protected:
	const double PI = 3.14;
	double perimeterCircle;
	double areaCircle;
	double radiusCircle;
public:
	Circle(); 
	Circle(const Circle& temp); 
	Circle(double radius);

	~Circle(); 

	void inputRadius();
	void setRadius(int radius);

	void inputData();

	int getRadius() const;
	int getPerimeter() const;
	int getArea() const;
	void printData() const;
};