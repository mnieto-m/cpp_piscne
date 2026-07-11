#include "Phonebook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook		book;
	std::string		command;
	(void)argc;
	(void)argv;

	while (1) 
	{
		std::getline(std::cin, command);
// Me falta un fallo que tengo con la señal de control d
		if (command == "ADD")
			book.add();
		else if (command == "SEARCH")
			book.search();
		else if (command == "EXIT") {
			book.exit();
			break ;			
		}
		command = "";
	}
	
	return (0);
}