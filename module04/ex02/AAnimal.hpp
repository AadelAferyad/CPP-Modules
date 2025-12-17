#pragma once

#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal();
		void	virtual makeSound() const = 0;
		std::string	getType() const;
};
