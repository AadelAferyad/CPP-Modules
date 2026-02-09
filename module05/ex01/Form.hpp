#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool	isSigned;
		const int	signedGrade;
		const int	executeGrade;
	public:
		Form();
		Form(const std::string &name, const int sgrade, const int egrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string	getName() const;
		bool getSign() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		class GradeTooHighException: public std::exception
		{
			public:
				const char *	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *	what() const throw();
		};
		void	beSigned(const Bureaucrat &obj);


};

std::ostream &operator<<(std::ostream &out, const Form &obj);
