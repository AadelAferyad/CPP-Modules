#include "Character.hpp"


Character::Character() : name("defualt name")
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string const &name) : name(name)
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
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->inventory[idx])
		this->inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return name;
}
