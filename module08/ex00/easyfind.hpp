#pragma once

#include <algorithm>
#include <iostream>


class IntegerNotFound : public std::exception 
{
	const char	*what() const throw()
	{
		return ("Didn't found any occurrence in this container");
	}
};

template <typename T>
int	easyfind(const T &container, int n)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw(IntegerNotFound());
	return (*it);
}
