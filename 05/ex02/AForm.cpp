#include "AForm.hpp"
#include <iostream>

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (gradeToSign < Bureaucrat::HIGHEST || gradeToExec < Bureaucrat::HIGHEST)
		throw Bureaucrat::GradeTooHighException();

	if (gradeToSign > Bureaucrat::LOWEST || gradeToExec > Bureaucrat::LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& other)
: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{}

AForm &AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}

	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (gradeToSign < bureaucrat.getGrade())
		throw Bureaucrat::GradeTooLowException();

	isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!isSigned) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > gradeToExec) {
		throw Bureaucrat::GradeTooLowException();
	}

	performAction();
}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExec() const {
	return gradeToExec;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os
	<< form.getName()
	<< ", is signed: " << form.getIsSigned()
	<< ", grade to sign: " << form.getGradeToSign()
	<< ", grade to execute: " << form.getGradeToExec()
	<< std::endl;

	return os;
}
