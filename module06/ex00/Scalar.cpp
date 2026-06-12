#include "Scalar.hpp"

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
	if (msg == "impossible")
		std::cout << "float: " << msg << std::endl;
	else
		std::cout << "float: " << msg << "f" << std::endl;
	std::cout << "double: " << msg << std::endl;
}

double	toDouble(const char *str)
{
	char	*end;
	double	d;

	d = std::strtod(str, &end);
	if (*end != '\0' && str[1] == '\0')
		d = *str;
	return (d);
}

int	isValid(const char *str)
{
	std::string a = "impossible";
	int d = 0;
	int f = 0;
	int p = 0;
	int i;
	if (str[1] == '\0')
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (f && str[i])
		{
			printer_p(a);
			return (1);
		}
		if (str[i] == '.' && !std::isdigit(str[i + 1]))
		{
			printer_p(a);
			return (1);
		}
		if (str[i] == '-' || str[i] == '+')
		{
			p++;
			continue;
		}
		if (str[i] == '.')
			d++;
		else if (str[i] == 'f')
			f++;
		if ((f > 1 || d > 1 || p > 1) || (str[i] != '.' && str[i] != 'f' && !(str[i] >= '0' && str[i] <= '9')))
		{
			printer_p(a);
			return (1);
		}
	}
	if ((f && !d) || str[i - 1] == '.')
	{
		printer_p(a);
		return (1);
	}
	return (0);
}

int	checker(std::string &str)
{
	double	dum;

	std::cout << std::fixed << std::setprecision(1);
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
	dum = toDouble(str.c_str());
	if (isValid(str.c_str()))
		return (1);
	if (dum > 127 || dum < -128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(dum)))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(dum) << std::endl;
	if (dum > INT_MAX || dum < INT_MIN)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(dum) << std::endl;
	if (dum > FLT_MAX || dum < -FLT_MAX)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(dum) << "f" << std::endl;

	std::cout << "double: " << dum << std::endl;
	return (0);
}

void	ScalarConverter::convert(std::string &str)
{
	checker(str);
}

