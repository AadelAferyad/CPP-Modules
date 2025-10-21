#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	rawbit;
		static const int	fraction;
	public:
		Fixed();
		Fixed(int const rawbit);
		Fixed(float const rawbit);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);
#endif
