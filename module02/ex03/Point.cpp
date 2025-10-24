#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(Point& p): x(p.x), y(p.y) {}

Point& Point::operator=(Point& p)
{
	(void) p;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

