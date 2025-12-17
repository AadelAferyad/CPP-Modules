#include "AAnimal.hpp"

AAnimal::AAnimal() 
{
	this->type = "AAnimal";
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type): type(type)
{
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal making sound" << std::endl;
}
std::string	AAnimal::getType() const
{
	return (this->type);
}
