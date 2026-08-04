#ifndef FIXED_HPP
#	define FIXED_HPP
# include <string>
# include <iostream>
# include <iomanip>


class Fixed
{
	private:
		int				raw_bits;
		static const int	fract_bits = 8;

	public:
		Fixed(void);
		~Fixed(void);

		Fixed(Fixed &fixedp);
		Fixed& operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};




#endif