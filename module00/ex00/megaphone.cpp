#include <iostream>
#include <string>
#include <cctype>

void	PrintToUpper(char *str)
{
	char	c;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 32;
		else
			c = str[i];
		std::cout << c;
	}
}

int	main(int ac, char **av)
{
	std::string	str;
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			for (int j = 0; str[j]; j++)
				std::cout << (char) toupper(str[j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
