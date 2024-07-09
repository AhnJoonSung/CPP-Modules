#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap jooahn("jooahn");

	jooahn.attack("seunan");
	jooahn.takeDamage(0);
	std::cout << std::endl;

	jooahn.attack("seonmiki");
	jooahn.takeDamage(9);
	std::cout << std::endl;

	for (int i = 0; i < 7; i++)
		jooahn.beRepaired(1);
	std::cout << std::endl;

	jooahn.attack("inlim");
	jooahn.takeDamage(10);
	std::cout << std::endl;

	jooahn.attack("seoji");
	jooahn.takeDamage(1);
	std::cout << std::endl;

	jooahn.attack("seongmik");
	jooahn.takeDamage(20);
	jooahn.beRepaired(10);
}
