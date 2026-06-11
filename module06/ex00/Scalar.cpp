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
	if (msg == "impossible")
		std::cout << "float: " << msg << std::endl;
	else
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
	if (s.iFlag == "impossible")
		std::cout << "int: " << s.iFlag << std::endl;
	else
		std::cout << "int: " << s.n << std::endl;
	if (s.fFlag == "impossible")
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << s.f << "f" << std::endl;
	std::cout << "double: " << s.d << std::endl;
}

double	toDouble(const char *str)
{
	char	*end;
	return (std::strtod(str, &end));
}

int	isValid(const char *str)
{
	std::string a = "impossible";
	int d = 0;
	int f = 0;
	int p = 0;
	int i;
	for (i = 0; str[i]; i++)
	{
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

int	checker(std::string &str, Parse &s)
{
	double	dum;
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		s.convert(str[0]);
		return (0);
	}
	if (isValid(str.c_str()))
		return (1);
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
	if (isInt(str.c_str()) == true)
	{
		dum = toDouble(str.c_str());
		 s.convert(dum);
	}
	else if (str.find('.') != std::string::npos)
	{
		if (str.find('f') != std::string::npos)
		{
			s.convert(toDouble(str.c_str()));
		}
		else
			s.convert(toDouble(str.c_str()));
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

