#pragma once
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	~Animal();

	virtual void makeSound() const;
	virtual std::string getType() const;
};
