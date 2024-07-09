#include "Bureaucrat.hpp"
#include <iostream>

int main() {

	try
	{
		Bureaucrat jooahn("jooahn", 1);
		std::cout << jooahn << std::endl;
		Bureaucrat joonsung("joonsung", 150);
		std::cout << joonsung << std::endl;
		jooahn.decrement();
		joonsung.increment();
		jooahn.increment();
		jooahn.increment();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
