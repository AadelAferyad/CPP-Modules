#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point p1(2, 2);  // inside
	Point p2(6, 2);  // outside

	std::cout << bsp(a, b, c, p1) << std::endl; // true
	std::cout << bsp(a, b, c, p2) << std::endl;
	return 0;
}
