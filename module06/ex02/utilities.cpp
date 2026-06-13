#include "utilities.hpp"


Base * generate(void)
{
	srand(time(NULL));
	int	r = rand() % 3;
	if (r == 1)
		return (new A());
	else if (r == 2)
		return (new B());
	return (new C());
}


void identify(Base* p)
{
	char	s;

	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	
	if (a != NULL)
		s = 'a';
	else if (b != NULL)
		s = 'b';
	else if (c != NULL)
		s = 'c';
	std::cout << "p: " << s << std::endl;	
}


