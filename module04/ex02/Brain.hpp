#pragma once

#include <iostream>


class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(const std::string &idea);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
};
