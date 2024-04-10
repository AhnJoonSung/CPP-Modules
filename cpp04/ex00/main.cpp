#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *i = new Dog();
		const Animal *j = new Cat();

		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{ // Wrong Case
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();

		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}
	return 0;
}
