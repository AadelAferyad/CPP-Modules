#pragma once
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class	RPN
{
	private:
		std::stack <int> container;
		char	op;
	public:
		RPN();
		RPN(const std::string &str);
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		~RPN();
		int	eval();
		int	getStack () const;
};

std::ostream &operator<<(std::ostream &out, const RPN &obj);
