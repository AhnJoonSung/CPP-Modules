#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : idx(0)
{
	for (int i = 0; i < SIZE; i++)
		materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) : idx(0)
{
	for (int i = 0; i < SIZE; i++)
		materias[i] = other.materias[i]->clone();
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		idx = other.idx;
		for (int i = 0; i < SIZE; i++)
		{
			if (materias[i])
				delete materias[i];
			materias[i] = other.materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (materias[i] != 0)
			delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (idx == SIZE)
		return;
	materias[idx++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (materias[i]->getType() == type)
			return (materias[i]->clone());
	}
	std::cout << "Creating a Materia requires learning first." << std::endl;
	return 0;
}
