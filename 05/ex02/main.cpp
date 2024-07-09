#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {

	try
	{
		Bureaucrat jooahn("jooahn", 1);
		Bureaucrat low("low", 150);
		ShrubberyCreationForm shrubberyCreationForm("home");

		jooahn.executeForm(shrubberyCreationForm);
		low.executeForm(shrubberyCreationForm);

		jooahn.signForm(shrubberyCreationForm);

		jooahn.executeForm(shrubberyCreationForm);
		low.executeForm(shrubberyCreationForm);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
