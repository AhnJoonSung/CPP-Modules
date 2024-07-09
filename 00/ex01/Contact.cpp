#include "Contact.hpp"
#include <iostream>
#include <iomanip>

bool Contact::inputFields()
{
	std::string fields[SIZE] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string inputs[SIZE];

	int i = 0;
	while (i < SIZE)
	{
		std::cout << "input the " << fields[i] << " of the new contact" << std::endl;
		std::getline(std::cin, inputs[i]);
		if (std::cin.eof())
			return false;
		// 입력이 whitespace로만 이루어져 있으면 에러 처리
		if (isspace(inputs[i]))
		{
			std::cout << "Contact can't have empty fields." << std::endl;
			continue;
		}
		// tab문자는 커다라니까 공백으로 교체
		for (std::size_t j = 0; j < inputs[i].length(); j++)
		{
			if (inputs[i][j] == '\t')
				inputs[i][j] = ' ';
		}
		i++;
	}

	this->firstName = inputs[0];
	this->lastName = inputs[1];
	this->nickname = inputs[2];
	this->phoneNumber = inputs[3];
	this->darkestSecret = inputs[4];
	return (true);
}

bool Contact::isspace(std::string str)
{
	std::string whitespace = " \t\n\r\v\f";

	if (str.find_first_not_of(whitespace) == std::string::npos)
		return true;
	return false;
}

void Contact::printSummary()
{
	int size = 3;

	std::string columns[] = {firstName, lastName, nickname};
	for (int i = 0; i < size; i++)
	{
		std::string col = columns[i];
		if (col.length() > 10)
			std::cout << std::right << std::setw(10) << col.substr(0, 9) + '.';
		else
			std::cout << std::right << std::setw(10) << col;
		if (i != size - 1)
			std::cout << '|';
	}
	std::cout << std::endl;
}

void Contact::printDetails()
{
	std::string datas[] = {firstName, lastName, nickname, phoneNumber, darkestSecret};
	for (int i = 0; i < Contact::SIZE; i++)
		std::cout << datas[i] << std::endl;
}
