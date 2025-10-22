#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(Point& p);
		Point& operator=(Point& p);
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
