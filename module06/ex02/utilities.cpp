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
		s = 'A';
	else if (b != NULL)
		s = 'B';
	else if (c != NULL)
		s = 'C';
	else
		s = 'x';

	if (s == 'x')
		std::cout << "Object doesn't exist" << std::endl;	
	else
		std::cout << "p: " << s << std::endl;	
}

void identify(Base& p)
{
	char	s;

	s = 'x';
	try
	{
		A &a = dynamic_cast<A&>(p);
		s = 'A';
		(void) a;
	}
	catch (std::exception &e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		s = 'B';
		(void) b;
	}
	catch (std::exception &e)
	{}
	try
	{
		C &c = dynamic_cast<C&>(p);
		s = 'C';
		(void) c;
	}
	catch (std::exception &e)
	{}
	if (s == 'x')
		std::cout << "Object doesn't exist" << std::endl;	
	else
		std::cout << "p: " << s << std::endl;	
}
