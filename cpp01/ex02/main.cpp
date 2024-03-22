#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::hex << &string << std::endl;
	std::cout << std::hex << stringPTR << std::endl;
	std::cout << std::hex << &stringREF << std::endl;
	return 0;
}
