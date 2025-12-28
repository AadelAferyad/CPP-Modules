#include "Character.hpp"


Character::Character() : name("defualt name")
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string &name) : name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			this->inventory[i] = other.inventory[i]->clone();
		}
		else
			this->inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (&other != this)	
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			if (other.inventory[i])
			{
				this->inventory[i] = other.inventory[i]->clone();
			}
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
	}
};

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m->clone();
			break ;
		}
	}
}

void unequip(int idx);
void use(int idx, ICharacter& target) const;
std::string const & getName() const;













