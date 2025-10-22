#include "Fixed.hpp"


bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}
bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}
bool Fixed::operator>=(const Fixed& fixed)
{
	return (this->getRawBits() >= fixed.getRawBits());
}
bool Fixed::operator<=(const Fixed& fixed)
{
	return (this->getRawBits() <= fixed.getRawBits());
}
bool Fixed::operator==(const Fixed& fixed)
{
	return (this->getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed& fixed)
{
	return (this->getRawBits() != fixed.getRawBits());
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}
