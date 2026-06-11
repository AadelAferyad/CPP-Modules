#include <iostream>
#include "Scalar.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter one argument only" << std::endl;
		return (1);
	}
	std::string a = av[1];
	ScalarConverter::convert(a);
	return (0);
}
