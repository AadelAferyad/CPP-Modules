#include "PmergeMe.hpp"
#include <iostream>

static int	checkArg(char *str)
{
	char *end;
	long n = std::strtol(str, &end, 10);
	if (*end != '\0')
		throw std::runtime_error("Invalid argument");
	if (n < 0 || n > INT_MAX)
		throw std::runtime_error("Invalid digit");
	return (static_cast<int>(n));
}

int	main(int ac, char **av)
{
	std::vector<node>	vect;
	std::deque<node>	deq;
	PmergeMe sort;
	if (ac < 2)
	{
		std::cerr << "Error: need arguments" << std::endl; 
		return (1);
	}
	try
	{
		int	n = 0;
		for (int i = 1; i < ac; i++)
		{
			n = checkArg(av[i]);
			vect.push_back(node(n));
			deq.push_back(node(n));
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	sort.sortVecotrContainer(vect);
	sort.sortDequeContainer(deq);
	return (0);
}
