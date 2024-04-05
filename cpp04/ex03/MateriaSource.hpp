#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int SIZE = 4;
	AMateria *materias[SIZE];
	int idx;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	const MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};
