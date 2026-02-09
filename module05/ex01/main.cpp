#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	b("Boss", 2);
			Form	f("Medc", 60, 13);
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			f.beSigned(b);
			std::cout << f << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	};
	std::cout << "--------------------------------------------" << std::endl;
	{
		try
		{
			Bureaucrat	b("Boss", 2);
			Form	f("Medc", 60, 13);
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	};
	std::cout << "\n--------------------------------------------" << std::endl;
	{
		try
		{
			Bureaucrat	b("Boss", 140);
			Form	f("Medc", 60, 13);
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			f.beSigned(b);
			std::cout << f << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
