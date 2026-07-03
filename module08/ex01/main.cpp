#include "Span.hpp"
#include <iostream>
#include <list>

int main()
{
	Span sp = Span(5);
	std::list<int>  l;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{	
		Span bag(15000);
		for (int i = 0; i < 15000; i++)
			l.push_back(i * 2);
		bag.insertAll(l.begin(), l.end());
		std::cout << bag.shortestSpan() << std::endl;
		std::cout << bag.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
