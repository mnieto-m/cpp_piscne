#include "./include/PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook		book;
	std::string		command;
	(void)argc;
	(void)argv;

	while (1) {
		std::getline(std::cin, command);
		if (command == "add")
			book.add();
		else if (command == "search")
			book.search();
		else if (command == "exit") {
			book.exit();
			break ;			
		}
		command = "";
	}
	
	return (0);
}