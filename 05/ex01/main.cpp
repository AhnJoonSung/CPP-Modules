#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

	try
	{
		Form a("a", 1, 1);
		Bureaucrat jooahn("jooahn", 1);

		jooahn.signForm(a);
		jooahn.decrement();
		jooahn.signForm(a);

		Form c("c", 0, 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
