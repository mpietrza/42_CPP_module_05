/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:57 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/16 15:11:00 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//default constructor
Bureaucrat::Bureaucrat(): _name("generic"), _grade(42)
{
//	std::cout << "Bureaucrat created with a default constructor" << std::endl;
}

//parametrized constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade < 1)
		throw gradeTooHighException();
	else if (grade > 150)
		throw gradeTooLowException();
	else
		_grade = grade;
//	std::cout << "Bureaucrat name: " << name << " with a grade: " << grade << " created with a parametrized constructor" << std::endl;
}

//copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	_grade = other._grade;
//	std::cout << "Bureaucrat copied" << std::endl;
}

//assigment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}		
//	std::cout << "Bureaucrat assigment operator called" << std::endl;
	return *this;
}

//destructor
Bureaucrat::~Bureaucrat()
{
//	std::cout << "Bureaucrat destructor called" << std::endl;
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
		throw gradeTooLowException();
	else
		_grade -= number;
}

void Bureaucrat::decreaseGrade(int number)
{
	if (_grade + number > 150)
		throw gradeTooHighException();
	else
		_grade += number;
}

//exceptions
const char* Bureaucrat::gradeTooHighException::what() const throw()
{
	return "The grade is too high! The valid range is from 1 (the highest) to 150 (the lowest).";
}

const char* Bureaucrat::gradeTooLowException::what() const throw()
{
	return "The grade is too low! The valid range is from 1 (the highest) to 150 (the lowest).";
}

//overload << operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &entity)
{
	return out << entity.getName() << ", bureaucrat grade " << entity.getGrade() << ".";
}
