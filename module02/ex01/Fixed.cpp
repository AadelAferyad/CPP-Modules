#include "Fixed.hpp"


const int Fixed::fraction = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->rawbit = 0;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		rawbit = other.rawbit;
	}
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawbit = other.rawbit;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawbit;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawbit= raw;
}

Fixed::Fixed(int rawbit)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawbit = rawbit << Fixed::fraction;
}

Fixed::Fixed(float rawbit)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawbit = roundf(rawbit * (1 << Fixed::fraction));
}

float Fixed::toFloat( void ) const
{
	return ((float) this->rawbit / (1 << Fixed::fraction));
}

int Fixed::toInt( void ) const
{
	return ((int) this->rawbit / (1 << Fixed::fraction));
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}
