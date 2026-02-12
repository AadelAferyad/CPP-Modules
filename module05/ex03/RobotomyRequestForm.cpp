#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm default", 72, 45), target("Default")
{
	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(target, 72, 45), target(target)
{
	std::cout << "[RobotomyRequestForm] Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target)
{
	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "[RobotomyRequestForm] Copy assignment constructor called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw FormIsNotSigned();
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "drrrrrrrrrrrrrrrrrrrrrrilling noisesssssssssss!" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully 50\% of the time." << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
