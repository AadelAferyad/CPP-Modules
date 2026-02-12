#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "[Intern] Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)	other;
	std::cout << "[Intern] copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	std::cout << "[Intern] Copy assignment constructor called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called" << std::endl;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
}
