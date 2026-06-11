#include "Parse.hpp"

Parse::Parse() : iFlag("default"), dFlag("default"), fFlag("default"), cFlag("default"){}
Parse::Parse(const Parse &obj)
{
	(void) obj;
}

Parse &Parse::operator=(const Parse &obj)
{
	(void) obj;
	return (*this);
}

Parse::~Parse() {}

void	Parse::convert(int p)
{
	n = p;
	f = static_cast <float>(p);
	d = static_cast <double>(p);
	c = static_cast <char>(p);
}

void	Parse::convert(float p)
{
	f = p;
	n = static_cast <int>(p);
	d = static_cast <double>(p);
	c = static_cast <char>(p);
}

void	Parse::convert(double p)
{
	d = p;
	if (d > INT_MAX || d < INT_MIN) 
		iFlag = "impossible";
	else
		n = static_cast <int>(p);
	if (d > FLT_MAX || d < FLT_MIN)
		fFlag = "impossible";
	else 
		f = static_cast <float>(p);
	c = static_cast <char>(p);
}

void	Parse::convert(char p)
{
	c = p;
	f = static_cast <float>(p);
	n = static_cast <int>(p);
	d = static_cast <double>(p);
}
