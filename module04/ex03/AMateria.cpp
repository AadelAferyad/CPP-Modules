#include "AMateria.hpp"



AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) 
{
	(void) other;
	*this = other;
}
AMateria &AMateria::operator=(const AMateria& other)
{
	(void) other;
	return (*this);
}
AMateria::~AMateria() {}
