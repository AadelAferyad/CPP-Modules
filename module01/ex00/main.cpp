#include "Zombie.hpp"

int	main(void)
{
	Zombie c("mm");
	Zombie *p;

	p = c.newZombie("FFF");
	c.randomChump("anotherone");
	p->announce();
	delete p;
	return (0);
}
