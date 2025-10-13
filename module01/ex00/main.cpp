#include "Zombie.hpp"

int	main(void)
{
	Zombie c("mm");
	Zombie *p;

	p = newZombie("FFF");
	randomChump("anotherone");
	c.announce();
	p->announce();
	delete p;
	return (0);
}
