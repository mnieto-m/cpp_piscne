#ifndef FIXED_HPP
#	define FIXED_HPP
# include <string>
# include <iostream>
# include <iomanip>
#include <cmath>

class Fixed
{
	private:
		int				raw_bits;
		static const int	fract_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);

		Fixed(const int int_nbr);
		Fixed(const float float_nbr);
		Fixed(const Fixed &fixedp);
		
		Fixed &operator=(const Fixed &fixed);
		friend std::ostream &operator<<(std::ostream& os, const Fixed &fixed);

		bool operator!=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator>=(const Fixed &Fixed);
		bool operator>(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator<(const Fixed &fixed);

		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);

		Fixed &operator++(); //pre increment
		Fixed &operator++(int); //post increment, dummy iny param
		Fixed &operator--();
		Fixed &operator --(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed &max(const Fixed &f1, const Fixed &f2);

};




#endif