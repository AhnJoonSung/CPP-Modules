#include "ClapTrap.hpp"
#include <iostream>

bool cannottMove(unsigned int hp, unsigned int ep);
void printCannotMove(const std::string &name);

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {}

void ClapTrap::attack(const std::string &target)
{
	if (cannottMove(hitPoints, energyPoints))
	{
		printCannotMove(name);
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < 1)
	{
		std::cout << "ClapTrap " << name << " has already died." << std::endl;
		return;
	}
	if (hitPoints > amount)
		hitPoints -= amount;
	else
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " take " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (cannottMove(hitPoints, energyPoints))
	{
		printCannotMove(name);
		return;
	}
	energyPoints--;
	hitPoints++;
	std::cout << "ClapTrap " << name << " gets " << amount << " hit points!" << std::endl;
}

bool cannottMove(unsigned int hp, unsigned int ep)
{
	if (hp < 1 || ep < 1)
		return true;
	return false;
}

void printCannotMove(const std::string &name)
{
	std::cout << "ClapTrap " << name << " can't do anything." << std::endl;
}
