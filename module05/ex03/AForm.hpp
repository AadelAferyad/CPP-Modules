#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool	isSigned;
		const int	signedGrade;
		const int	executeGrade;
	public:
		AForm();
		AForm(const std::string &name, const int sgrade, const int egrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
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
		class FormIsNotSigned: public std::exception
		{
			public:
				const char *	what() const throw();
		};
		class FileError: public std::exception
		{
			public:
				const char *	what() const throw();
		};
		void	beSigned(const Bureaucrat &obj);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
