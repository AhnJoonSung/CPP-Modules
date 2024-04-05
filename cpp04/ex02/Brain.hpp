#pragma once

#include <string>

class Brain
{
private:
	static const int SIZE = 100;
	std::string ideas[SIZE];

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
};
