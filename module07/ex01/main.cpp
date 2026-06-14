#include "iter.hpp"
#include <iostream>

void	add(int &x)
{
	x++;
}

void	print(std::string const &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	int	arr[] = {1, 2, 3, 5};
	std::string	str[] = {"do", "it", "again"};

	iter(arr, 4, add);
	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	iter(str, 3, print);
	return (0);
}
