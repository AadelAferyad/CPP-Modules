#include "ICharacter.hpp"



ICharacter::~ICharacter() {}
ICharacter::ICharacter() {}
ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
}
ICharacter& ICharacter::operator=(const ICharacter &other)
{
	(void) other;
	return (*this);
}

