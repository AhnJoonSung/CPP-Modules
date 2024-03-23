#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name("default"), ScavTrap("default"), FragTrap("default"), ClapTrap("default_clap_name")
{
}

DiamondTrap::DiamondTrap(std::string name) {}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {}

DiamondTrap::~DiamondTrap(void) {}

void DiamondTrap::whoAmI() {}
