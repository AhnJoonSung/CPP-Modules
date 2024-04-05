#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() { type = "ice"; }

Ice::Ice(const Ice &other)
{
	(void)other;
	type = "ice";
}

const Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
