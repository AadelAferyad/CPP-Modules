#include "Cure.hpp"


Cure::Cure(): AMateria("cure") {}


Cure::Cure(const Cure &other): AMateria(other)
{
	(void) other;
}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return new Cure();
}

Cure::~Cure() {};
