#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include <exception>

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

protected:
	virtual void performAction() const = 0;

public:
	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);
	virtual ~AForm();

	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

