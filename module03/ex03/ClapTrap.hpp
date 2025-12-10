#ifndef CLAP_H
#define CLAP_H

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string	name;
		unsigned int	hit;
		unsigned int	energy;
		unsigned int	AttackDamag;
	public:
		ClapTrap();
		ClapTrap(const std::string &name, unsigned int ht, unsigned int eng, unsigned int attack);
		ClapTrap(const ClapTrap &clap);
		ClapTrap& operator=(const ClapTrap &clap);
		~ClapTrap();
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
		

#endif
