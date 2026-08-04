#include "Fixed.hpp"

Fixed::Fixed(void):raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
};

Fixed::Fixed(Fixed &fixed)
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

Fixed::Fixed(const int int_nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = int_nbr * (1 << Fixed::fract_bits);
}

Fixed::Fixed(const float float_nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(float_nbr * (1 << Fixed::fract_bits));
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