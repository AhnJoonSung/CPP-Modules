#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() { type = "cure"; }

Cure::Cure(const Cure &) { type = "cure"; }

const Cure &Cure::operator=(const Cure &) { return (*this); }

Cure::~Cure() {}

AMateria *Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
