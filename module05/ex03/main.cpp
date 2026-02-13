#include "./Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void)
{
	std::srand(std::time(NULL));

	{
		Intern	r;
		AForm	*form;
		Bureaucrat	b1("boss", 1);
	
		try
		{
			form = r.makeForm("robotomy request", "billal");
			b1.signForm(*form);
			b1.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

