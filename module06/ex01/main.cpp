#include "Serialization.hpp"

int	main(void)
{
	Data p;
	Data *d;
	uintptr_t	ptr;

	p.name = "tio";
	p.age = 20;

	std::cout << "---data---" << std::endl << "name: " << p.name << std::endl << "age: " << p.age << std::endl;
	
	ptr = Serializer::serialize(&p);
	std::cout << "printing ptr: " << ptr << std::endl; 
	d = Serializer::deserialize(ptr);
	std::cout << "---restoring data---" << std::endl << "name: " << d->name << std::endl << "age: " << d->age << std::endl;
	return (0);
}
