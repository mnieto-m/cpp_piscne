#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../include/Claptrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap ();
        ScavTrap (std::string _name);
		ScavTrap (const ScavTrap& other);

        virtual ~ScavTrap ();
		ScavTrap& operator=(const ScavTrap& rhs);

        void guardGate();
        void attack(const std::string& target);

    private:
		
};

#endif