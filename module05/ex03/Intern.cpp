#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

const char *Intern::RaiseNoFormFound::what() const throw()
{
	return ("[Intern] form not found");
}

AForm	*genPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm	*genRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*genShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm *(*(forms) [3]) (const std::string &) = {&genPresidential, &genRobotomy, &genShrubbery};
	const std::string formsName[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (name == formsName[i])
			return (forms[i](target));
	}
	throw Intern::RaiseNoFormFound();
	return (NULL);
} 
