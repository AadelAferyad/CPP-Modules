#pragma once
#include <iostream>
#include <string>

class Bureaucrat:
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
};
