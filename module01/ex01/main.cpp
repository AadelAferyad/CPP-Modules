#include "Zombie.hpp"

int	main(void)
{
	Zombie *ptr = NULL;

	ptr = ptr->zombieHorde(5, "charchar");
	for (int i = 0; i < 5; i++)
	{
		ptr[i].announce();
	}
	delete [] ptr;
	return (0);
}

