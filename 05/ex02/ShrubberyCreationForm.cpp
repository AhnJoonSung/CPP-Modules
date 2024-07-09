#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const {
	std::ofstream file(target + "_shrubbery");
	if (!file.is_open())
		return ;

	file << "$&X&&X&&&$X&&&&&$x$&$&$xX&&&$$$xX$$$XXX\n";
	file << "::;;;;;;;++;;;;;;;;+;++xxxxX$$$$XX$&$&$\n";
	file << ";;;;;;;:::;+xx+;+++x+;;;+;;:....:::::::\n";
	file << ";;;;;;;;+xxXxxxx+X;+Xxx+++;+;;;;;;;;;;:\n";
	file << ";;;;;;;xXXXXx+x++Xx+xxxXXX++++;;;;;;;;;\n";
	file << "++++++xxxXXxXx+x+xx++xx+x+;;+x;;;;;;;;;\n";
	file << ".....:x$XXxXXxxXxXX$Xxx+xx+xx+x+;;;;;;;\n";
	file << ".....:x$XXXXxxxX$xxxXxXxxxxxxx++;;;;+++\n";
	file << "......+$$XXX+Xxx+++$XxXxxX+Xx+x:.......\n";
	file << "+++xXx+x$$$$XXXXXXXXxxXxxxxxxx:........\n";
	file << "x$$$$$$&$$$$&&X$X$XX$xXxx++x:..........\n";
	file << "+++xX$$$$&&&&&&$&$$&&$&$$$x+;;+++++;;;;\n";
	file << "++++++;++;+++++;;;;;+;;;+++++++++++++++\n";

	file.close();
}
