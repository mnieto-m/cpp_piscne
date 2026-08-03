#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc  != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "example of use: ./exec filename s1 s2" << std::endl;
		return(1);
	}
	Replacer str_replace(argv[1], argv[2], argv[3]);
	str_replace.replace_str();
	
	return (0);
}