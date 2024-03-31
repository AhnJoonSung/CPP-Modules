#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat's constructor called." << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat's destructor called." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat's sound." << std::endl;
}

std::string Cat::getType(void) const
{
	return type;
}
