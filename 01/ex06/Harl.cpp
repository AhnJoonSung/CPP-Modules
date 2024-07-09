#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) { std::cout << "debug comment" << std::endl; }
void Harl::info(void) { std::cout << "info comment" << std::endl; }
void Harl::warning(void) { std::cout << "warning comment" << std::endl; }
void Harl::error(void) { std::cout << "error comment" << std::endl; }
void Harl::insignificant(void) { std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; }

void Harl::complain(std::string level)
{
	const int size = 5;
	std::string levels[size] = {"DEBUG", "INFO", "WARNING", "ERROR", "INSIGNIFICANT"};
	void (Harl::*funcPtr[size])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::insignificant};

	for (int i = 0; i < size; i++)
	{
		if (level == levels[i])
		{
			(this->*funcPtr[i])();
			return;
		}
	}
}
