#include "Zombie.hpp"

int	main(void)
{
	Zombie *ptr = NULL;

	ptr = zombieHorde(5, "charchar");
	if (!ptr)
		return (0);
	for (int i = 0; i < 5; i++)
	{
		ptr[i].announce();
	}
	delete [] ptr;
	return (0);
}

