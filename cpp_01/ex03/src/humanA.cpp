#include "HumanA.hpp"

HumanA::~HumanA(void) {}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon),
												   _name(name) {}

Weapon &HumanA::getWeapon(void) { return this->_weapon; }

std::string HumanA::getName(void) { return this->_name; }

void HumanA::setWeapon(Weapon &weapon) const { this->_weapon = weapon; }

void HumanA::setName(std::string name) { this->_name = name; }

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}