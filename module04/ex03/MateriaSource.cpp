#include "MateriaSource.hpp"


MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
	{
		this->materias[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->materias[i];
			if (other.materias[i])
				this->materias[i] = other.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
}
	
void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = materia;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return (NULL);
}

