#include "Parse.hpp"

Parse::Parse() : flag("default"){}
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
	f = static_cast <float>(p);
	n = static_cast <int>(p);
	c = static_cast <char>(p);
}

void	Parse::convert(char p)
{
	c = p;
	f = static_cast <float>(p);
	n = static_cast <int>(p);
	d = static_cast <double>(p);
}
