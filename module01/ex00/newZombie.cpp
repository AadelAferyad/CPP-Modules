#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *a = new Zombie(name);
	return (a);
}
