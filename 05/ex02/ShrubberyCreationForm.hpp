#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string target;

protected:
	void performAction() const;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

};
