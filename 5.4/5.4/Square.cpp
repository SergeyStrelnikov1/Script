#include "Square.h"

Square::Square() {
	this->sideSquare = 1;
	this->perimeterSquare = 4 * sideSquare;
	this->areaSquare = sideSquare * sideSquare;
}

Square::Square(const Square& temp) {
	this->sideSquare = temp.getSide();
	this->perimeterSquare = temp.getPerimeter();
	this->areaSquare = temp.getArea();
}

Square::Square(double side) {
	this->sideSquare = side;
	this->perimeterSquare = 4 * sideSquare;
	this->areaSquare = sideSquare * sideSquare;
}

Square::~Square() {}

void Square::inputSide() {
	cout << "������� Side: ";
	cin >> this->sideSquare;

	this->perimeterSquare = 4 * sideSquare;
	this->areaSquare = sideSquare * sideSquare;
}

void Square::setSide(int side) {
	this->sideSquare = side;
	this->perimeterSquare = 4 * sideSquare;
	this->areaSquare = sideSquare * sideSquare;
}

void Square::inputData() {
	inputCoordinate();
	inputSide();
}

int Square::getSide() const {
	return this->sideSquare;
}

int Square::getPerimeter() const {
	return this->perimeterSquare;
}

int Square::getArea() const {
	return this->areaSquare;
}

void Square::printData() const {
	cout << "Side: " << this->sideSquare << endl;
	cout << "Perimeter: " << this->perimeterSquare << endl;
	cout << "Area: " << this->areaSquare << endl;
}
