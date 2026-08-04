#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "../include/Claptrap.hpp"

class FragTrap: public ClapTrap{
    public:
        FragTrap ();
        FragTrap (std::string _name);
		FragTrap (const FragTrap& other);

        virtual ~FragTrap ();
		FragTrap& operator=(const FragTrap& rhs);

        void highFivesGuys();

    private:
		
};

#endif