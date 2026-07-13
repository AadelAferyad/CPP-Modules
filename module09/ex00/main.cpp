#include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{
	Btc a;

	if (ac != 2)
	{
		std::cout << "Usage: need inpute file [./btc file]" << std::endl;
		return (1);
	}
	try
	{
		a.loadDataBase();
		a.loadInpute(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
