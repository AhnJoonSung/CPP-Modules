#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) { std::cout << "debug comment" << std::endl; }
void Harl::info(void) { std::cout << "info comment" << std::endl; }
void Harl::warning(void) { std::cout << "warning comment" << std::endl; }
void Harl::error(void) { std::cout << "error comment" << std::endl; }

void Harl::complain(std::string level)
{
	const int size = 4;
	std::string levels[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[size])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < size; i++)
	{
		if (level == levels[i])
		{
			(this->*funcPtr[i])();
			return;
		}
	}
}
