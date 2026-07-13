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

void	checkDate(std::string &date)
{
	int	year;
	int	month;
	int	day;
	char	sep;
	char	sep1;


	if (date.size() != 10)
		throw std::runtime_error("Error: Bad inpute => " + date);
	std::stringstream stream(date);
	stream >> year >> sep >> month >> sep1>> day;
	if (sep != '-' || sep1 != '-' || !year || !month || !(1 <= month && month <= 12) || !day || day > 31)
		throw std::runtime_error("Error: Bad inpute => " + date);
	// check leap year ...	
}

void	checkLine(std::map<std::string, float> &data, std::string &line)
{
	std::string	date;
	std::string	value;
	char	sep;

	if (line.empty())
		throw std::runtime_error("Error: bad inpute");
	std::stringstream	stream(line);
	stream >> date >> sep >> value;

	if (sep != '|')
		throw std::runtime_error("Error: bad inpute");
	checkDate(date);
	checkValue(value);
	(void)data;
	std::cout << date << sep << value << std::endl;
}

void	Btc::loadInpute(char *filename)
{
	std::ifstream	file(filename);
	std::string	line;
	std::map<std::string, float> data;

	if (!file.is_open())
		throw std::runtime_error("Error: Couldn't open file");
	getline(file, line);	
	if (line != "date | value")
		throw std::runtime_error("Error: Bad file header");
	while (getline(file, line))
	{
		try
		{
			checkLine(data, line);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}
