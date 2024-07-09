#include "Harl.hpp"
#include <string>

int main()
{
	const int size = 5;
	std::string levels[size] = {"DEBUG", "INFO", "WARNING", "ERROR", "NONE"};

	Harl harl;
	for (int i = 0; i < size * 10; i++)
		harl.complain(levels[i % size]);
	return 0;
}
