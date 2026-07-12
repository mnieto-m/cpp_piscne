#include "Phonebook.hpp"

int	main(int argc, char **argv)
{
	if(argc != 1 || argv[1] != NULL)
	{
		std::cout << "Invalid argument" << std::endl;
		return(1);
	}

	PhoneBook		book;
	std::string		command;

	while (std::getline(std::cin, command))
	{
		if (command.empty())
			book.interface();
		else if(command == "ADD" || command == "SEARCH" || command == "EXIT")
			book.dictionary(command);
		else
		{
			std::cout << "> Wrong command, use another command" << std::endl;
			book.interface();
		}
	}
	return (0);
}