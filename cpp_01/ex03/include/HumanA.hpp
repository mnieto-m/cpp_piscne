#ifndef HUMANA_CPP
#define HUMANA_CPP

# include <string>
# include <iostream>
# include <iomanip>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &_weapon;
		std::string _name;

	public:
 		~HumanA(void);
		HumanA(std::string name, Weapon &weapon);

		Weapon &getWeapon(void);
		std::string getName(void);

		void setWeapon(Weapon &weapon) const;
		void setName(std::string name);

		void attack(void);
} ;

#endif