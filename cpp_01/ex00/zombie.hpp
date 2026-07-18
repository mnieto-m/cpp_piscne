#ifndef ZOMBIE_H
#define ZOMNBIE_H

# include <sstream>
# include <iostream>
# include <iomanip>

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(void);
		~Zombie(void);
		void set_name(std::string name);
		std::string get_name(void);

		void announce(void);

};


Zombie* newZombie (std::string name);
void randomChump(std::string name);

#endif