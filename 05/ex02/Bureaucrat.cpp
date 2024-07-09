#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
: name(name), grade(grade) {

	if (grade < HIGHEST)
		throw GradeTooHighException();

	if (grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
	}

	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::increment() {
	std::cout << "Before increment: " << *this << std::endl;
	if (grade == HIGHEST)
		throw GradeTooHighException();

	grade--;
	std::cout << "After increment: " << *this << std::endl;
}

void Bureaucrat::decrement() {
	std::cout << "Before decrement: " << *this << std::endl;
	if (grade == LOWEST)
		throw GradeTooLowException();

	grade++;
	std::cout << "After decrement: " << *this << std::endl;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " failed to exectue because " << e.what() << std::endl;
	}
}

const std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
