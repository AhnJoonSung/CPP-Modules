#pragma once

class ICharacter;

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	const Cure &operator=(const Cure &other);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};
