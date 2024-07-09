#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog's constructor called." << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog's sound." << std::endl;
}

std::string Dog::getType() const
{
	return type;
}
