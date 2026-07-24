#include "RPN.hpp"
#include <iostream>
#include <exception>


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Usage ./RPN + \"args\" " << std::endl;
		return (1);
	}
	try
	{
		RPN a(av[1]);
		std::cout << a << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
