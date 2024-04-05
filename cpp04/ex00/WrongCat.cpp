#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat's constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat's sound." << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}
