#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook created: " << std::endl;
	std::cout << "	Available commands:" << std::endl;
	std::cout << "	> ADD: New contact" << std::endl;
	std::cout << "	> SEARCH: Display a specific contact" << std::endl;
	std::cout << "	> EXIT: Quit and delete contacts" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		this->_contacts[i].reset();
	}
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(void)
{
	int 				i = 0;
	std::stringstream	index;
	std::string			first_name;
	std::string			last_name;
	std::string			nickname;
	std::string			phone_number;
	std::string			darkest_secret;

	for (int j = 0; j < 8; j++)
	{
		if (this->_contacts[j].get_index() == "" || j == 7)
		{
			index << j;
			i = j;
			break;
		}
	}

	std::cout << "  Save a new contact:" << std::endl;
	std::cout << "> first_name:" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "> last_name:" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "> nickname:" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "> phone_number:" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "> darkest_secret:" << std::endl;
	std::getline(std::cin, darkest_secret);

	this->_contacts[i].set_index(index.str());
	this->_contacts[i].set_first_name(first_name);
	this->_contacts[i].set_last_name(last_name);
	this->_contacts[i].set_nickname(nickname);
	this->_contacts[i].set_phone_number(phone_number);
	this->_contacts[i].set_darkest_secret(darkest_secret);

	std::cout << "  Contact saved!" << std::endl;
	std::cout << "> Use another command" << std::endl;
}

static void truncate(const std::string &str, size_t max_len)
{
	if (str.length() > max_len)
		std::cout << str.substr(0, max_len - 1).append(".");
	else
		std::cout << str;
}

void PhoneBook::search(void)
{
	Contact 	contact;
	std::string index;
	int			i;

	std::cout << "  List of contacts:" << std::endl;
	for (int j = 0; j < 8; j++)
	{
		contact = this->_contacts[j];
		std::cout << std::setiosflags(std::ios::right);
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << contact.get_index();
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		truncate(contact.get_first_name(), 10);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		truncate(contact.get_last_name(), 10);
		std::cout << " | ";
		std::cout << std::setfill(' ') << std::setw(10);
		truncate(contact.get_nickname(), 10);
		std::cout << std::endl;
	}
	if (this->_contacts[0].get_index() == "")
	{
		std::cout << "  Empty list, returning" << std::endl;
		std::cout << "> Use another command" << std::endl;
		return ;
	}

	while (1)
	{
		std::cout << "> Type in the idx to show info" << std::endl;
		std::cin >> index;
		i = atoi(index.c_str());
		if (i >= 0 && i < 8)
		{
			if (this->_contacts[i].get_index() == "")
				std::cout << "  Contact empty, try again" << std::endl;
			else
				break ;
		}
		else
			std::cout << "  Index out of bounds, try again" << std::endl;
	}

	std::cout << "  Contact info:" << std::endl;
	std::cout << this->_contacts[i].get_first_name() << std::endl;
	std::cout << this->_contacts[i].get_last_name() << std::endl;
	std::cout << this->_contacts[i].get_nickname() << std::endl;
	std::cout << this->_contacts[i].get_phone_number() << std::endl;
	std::cout << this->_contacts[i].get_darkest_secret() << std::endl;
	std::cout << "  End of contact" << std::endl;
	std::cout << "> Use another command" << std::endl;
}

void PhoneBook::exit(void)
{
	std::cout << "	⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⢀⠖⠢⡀⠀⠀⠀\n⠀⠀⠀⠀⠰⠊⠁⠀⠀⠀⠀⠀⠀⠈⠑⠢⣀⠀⠀⠀⠀⡞⠀⠘⠀⡆⠀⢠⠁⡠⠒⠢\n⠀⠀⣠⠂⠀⣠⣴⣶⡀⠀⠀⠀⠀⢠⣦⣄⠀⠣⡀⠀⠀⢡⠀⠀⡀⠇⠀⠇⠰⠀⢠⠊\n⠀⡰⠃⠀⠀⢿⣿⠿⠁⠀⠀⠀⠀⠈⠻⢿⠗⠀⠱⡀⠀⠈⢆⠀⠀⠂⠀⠈⠁⠀⡆⠀\n⠰⠁⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⠀⠄⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀\n⢈⠀⢣⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡆⠘⢢⣀⡀⠀⣀⠀⠀⠀⠀⢠⠆⠀\n⢸⠀⠘⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠃⠸⠀⠀⠀⠀⠀⠐⠤⠤⠂⠁⠀⠀\n⠀⢧⡀⠙⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⢀⣼⡿⠃⢠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠈⢿⠀⠈⠻⣿⣷⣦⣄⣀⣀⣤⣾⡿⠋⠀⣠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠑⢄⠀⠀⠀⠉⠙⠉⠉⠉⠁⠀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠒⠚⠲⠶⠶⠶⠾⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
}

