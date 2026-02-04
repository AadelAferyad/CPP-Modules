#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
	this->name = "default";
	this->grade = 0;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
{
	this->name = other.name;
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

~Bureaucrat();
