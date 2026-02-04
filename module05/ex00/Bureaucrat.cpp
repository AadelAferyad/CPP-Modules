#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default constructor callded" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &num) : name(name), grade(num)
{
	std::cout << "Parameterized constructor callded" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor callded" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	std::cout << "Copy assignment constructor callded" << std::endl;
	return (*this);
}

~Bureaucrat();
