#include "../include/Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void)
{
	std::cout << "destructor:" << this->name << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}
std::string Zombie::get_name(void)
{
	return this->name;
}

void Zombie::announce(void)
{
	std::cout << Zombie::get_name() << ":BraiiiiiiinnnzzzZ..." << std::endl;
}