#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hit = 100;
	energy = 100;
	AttackDamag = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->name = name;
	hit = 100;
	energy = 100;
	AttackDamag = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (&other != this)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}


void FragTrap::attack(const std::string& target)
{
	if (this->hit > 0 && this->energy > 0)
	{
		this->energy--;
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "
			<< this->AttackDamag << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->name << " has no energy or hit points left" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " is Requesting high fives!\n";
}
