#include "Animal.hpp"

Animal::Animal() 
{
	this->type = "Animal";
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal making sound" << std::endl;
}
std::string	Animal::getType() const
{
	return (this->type);
}
