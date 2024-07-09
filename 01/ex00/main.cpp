#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie stackZombie("stack zombie");
	Zombie *heapZombie = newZombie("heap zombie");

	stackZombie.announce();
	heapZombie->announce();
	delete heapZombie;
	randomChump("random chump");

	return 0;
}
