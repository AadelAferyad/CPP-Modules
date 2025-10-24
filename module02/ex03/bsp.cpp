#include "Point.hpp"


float	cross(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed b((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX()));
	return (b.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float cross1 = cross(a, b, point);
	float cross2 = cross(b, c, point);
	float cross3 = cross(c, a, point);

	bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
	bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

	return !(has_neg && has_pos);
}
