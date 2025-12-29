#include "Ice.hpp"


Ice::Ice(): AMateria("ice") {}


Ice::Ice(const Ice &other): AMateria(other)
{
	(void) other;
}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* Ice: shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return new Ice();
}

Ice::~Ice() {};
