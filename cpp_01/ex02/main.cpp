# include <sstream>
# include <iostream>
# include <iomanip>


int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;
	
	std::cout << "mem address of str:		" << &str << std::endl;
	std::cout << "mem address held by ptr:	" << ptr << std::endl;
	std::cout << "mem address held by ref:	" << &ref << std::endl;

	std::cout << "value of str:			" << str << std::endl;
	std::cout << "value pointed by ptr:		" << *ptr << std::endl;
	std::cout << "value referened by ref:		" << ref << std::endl;
	
	return (0);
}