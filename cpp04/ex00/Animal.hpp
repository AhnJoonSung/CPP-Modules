#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	~Animal(void);

	virtual void makeSound(void) const;
	virtual std::string getType(void) const;
};

#endif
