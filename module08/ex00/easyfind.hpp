#pragma once

#include <iostream>


class IntegerNotFound : public std::exception 
{
	const char	*what() const throw();
};

template <typename T>
int	easyfind(const T &container, int n);
