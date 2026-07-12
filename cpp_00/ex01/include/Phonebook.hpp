#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

class PhoneBook {
	private:
		Contact _contacts[8];
		
	public:
		PhoneBook();
		~PhoneBook();
		void interface(void);
		void dictionary(std::string command);
		void add(void);
		void search(void);
		void exit(void);
};

#endif