#include "../include/Fixed.hpp"

Fixed::Fixed(void):raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
};

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};



Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Int constructor called" << std::endl;
	this->raw_bits = int_nbr * (1 << Fixed::fract_bits);
}

Fixed::Fixed(const float float_nbr)
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}