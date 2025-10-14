#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType() << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
