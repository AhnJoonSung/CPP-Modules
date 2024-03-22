#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int value) : value(value * (1 << fractionalBits))
{
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const { return (this->value > other.getRawBits()); }
bool Fixed::operator<(const Fixed &other) const { return (this->value < other.getRawBits()); }
bool Fixed::operator>=(const Fixed &other) const { return (this->value >= other.getRawBits()); }
bool Fixed::operator<=(const Fixed &other) const { return (this->value <= other.getRawBits()); }
bool Fixed::operator==(const Fixed &other) const { return (this->value == other.getRawBits()); }
bool Fixed::operator!=(const Fixed &other) const { return (this->value != other.getRawBits()); }

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed((value + other.getRawBits()) / (1 << fractionalBits)));
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed((value - other.getRawBits()) / (1 << fractionalBits)));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	int64_t temp = static_cast<int64_t>(value) * other.getRawBits();
	double d = static_cast<double>(temp) / (1LL << fractionalBits * 2);
	return (Fixed(static_cast<float>(d)));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(static_cast<float>(value) / other.getRawBits()));
}

Fixed Fixed::operator++(void)
{
	this->value++;
	return (*this);
}
Fixed Fixed::operator++(int dummy)
{
	(void)dummy;
	Fixed temp = *this;
	this->value++;
	return (temp);
}
Fixed Fixed::operator--(void)
{
	this->value--;
	return (*this);
}
Fixed Fixed::operator--(int dummy)
{
	(void)dummy;
	Fixed temp = *this;
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) { return (lhs < rhs ? lhs : rhs); }
const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) { return (lhs < rhs ? lhs : rhs); }
Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) { return (lhs > rhs ? lhs : rhs); }
const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) { return (lhs > rhs ? lhs : rhs); }

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	float f = static_cast<float>(value) / (1 << fractionalBits);
	return (f);
}

int Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}
