#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &num) : name(name), grade(num)
{
	if (num < 1)
		throw GradeTooHighException();
	if (num > 150)
		throw GradeTooLowException();
	std::cout << "Parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->grade = other.grade;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	std::cout << "Copy assignment constructor called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("{Bureaucrat exception raised}: GradeTooHigh");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("{Bureaucrat exception raised}: GradeTooLow");
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increment(void)
{
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << this->name << " has increment it's grade" << std::endl;
}

void	Bureaucrat::decrement(void)
{
	this->grade++;
	if (this->grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << this->name << " has decrement it's grade" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out);
}
