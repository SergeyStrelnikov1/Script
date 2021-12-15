#include "CircleSquare.h"

CircleSquare::CircleSquare() {}

CircleSquare::CircleSquare(const CircleSquare& temp) : Position(temp), Square(temp), Circle(temp) {}

CircleSquare::CircleSquare(int x, int y, int radius) : Position(x, y), Square(radius * 2), Circle(radius) {}

CircleSquare::~CircleSquare() {}