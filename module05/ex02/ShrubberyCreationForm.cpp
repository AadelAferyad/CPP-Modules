#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default shrubbery", 145, 137), target("Default")
{
	std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(target, 145, 137), target(target)
{
	std::cout << "[ShrubberyCreationForm] Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target)
{
	std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "[ShrubberyCreationForm] Copy assignment constructor called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw FormIsNotSigned();
	if (this->getExecGrade() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream out((this->target + "_shrubbery").c_str());
	if (!out.is_open())
		throw FileError();
	out << "       *\n";
	out << "      ***\n";
	out << "     *****\n";
	out << "    *******\n";
	out << "   *********\n";
	out << "      |||\n";
	out << "      |||\n";
	out << std::endl;
	out.close();
}
