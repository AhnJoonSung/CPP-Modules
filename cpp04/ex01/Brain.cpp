#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	for (int i = 0; i < SIZE; i++)
		ideas[i] = "";
	std::cout << "Brain's constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < SIZE; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain's destructor called." << std::endl;
}
