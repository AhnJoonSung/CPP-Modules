#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

public:
	Form(const std::string& name, const int gradeToSign, const int gradeToExec);
	Form(const Form& other);
	Form &operator=(const Form& other);
	~Form();

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

