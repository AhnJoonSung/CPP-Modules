#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;

	const int size = 2;
	Animal *animals[size];
	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		delete animals[i];

	// Cat cat;
	// Cat copyCat(cat);
	// Cat copyAssginCat;
	// copyAssginCat = cat;

	// copyCat.setType("copy cat");
	// copyAssginCat.setType("copy assign cat");
	// std::cout << "cat's type is " << cat.getType() << std::endl;
	// std::cout << "copyCat's type is " << copyCat.getType() << std::endl;
	// std::cout << "copyAssginCat's type is " << copyAssginCat.getType() << std::endl;

	return 0;
}
