#include "Position.h"

Position::Position() {
	this->coordinateX = 0;
	this->coordinateY = 0;
}

Position::Position(const Position& temp) {
	this->coordinateX = temp.getX();
	this->coordinateY = temp.getY();
}

Position::Position(int x, int y) {
	this->coordinateX = x;
	this->coordinateY = y;
}

Position::~Position() {}

void Position::inputCoordinate() {
	cout << "������� X: ";
	cin >> this->coordinateX;
	cout << "������� Y: ";
	cin >> this->coordinateY;
}

void Position::setCoordinate(int x, int y) {
	this->coordinateX = x;
	this->coordinateY = y;
}

int Position::getX() const {
	return this->coordinateX;
}

int Position::getY() const {
	return this->coordinateY;
}

void Position::print() const {
	cout << "X: " << this->coordinateX << endl;
	cout << "Y: " << this->coordinateY << endl;
}

void Position::changeCoordinate(int x, int y) {
	this->coordinateX = x;
	this->coordinateY = y;
}
