#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	rawbit;
		static const int	fraction;
	public:
		Fixed();
		Fixed(int rawbit);
		Fixed(float rawbit);
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif
