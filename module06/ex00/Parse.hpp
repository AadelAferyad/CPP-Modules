#ifndef __PARSE__
#define __PARSE__

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>


class Parse
{
	public:
		std::string	flag;
		char	c;
		int	n;
		float	f;
		double	d;
		Parse();
		Parse(const Parse& obj);
		Parse &operator=(const Parse& obj);
		~Parse();
		void	convert(int c);
		void	convert(float c);
		void	convert(double c);
		void	convert(char c);
};

#endif
