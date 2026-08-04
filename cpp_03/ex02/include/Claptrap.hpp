#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <climits>

class ClapTrap {
    public:
        ClapTrap ();
        ClapTrap (std::string _name);
		ClapTrap (const ClapTrap& other);

        virtual ~ClapTrap ();
		ClapTrap& operator=(const ClapTrap& rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
	    std::string name;	
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
};

#endif