#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal's constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal's copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal's copy assignment called." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setType(std::string type)
{
	this->type = type;
}
