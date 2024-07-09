#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
private:
	std::string name;
	static const int SIZE = 4;
	AMateria *slot[SIZE];

public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	const Character &operator=(const Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	bool outOfIdx(int idx) const;
};
