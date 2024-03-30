#include <iostream>

#include "Point.h"

std::ostream & operator << (std::ostream &out, const Point &p) {
  // TODO: implement this operator.
	return out << "(" << p.getX() << ", " << p.getY() << ")";
}

std::istream & operator >> (std::istream &in,  Point &p) {
  // TODO: implement this operator.
	return in >> p.x >> p.y;
}

Point Point::operator + (const Point &p) {
  // TODO: implement this operator.
	Point Pnew;
	Pnew.x = x + p.getX();
	Pnew.y = y + p.getY();
	return Pnew;
}

Point& Point::operator += (const Point &p) {
  // TODO: implement this operator.
	this->x = getX() + p.getX();
	this->y = getY() + p.getY();
	return *this;
}