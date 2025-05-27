/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:57 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/27 17:21:29 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//default constructor
Bureaucrat::Bureaucrat(): _name("generic"), _grade(42)
{
	std::cout << "Bureaucrat created with a default constructor" << std::endl;
}

//parametrized constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Bureaucrat name: " << name << " with a grade: " << grade << " created with a parametrized constructor" << std::endl;
}

//copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	_grade = other._grade;
	std::cout << "Bureaucrat copied" << std::endl;
}

//assigment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;	
	std::cout << "Bureaucrat assigment operator called" << std::endl;
	return *this;
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//name getter
std::string Bureaucrat::getName() const
{
	return _name;
}

//grade getter
int Bureaucrat::getGrade() const
{
	return _grade;
}

//member functions:
void Bureaucrat::increaseGrade(int number)
{
	if (_grade - number < 1)
		throw GradeTooLowException();
	else
	{
		_grade -= number;
		std::cout << _name << " has increased his grade to " << _grade << std::endl;
	}
}

void Bureaucrat::decreaseGrade(int number)
{
	if (_grade + number > 150)
		throw GradeTooHighException();
	else
	{
		_grade += number;
		std::cout << _name << " has decreased his grade to " << _grade << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " has signed a form " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << _name << " hasn't signed a form " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed a form " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << _name << " couldn't execute a form " << form.getName() << " because " << e.what() << std::endl;			}
}

//exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high! The valid range is from 1 (the highest) to 150 (the lowest).";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low! The valid range is from 1 (the highest) to 150 (the lowest).";
}

//overload << operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &entity)
{
	return out << entity.getName() << ", bureaucrat grade " << entity.getGrade() << ".";
}
