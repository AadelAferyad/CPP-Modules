#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	b;
			Bureaucrat	b1("Boss", 2);
			std::cout << b << std::endl;
			std::cout << b1 << std::endl;
			b1.increment();
			std::cout << b1 << std::endl;
			b = b1;
			b.decrement();
			std::cout << b << std::endl;
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
			Bureaucrat	b("test", 150);
			std::cout << b << std::endl;
			b.decrement();
			std::cout << "This won't be printed" << std::endl;
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
			Bureaucrat	b("test", 1);
			std::cout << b << std::endl;
			b.increment();
			std::cout << "This won't be printed" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	}
	return (0);
}
