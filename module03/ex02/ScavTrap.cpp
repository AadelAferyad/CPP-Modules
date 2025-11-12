#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("defualt", 100, 50, 20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
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
    if (this->energy > 0 && this->hit > 0)
    {
        this->energy--;
	std::cout <<  "ScavTrap " << this->name << " is now in Gate keeper mode";
    }
    else
        std::cout << "ScavTrap " << this->name << " has no more Energy Points or Hit Points" << std::endl;
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
