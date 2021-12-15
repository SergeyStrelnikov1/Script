#pragma once
#include "Circle.h"
#include "Square.h"
class CircleSquare : public Circle, public Square {
public:
	CircleSquare(); 
	CircleSquare(const CircleSquare& temp); 
	CircleSquare(int x, int y, int radius);

	~CircleSquare(); 
};