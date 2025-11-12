#ifndef CLAP_H
#define CLAP_H

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hit;
		unsigned int	energy;
		unsigned int	AttackDamag;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap& operator=(const ClapTrap &clap);
		~ClapTrap();
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
		

#endif
