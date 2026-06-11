#include "Scalar.hpp"
#include "Parse.hpp"

bool	isInt(const char *str)
{
	char *end;

	std::strtol(str, &end, 10);
	return (*end == '\0');
}

void printer_p(std::string &msg)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << msg << "f" << std::endl;
	std::cout << "double: " << msg << std::endl;
}

void printer(Parse &s)
{
	std::cout << std::fixed << std::setprecision(1);
	if (s.n > 0 && s.n > 32 && s.n <= 127)
		std::cout << "char: " << s.c << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (s.flag == "impossible")
		std::cout << "int: " << s.flag << std::endl;
	else
		std::cout << "int: " << s.n << std::endl;
	std::cout << "float: " << s.f << "f" << std::endl;
	std::cout << "double: " << s.d << std::endl;
}

double	toDouble(const char *str)
{
	char	*end;
	return (std::strtod(str, &end));
}

int	checker(std::string &str, Parse &s)
{
	double	dum;
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		printer_p(str.erase(str.size() - 1));
		return (1);
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		printer_p(str);
		return (1);
	}
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		s.convert(str[0]);
	}
	else if (isInt(str.c_str()) == true)
	{
		dum = toDouble(str.c_str());
		 if (dum > INT_MAX) 
			 s.flag = "impossible";
		 std::cout << "d " << dum << std::endl;
		 s.convert(dum);
	}
	return (0);
}

void	ScalarConverter::convert(std::string &str)
{
	Parse s;
	if (checker(str, s))
		return ;
	printer(s);
}

