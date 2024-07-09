#include "Character.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < SIZE; i++)
		slot[i] = 0;
}

Character::Character(const std::string &name) : name(name)
{
	for (int i = 0; i < SIZE; i++)
		slot[i] = 0;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < SIZE; i++)
		slot[i] = other.slot[i]->clone();
}

const Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (slot[i])
				delete slot[i];
			slot[i] = other.slot[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (slot[i] != 0)
			delete slot[i];
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < SIZE; i++)
	{
		if (slot[i] == 0)
		{
			slot[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (outOfIdx(idx))
		return;
	slot[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (outOfIdx(idx))
		return;
	if (slot[idx] == 0)
		return;
	slot[idx]->use(target);
}

bool Character::outOfIdx(int idx) const
{
	if (idx < 0 || idx >= SIZE)
		return true;
	return false;
}
