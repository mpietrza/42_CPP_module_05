/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:06:55 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/07 13:38:46 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//default constructor
AForm::AForm(): _name("generic"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm created with a deafault constructor" << std::endl;
}

//parametrized constructor
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _isSinged(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else
	{
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
	std::cout << "AForm " << name << " with grade to sign: " << gradeToSign << " and grade to execute: " << gradeToExecute << " created with a parametrized constructor." << std::endl;
}

//copy constructor
AForm::AForm(const AForm &other)
{
	_isSigned = other._isSigned;
	_gradeToSign = other._gradeToSign;
	_gradeToExecute = other._gradeToExecute;
	std::cout << "AForm " << getName(this) << " copied" << std::endl;
}

//assignment operator
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSinged;
		_gradeToSign = other._gradeToSign;
		_gradeToExecute = other._gradeToExecute;
	}
	std::cout << "AForm assignment opearator called" << std::endl;
	return *this;
}

//destructor
AForm::~AForm();
{
	std::cout << "AForm destructor called" << std::endl;
}

//name getter
std::string AForm::getName() const
{
	return _name;
}

//gradeToSign getter
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

//gradeToExecute getter
int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

//member functions
void AForm::beSigned(AForm *entity);
{
	if (entity._isSigned == false)
		entity._isSigned = true;
	else
		std::cout << "The form: " << name << " is already signed" << std::endl;
}

//exceptions
const char* AForm::GradeTooHighException::what()
const throw()
{
	return "The grade is too high! The valid range is from 1 (the highest) to 150 (the lowest)."
}

const char* AForm::GradeTooLowException::what()
const throw()
{
	return "The grade is too low! The valid range is from 1 (the highest) to 150 (the lowest)."
}

//overload << operator
std::ostream &operator<<(std::ostream &out, const AForm &entity);
{
	return out << entity.getName() << ", form signed (?): " entity.getIsSinged() << " with a grade needed to sign it " << entity,getGradeToSign() <<  " and a grade needed to execute it: " entity.getGradeToSign << std::endl:
