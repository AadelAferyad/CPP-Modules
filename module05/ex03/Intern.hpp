#pragma once

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		class RaiseNoFormFound: public std::exception
		{
			public:
				const char *what() const throw();
		};
		AForm	*makeForm(const std::string &name, const std::string &target);
};
