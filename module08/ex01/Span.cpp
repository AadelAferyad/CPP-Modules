#include "Span.hpp"


Span::Span(): capacity(0) {};
Span::Span(unsigned int n) : capacity(n){};
Span::Span(const Span &obj): storage(obj.storage), capacity(obj.capacity) {};
Span& Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		capacity = obj.capacity;
		storage = obj.storage;
	}
	return (*this);
}
Span::~Span() {};
const char * Span::NoEnoughStorage::what() const throw()
{
	return ("No enough Space reached maximum capacity");
}

void	Span::addNumber(const int n)
{
	if (capacity > storage.size())	
		storage.push_back(n);
	else
		throw(NoEnoughStorage());
}

int	Span::shortestSpan(void)
{
	int r = INT_MAX;
	if (storage.size() < 2)
		throw(std::out_of_range("Small span can't perform this operation"));
	std::vector<int> dumy(storage);
	std::sort(dumy.begin(), dumy.end());
	for (unsigned int i = 0; i <= dumy.size() - 1; i++)
	{
		int	temp = dumy[i + 1] - dumy[i]; 
		if (temp > 0 && temp < r)
			r = temp;
	}
	return (r);
}

int	Span::longestSpan(void)
{
	if (storage.size() < 2)
		throw(std::out_of_range("Small span can't perform this operation"));
	std::vector <int> dumy(storage);
	std::sort(dumy.begin(), dumy.end());
	return (dumy[dumy.size() - 1] - dumy[0]);
}
