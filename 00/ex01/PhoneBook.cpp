#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	idx = 0;
	cnt = 0;
}

void PhoneBook::add()
{
	Contact newContact;
	if (newContact.inputFields() == false)
		return;
	phoneBook[idx++ % SIZE] = newContact;
	if (cnt < SIZE)
		cnt++;
}

void PhoneBook::search()
{
	if (cnt < 1)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	for (int i = 0; i < cnt; i++)
	{
		Contact contact = phoneBook[i];
		std::cout << std::right << std::setw(10) << i << '|';
		contact.printSummary();
	}

	std::cout << "Input index of the entry to display." << std::endl;
	std::string input;
	int index;
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
		std::istringstream iss(input);
		if ((iss >> index) && !(iss >> input) && !outOfIndex(index))
			break;
		std::cout << "Wrong index. Please retry." << std::endl;
	}

	phoneBook[index].printDetails();
}

bool PhoneBook::outOfIndex(int index)
{
	if (index < 0)
		return true;
	if (index >= cnt)
		return true;
	return false;
}
