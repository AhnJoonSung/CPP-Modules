#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string target;

protected:
	void performAction() const;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

};
