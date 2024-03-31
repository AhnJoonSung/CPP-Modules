#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal's constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal's destructor called." << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal's sound." << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}
