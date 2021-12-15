#include "Circle.h"

Circle::Circle() {
	this->radiusCircle = 1;
	this->perimeterCircle = 2 * this->PI * radiusCircle;
	this->areaCircle = this->PI * radiusCircle * radiusCircle;
}

Circle::Circle(const Circle& temp) {
	this->perimeterCircle = temp.getPerimeter();
	this->areaCircle = temp.getArea();
	this->radiusCircle = temp.getRadius();
}

Circle::Circle(double radius) {
	this->radiusCircle = radius;
	this->perimeterCircle = 2 * this->PI * radiusCircle;
	this->areaCircle = this->PI * radiusCircle * radiusCircle;
}

Circle::~Circle() {}

void Circle::inputRadius() {
	cout << "������� Radius: ";
	cin >> this->radiusCircle;

	this->perimeterCircle = 2 * this->PI * radiusCircle;
	this->areaCircle = this->PI * radiusCircle * radiusCircle;
}

void Circle::setRadius(int radius) {
	this->radiusCircle = radius;

	this->perimeterCircle = 2 * this->PI * radiusCircle;
	this->areaCircle = this->PI * radiusCircle * radiusCircle;
}

void Circle::inputData() {
	inputCoordinate();
	inputRadius();
}

int Circle::getRadius() const {
	return this->radiusCircle;
}

int Circle::getPerimeter() const {
	return this->perimeterCircle;
}

int Circle::getArea() const {
	return this->areaCircle;
}

void Circle::printData() const {
	cout << "Perimeter: " << this->perimeterCircle << endl;
	cout << "Area: " << this->areaCircle << endl;
	cout << "Radius: " << this->radiusCircle << endl;
}