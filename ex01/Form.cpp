/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:56:20 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/09 15:48:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//default constructor
Form::Form(): _name("generic"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form created with a deafault constructor" << std::endl;
}

//parametrized constructor
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << name << " with grade to sign: " << gradeToSign << " and grade to execute: " << gradeToExecute << " created with a parametrized constructor." << std::endl;
}

//copy constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
	std::cout << "Form " << getName() << " copied" << std::endl;
}

//assignment operator
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << "Form assignment opearator called" << std::endl;
	return *this;
}

//destructor
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

//name getter
std::string Form::getName() const
{
	return _name;
}

//gradeToSign getter
int Form::getGradeToSign() const
{
	return _gradeToSign;
}

//gradeToExecute getter
int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

//isSigned getter
bool Form::getIsSigned() const
{
	return _isSigned;
}

//member functions
void Form::beSigned(Form *entity)
{
	if (entity._isSigned == false)
		entity._isSigned = true;
	else
		std::cout << "The form: " << _name << " is already signed" << std::endl;
}

//exceptions
const char* Form::GradeTooHighException::what()
const throw()
{
	return "The grade is too high! The valid range is from 1 (the highest) to 150 (the lowest)."
}

const char* Form::GradeTooLowException::what()
const throw()
{
	return "The grade is too low! The valid range is from 1 (the highest) to 150 (the lowest)."
}

//overload << operator
std::ostream &operator<<(std::ostream &out, const Form &entity)
{
	return out << entity.getName() << ", form signed (?): " entity.getisSigned() << " with a grade needed to sign it " << entity,getGradeToSign() <<  " and a grade needed to execute it: " entity.getGradeToSign << std::endl:
}