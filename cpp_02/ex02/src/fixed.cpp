#include "../include/Fixed.hpp"

Fixed::Fixed(void):raw_bits(0)
{
};

Fixed::~Fixed(void)
{
};

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
};


Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->raw_bits = fixed.getRawBits();		
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	int integer_part = fixed.getRawBits() >> Fixed::fract_bits;
	float fractional_part = fixed.getRawBits() & ((1 << Fixed::fract_bits) - 1);
	float floatFractional = fractional_part / (1 << Fixed::fract_bits);
	os << integer_part + floatFractional;
	return (os);
}

Fixed::Fixed(const int int_nbr)
{
	this->raw_bits = int_nbr * (1 << Fixed::fract_bits);
}

Fixed::Fixed(const float float_nbr)
{
	this->raw_bits = roundf(float_nbr * (1 << Fixed::fract_bits));
}
float Fixed::toFloat(void) const
{
	return ((this->raw_bits / (float)(1 << Fixed::fract_bits)));
}

int Fixed::toInt(void) const
{
	return ((int)(this->raw_bits >> Fixed::fract_bits));
}
int Fixed::getRawBits(void) const
{
	return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}
bool Fixed::operator!=(const Fixed &fixed)
{
	if (this->getRawBits() != fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &fixed)
{
	if (this->getRawBits() == fixed.getRawBits())
		return (0);
	return (1);
}

bool Fixed::operator>=(const Fixed &fixed)
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>(const Fixed &fixed)
{
	if (this->getRawBits() > fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &fixed)
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &fixed)
{
	if (this->getRawBits() < fixed.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	float added_float = this->toFloat() + fixed.toFloat();
	return (Fixed(added_float));
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	float substracted_float = this->toFloat() - fixed.toFloat();
	return (Fixed(substracted_float));
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	float mult_float = this->toFloat() * fixed.toFloat();
	return (Fixed(mult_float));
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	float div_float = this->toFloat() / fixed.toFloat();
	return (Fixed(div_float));
}

//Prefix
Fixed &Fixed::operator++()
{
	int val = this->getRawBits() + 1;
	this->setRawBits(val);
	return (*this);
}
Fixed &Fixed::operator++(int)
{
	Fixed *tmp = new Fixed(*this);  //created a copy, return this
	int val = this->getRawBits() + 1;
	this->setRawBits(val);
	return (*tmp);
}

//Prefix
Fixed &Fixed::operator--()
{
	int val = this->getRawBits() - 1;
	this->setRawBits(val);
	return (*this);
}

//Postfix
Fixed &Fixed::operator --(int)
{
	Fixed *tmp = new Fixed(*this); //created a copy, return this
	int val = this->getRawBits() - 1;
	this->setRawBits(val);
	return (*tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	Fixed *min = new Fixed();
	if (f1.getRawBits() <= f2.getRawBits())
	{
		*min = f1;
	} else {
		*min = f2;
	}
	return (*min);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	Fixed *max = new Fixed();
	if (f1.getRawBits() >= f2.getRawBits())
	{
		*max = f1;
	} else {
		*max = f2;
	}
	return (*max);
}
