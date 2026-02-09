#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &num);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		const std::string &getName() const;
		int	getGrade() const;
		void	increment(void);
		void	decrement(void);
		void	signForm(Form &obj);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
