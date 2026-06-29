#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::list <int> a;
	a.push_front(1);
	a.push_back(2);
	a.push_back(3);
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "---------------Testing for list" << std::endl;
	{
		try
		{
			std::cout << "expected to return 3 :  " << easyfind(a, 3) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "expected to throw error :  " << easyfind(a, 222) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "---------------Testing for vector" << std::endl;
	{
		try
		{
			std::cout << "expected to return 2 :  " << easyfind(v, 2) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "expected to throw error :  " << easyfind(v, 222) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
