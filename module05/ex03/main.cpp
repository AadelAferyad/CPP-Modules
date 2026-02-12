#include "./Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== Creating Bureaucrats =====" << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		Bureaucrat mid("Manager", 40);
		Bureaucrat low("Intern", 140);

		std::cout << "\n===== Creating Forms =====" << std::endl;

		PresidentialPardonForm pardon("Arthur Dent");
		RobotomyRequestForm robot("Marvin");
		ShrubberyCreationForm shrub("home");

		std::cout << "\n===== Testing Signing =====" << std::endl;

		low.signForm(pardon);      // should fail
		president.signForm(pardon);

		mid.signForm(robot);       // should succeed
		low.signForm(shrub);       // might fail depending on your grades
		mid.signForm(shrub);

		std::cout << "\n===== Testing Execution =====" << std::endl;

		low.executeForm(pardon);       // fail
		president.executeForm(pardon); // success

		mid.executeForm(robot);        // success (50% robotomy)
		mid.executeForm(robot);        // try twice to see randomness

		low.executeForm(shrub);        // fail
		mid.executeForm(shrub);        // success (creates file)

		std::cout << "\n===== Testing Execute Without Sign =====" << std::endl;

		RobotomyRequestForm unsignedRobot("Bender");
		president.executeForm(unsignedRobot); // should throw FormNotSigned

	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== End of Tests =====" << std::endl;
}

