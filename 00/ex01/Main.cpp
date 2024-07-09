#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string cmd;

	while (1)
	{
		std::cout << "Input command(ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return 0;
		if (cmd.compare("ADD") == 0)
			pb.add();
		else if (cmd.compare("SEARCH") == 0)
			pb.search();
		else if (cmd.compare("EXIT") == 0)
			return 0;
		if (std::cin.eof())
			return 0;
	}
}
