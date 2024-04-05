#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat's constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : brain(new Brain(*(other.brain)))
{
	this->type = other.type;
	std::cout << "Cat's copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "Cat's copy assignment called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat's destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat's sound." << std::endl;
}

std::string Cat::getType() const
{
	return type;
}
