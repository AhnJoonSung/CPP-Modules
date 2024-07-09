#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	static const int SIZE = 5;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	bool isspace(std::string str);

public:
	bool inputFields();
	void printSummary();
	void printDetails();
};

#endif
