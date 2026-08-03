#ifndef HUMANB_CPP
#define HUMANB_CPP

# include <string>
# include <iostream>
# include <iomanip>
#include "Weapon.hpp"


class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;

	public:
		HumanB(std::string name);
		~HumanB(void);

		Weapon *getWeapon(void);
		std::string getName(void);

		void setWeapon(Weapon &weapon);
		void setName(std::string name);
		
		void attack(void);
} ;

#endif