#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hit = 100;
	energy = 50;
	AttackDamag = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	this->name = name;
	hit = 100;
	energy = 50;
	AttackDamag = 20;
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (&other != this)
	{
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout <<  "ScavTrap " << this->name << " is now in Gate keeper mode";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit > 0 && this->energy > 0)
	{
		this->energy--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
			<< this->AttackDamag << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " has no energy or hit points left" << std::endl;
}
