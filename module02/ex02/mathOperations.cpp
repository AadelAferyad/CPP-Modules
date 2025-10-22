#include "Fixed.hpp"


Fixed Fixed::operator+(const Fixed& fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}
Fixed Fixed::operator-(const Fixed& fixed)
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}
Fixed Fixed::operator*(const Fixed& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}
Fixed Fixed::operator/(const Fixed& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator++()
{
	Fixed temp = *this;

	this->setRawBits((this->getRawBits()) + 1);
	return (temp);
}

Fixed&	Fixed::operator++(int)
{
	this->setRawBits((this->getRawBits()) + 1);
	return (*this);
}
