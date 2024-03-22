#include "Harl.hpp"
#include <string>
#include <iostream>

enum Levels
{
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARNING,
	LEVEL_ERROR,
	LEVEL_INSIGNIFICANT
};

int getLevel(std::string level)
{
	if (level == "DEBUG")
		return (LEVEL_DEBUG);
	if (level == "INFO")
		return (LEVEL_INFO);
	if (level == "WARNING")
		return (LEVEL_WARNING);
	if (level == "ERROR")
		return (LEVEL_ERROR);
	return (LEVEL_INSIGNIFICANT);
}

int main(int ac, char **av)
{
	if (ac > 3)
		return 0;

	Harl harl;
	std::string filter;
	if (ac == 1)
		filter = "DEBUG";
	else
		filter = av[1];

	switch (getLevel(filter))
	{
	case LEVEL_DEBUG:
		harl.complain(filter);
	case LEVEL_INFO:
		harl.complain(filter);
	case LEVEL_WARNING:
		harl.complain(filter);
	case LEVEL_ERROR:
		harl.complain(filter);
		break;
	default:
		harl.complain("INSIGNIFICANT");
		break;
	}
	return 0;
}
