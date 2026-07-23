#include "BitcoinExchange.hpp"


Btc::Btc() {}
Btc::Btc(const Btc &obj) : in(obj.in) {}
Btc &Btc::operator=(const Btc &obj)
{
	if (this != &obj)
		in = obj.in;
	return *this;
}
Btc::~Btc() {};

float	Btc::getCloseValue(const std::string &str) const
{
	std::map<std::string, float>::const_iterator it;

	it = in.lower_bound(str);
	if (it != in.end() && it->first == str)
		return (it->second);
	if (it == in.begin())
		throw std::runtime_error("No earlier date");
	--it;
	return (it->second);
}

void	Btc::loadDataBase()
{
	std::ifstream file("data.csv");
	std::string	line;
	std::string	value = "";
	std::string	date = "";

	if (!file.is_open())
		throw std::runtime_error("Error: Can't open data.csv");
	std::getline(file, line);
	while (std::getline(file, date, ',') && std::getline(file, value))
		in[date] = std::atof(value.c_str());
	file.close();
}

const std::map<std::string, float> &Btc::getMap() const {return (in);}

std::ostream	&operator<<(std::ostream &out, const Btc &obj)
{
	const std::map<std::string, float> m = obj.getMap();

	for (std::map<std::string, float>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << " : " << it->second << std::endl;
	}
	return (out);
}
bool	isValidLeapYear(int year, int month, int day)
{
	bool	isLeap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	int	mDay = 0;
	
	if (month == 2)
	{
		if (isLeap)
			mDay = 29;
		else
			mDay = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		mDay = 30;
	}
	else
		mDay = 31;
	if (day < 1 || day > mDay)
		return (false);
	return true;
}

bool 	checkIsDigit(std::string &str)
{
	size_t	i = 0;
	size_t	l = str.size();

	if (str.empty())
		return (false);
	for (; i < l; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	checkAsStr(std::string &date)
{
	std::string y;
	std::string m;
	std::string d;
	int	f = 0;

	for (size_t i = 0; i < date.size(); i++)
	{
		if (date[i] == '-')
		{
			f++;
			continue ;
		}
		if (f == 0)
			y += date[i];
		else if (f == 1)
			m += date[i];
		else if (f == 2)
			d += date[i];
	}
	if (!checkIsDigit(y) || !checkIsDigit(m) || !checkIsDigit(d))
		return (false);
	return true;
}

void	checkDate(std::string &date)
{
	int	year;
	int	month;
	int	day;
	char	sep;
	char	sep1;


	if (date.size() != 10 || !checkAsStr(date))
		throw std::runtime_error("Error: Bad inpute => " + date);
	std::stringstream stream(date);
	stream >> year >> sep >> month >> sep1>> day;
	if (sep != '-' || sep1 != '-' || !year || !month || !(1 <= month && month <= 12) || !day || day > 31 || !isValidLeapYear(year, month, day))
		throw std::runtime_error("Error: Bad inpute => " + date);
}

float	checkValue(std::string &value)
{
	int	f = 0;
	if (value.empty())
		throw std::runtime_error("Error: Empty value.");
	std::stringstream	ss(value);
	float	n;
	ss >> n;
	if (n < 0)	
		throw std::runtime_error("Error: not a positive number.");
	if (n > 1000)
		throw std::runtime_error("Error: too large number.");
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
			f++;
		if (f > 1 || (value[i] != '.' && !std::isdigit(value[i])) || (value[i] == '.' && !std::isdigit(value[i + 1])))
			throw std::runtime_error("Error: Value should be a digit between 0 and 1000.");
	}
	return (n);
}

void	checkLine(std::string &line, const Btc &obj)
{
	std::string	date;
	std::string	value;
	char	sep;
	float	v;

	if (line.empty() || line.size() < 14)
		throw std::runtime_error("Error: bad inpute");
	std::stringstream	stream(line);
	stream >> date >> sep >> value;

	if (sep != '|' || !(line[10] == ' ' && line[11] == '|' && line[12] == ' ' && line[13] != ' '))
		throw std::runtime_error("Error: bad inpute");
	checkDate(date);
	v = checkValue(value);
	float val = obj.getCloseValue(date);
	std::cout << date << " => " << val << " = " << val * v << std::endl;
}

void	Btc::loadInpute(char *filename)
{
	std::ifstream	file(filename);
	std::string	line;

	if (!file.is_open())
		throw std::runtime_error("Error: Couldn't open file");
	getline(file, line);	
	if (line != "date | value")
		throw std::runtime_error("Error: Bad file header");
	while (getline(file, line))
	{
		try
		{
			checkLine(line, *this);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}
