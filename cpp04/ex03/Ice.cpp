#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() { type = "ice"; }

Ice::Ice(const Ice &)
{
	type = "ice";
}

const Ice &Ice::operator=(const Ice &)
{
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
