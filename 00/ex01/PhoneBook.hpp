#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	static const int SIZE = 8;
	Contact phoneBook[SIZE];
	int idx;
	int cnt;
	bool outOfIndex(int index);

public:
	PhoneBook();
	void add();
	void search();
};

#endif
