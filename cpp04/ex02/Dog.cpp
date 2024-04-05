#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog's constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : brain(new Brain(*(other.brain)))
{
	this->type = other.type;
	std::cout << "Dog's copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "Dog's copy assignment called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
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
