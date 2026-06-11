#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>


bool	isInt(const char *str)
{
	char *end;
	std::strtol(str, &end, 10);
	return (*end == '\0');
}

int main(int ac, char **av)
{
	std::string a = av[1];
	if (isInt(a.c_str()) == true)
		std::cout << "true this is a digit" << std::endl;
	else
		std::cout << "False" << std::endl;

	return (0);
}
