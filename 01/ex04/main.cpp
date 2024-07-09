#include <string>
#include <fstream>

std::string replace(std::string src, std::string s1, std::string s2);

int main(int ac, char **av)
{
	if (ac != 4)
		return 0;

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream file(filename);
	if (file.is_open())
	{
		std::ofstream rFile(filename + ".replace");
		if (rFile.is_open())
		{
			std::string line;
			while (std::getline(file, line))
				rFile << replace(line, s1, s2) << std::endl;
			rFile.close();
		}
		file.close();
	}

	return 0;
}

std::string replace(std::string src, std::string s1, std::string s2)
{
	size_t pos = 0;
	while ((pos = src.find(s1, pos)) != std::string::npos)
	{
		src.erase(pos, s1.length());
		src.insert(pos, s2);
		pos += s2.length();
	}
	return (src);
}
