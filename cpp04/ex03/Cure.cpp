#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() { type = "cure"; }

Cure::Cure(const Cure &other)
{
	(void)other;
	type = "cure";
}

const Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
