#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->hit = 10;
	this->energy = 10;
	this->AttackDamag = 0;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int ht, unsigned int eng, unsigned int attack)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
	this->name = name;
	this->hit = ht;
	this->energy = eng;
	this->AttackDamag = attack;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &clap)
	{
		this->name = clap.name;
		this->hit = clap.hit;
		this->energy = clap.energy;
		this->AttackDamag = clap.AttackDamag;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->name = clap.name;
	this->hit = clap.hit;
	this->energy = clap.energy;
	this->AttackDamag = clap.AttackDamag;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing " << this->AttackDamag << " points of damage!" << std::endl;
		this->energy--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy or hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->hit > 0)
	{
		std::cout << "ClapTrap "<< this->name << " Repaired, gains " << amount << " hit points!" << std::endl;
		this->hit += amount;
		this->energy--;

	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy or hit points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit = this->hit > amount ? this->hit - amount : 0;
	std::cout << "ClapTrap "<< this->name << " took " << amount << " of damage" << ". Has " << this->hit << " hit point left"<< std::endl;
}
