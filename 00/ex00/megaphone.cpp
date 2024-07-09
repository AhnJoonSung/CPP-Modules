#include <iostream>
#include <string>
#include <cctype>

class Megaphone
{
public:
	void sayLouder(std::string msg)
	{
		std::string upperMsg;
		for (std::size_t i = 0; i < msg.length(); i++)
			upperMsg += std::toupper(static_cast<unsigned char>(msg[i]));
		std::cout << upperMsg;
	}
};

int main(int ac, char *av[])
{
	Megaphone megaphone;

	if (ac > 1)
		for (int i = 1; i < ac; i++)
			megaphone.sayLouder(std::string(av[i]));
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
