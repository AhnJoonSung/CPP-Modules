#include "AMateria.hpp"
#include <string>

AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const &) {}

AMateria::AMateria(const AMateria &) {}

AMateria &AMateria::operator=(const AMateria &) { return (*this); }

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &) {}
