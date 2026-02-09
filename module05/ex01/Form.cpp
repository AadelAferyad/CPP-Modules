#include "Form.hpp"

Form::Form(): name("Default-name"), signedGrade(150), executeGrade(150)
{
	this->isSigned = false;
	std::cout << "[FORM] Default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int sgrade, const int egrade): name(name), isSigned(false), signedGrade(sgrade), executeGrade(egrade)
{
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
	std::cout << "[FORM] Parameterized constructor called" << std::endl;
}


Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), executeGrade(other.executeGrade)
{
	std::cout << "[FORM] Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "[FORM] Copy assignment constructor called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "[FORM] Destructor called" << std::endl;
}


const std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSign() const
{
	return (this->isSigned);
}

int	Form::getSignGrade() const
{
	return (this->signedGrade);
}

int	Form::getExecGrade() const
{
	return (this->executeGrade);
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return ("{Form exception raised}: GradeTooHigh");
}

const char *	Form::GradeTooLowException::what() const throw()
{
	return ("{Form exception raised}: GradeTooLow");
}

void	Form::beSigned(const Bureaucrat &obj)
{
	if (this->getSignGrade() < obj.getGrade())
		throw GradeTooLowException();
	this->isSigned ? std::cout << "Form is signed already." << std::endl : this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form name: " << obj.getName() << (obj.getSign() ? " This form is signed" : " This form is not signed")
		<< " Sign grade: " << obj.getSignGrade() << " Execute grade: " << obj.getExecGrade();
	return (out);
}
