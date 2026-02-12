#include "AForm.hpp"

AForm::AForm(): name("Default-name"), signedGrade(150), executeGrade(150)
{
	this->isSigned = false;
	std::cout << "[AFORM] Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int sgrade, const int egrade): name(name), isSigned(false), signedGrade(sgrade), executeGrade(egrade)
{
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
	std::cout << "[AFORM] Parameterized constructor called" << std::endl;
}


AForm::AForm(const AForm &other): name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), executeGrade(other.executeGrade)
{
	std::cout << "[AFORM] Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "[AFORM] Copy assignment constructor called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AFORM] Destructor called" << std::endl;
}


const std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSign() const
{
	return (this->isSigned);
}
int	AForm::getSignGrade() const
{
	return (this->signedGrade);
}

int	AForm::getExecGrade() const
{
	return (this->executeGrade);
}

const char *	AForm::GradeTooHighException::what() const throw()
{
	return ("{AForm exception raised}: GradeTooHigh\n");
}

const char *	AForm::GradeTooLowException::what() const throw()
{
	return ("{AForm exception raised}: GradeTooLow\n");
}

const char *	AForm::FormIsNotSigned::what() const throw()
{
	return ("{AFrom exception raised}: Form Is not signed\n");
}

const char *	AForm::FileError::what() const throw()
{
	return ("{FILE ERROR} encountered an error while opening the file\n");
}

void	AForm::beSigned(const Bureaucrat &obj)
{
	if (this->getSignGrade() < obj.getGrade())
		throw GradeTooLowException();
	this->isSigned ? std::cout << "AForm is signed already." << std::endl : this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "AForm name: " << obj.getName() << (obj.getSign() ? " This form is signed" : " This form is not signed")
		<< " Sign grade: " << obj.getSignGrade() << " Execute grade: " << obj.getExecGrade();
	return (out);
}
