#include "Cat.hpp"
#include <iostream>

Cat::Cat()
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

Cat::~Cat()
{
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
