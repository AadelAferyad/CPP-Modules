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

void	AMateria::use(ICharacter &target)
{
    std::cout << "Defaul AMateria use on " << target.getName() << std::endl;
}
std::string const &AMateria::getType(void) const {
    return this->type;
}
