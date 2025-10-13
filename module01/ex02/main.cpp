#include <iostream>
#include <string>

int	main(void)
{
	std::string	var = "HI THIS IS BRAIN";
	std::string	*stringPTR = &var;
	std::string	&stringPEF = var;

	std::cout << "The memory address of the string variable : " << &var << std::endl;
	std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : " << &stringPEF << std::endl;

	std::cout << "The value of the string variable          : " << var << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringPEF << std::endl;
	return (0);
}
