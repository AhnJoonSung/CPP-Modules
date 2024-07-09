#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (gradeToSign < Bureaucrat::HIGHEST || gradeToExec < Bureaucrat::HIGHEST)
		throw Bureaucrat::GradeTooHighException();

	if (gradeToSign > Bureaucrat::LOWEST || gradeToExec > Bureaucrat::LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& other)
: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{}

Form &Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}

	return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (gradeToSign < bureaucrat.getGrade())
		throw Bureaucrat::GradeTooLowException();

	isSigned = true;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExec() const {
	return gradeToExec;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os
	<< form.getName()
	<< ", is signed: " << form.getIsSigned()
	<< ", grade to sign: " << form.getGradeToSign()
	<< ", grade to execute: " << form.getGradeToExec()
	<< std::endl;

	return os;
}
