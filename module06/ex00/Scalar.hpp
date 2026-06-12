#pragma once

#include <iostream>
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <climits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();
	public:
		static void	convert(std::string &str);
};
