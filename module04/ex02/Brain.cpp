#include "Brain.hpp"

Brain::Brain(const std::string &idea)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Thinking about " + idea;
	}
	std::cout << "Brain default constructor callded" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor callded" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment constructor callded" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
		std::cout << "Brain destructor callded" << std::endl;
}
