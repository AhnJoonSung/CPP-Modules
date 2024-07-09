#pragma once

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat {
private:
	const std::string name;
	int grade;

public:
	static const int HIGHEST = 1;
	static const int LOWEST = 150;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat &operator=(const Bureaucrat& other);
	~Bureaucrat();

	void increment();
	void decrement();

	void signForm(Form& form);

	const std::string getName() const;
	int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
