#include <iostream>

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
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			PrintToUpper(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
