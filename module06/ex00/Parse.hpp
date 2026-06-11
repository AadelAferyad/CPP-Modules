#ifndef __PARSE__
#define __PARSE__

#include <iostream>
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <climits>
#include <iomanip>


class Parse
{
	public:
		std::string	iFlag;
		std::string	dFlag;
		std::string	fFlag;
		std::string	cFlag;
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
