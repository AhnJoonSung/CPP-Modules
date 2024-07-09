#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int N = 5;
	Zombie *zomHorde = zombieHorde(N, "zombieHorde");

	for (int i = 0; i < N; i++)
		zomHorde[i].announce();

	delete[] (zomHorde);
	return 0;
}
