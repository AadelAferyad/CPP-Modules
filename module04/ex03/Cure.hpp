#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		AMateria* clone(void) const;
		void use(ICharacter& target);
		~Cure();
};
