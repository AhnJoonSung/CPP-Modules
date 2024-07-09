#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap jooahn("jooahn");

	jooahn.attack("seunan");
	jooahn.takeDamage(90);
	for (int i = 0; i < 40; i++)
		jooahn.beRepaired(1);
	jooahn.guardGate();
}
