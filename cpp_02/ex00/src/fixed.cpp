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

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}