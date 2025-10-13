#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

void	Zombie::SetName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie* newZombie( std::string name )
{
	Zombie *p = new Zombie(name);
	return (p);
}

void randomChump( std::string name )
{
	Zombie c = Zombie(name);
	c.announce();
}

Zombie::~Zombie()
{
	std::cout << this->name << ": Deleted !\n";
}
