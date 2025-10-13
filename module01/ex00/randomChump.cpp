#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie a = Zombie(name);
	a.announce();
}
