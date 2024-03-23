#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap jooahn("jooahn");

	jooahn.attack("seunan");
	jooahn.takeDamage(90);
	for (int i = 0; i < 90; i++)
		jooahn.beRepaired(1);
	jooahn.highFivesGuys();
}
