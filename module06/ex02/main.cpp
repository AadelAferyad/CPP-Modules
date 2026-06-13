#include "utilities.hpp"


int	main(void)
{
	Base *p;
	Base c;
	p = generate();
	identify(p);
	identify(*p);

	std::cout << "testing invalid object" << std::endl;
	identify(c);

	delete p;
	return (0);
}
