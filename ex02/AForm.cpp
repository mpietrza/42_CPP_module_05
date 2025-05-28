/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:06:55 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:43:18 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//default constructor
AForm::AForm(): _name("generic"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << GRAY << "AForm created with a deafault constructor" << RESET << std::endl;
}

//parametrized constructor
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << GRAY << "AForm " << name << " with grade to sign: " << gradeToSign << " and grade to execute: " << gradeToExecute << " created with a parametrized constructor." << RESET << std::endl;
}

//copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << GRAY << "AForm " << getName() << " copied" << RESET << std::endl;
}

//assignment operator
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	std::cout << GRAY << "AForm assignment opearator called" << RESET << std::endl;
	return *this;
}

//destructor
AForm::~AForm()
{
	std::cout << GRAY << "AForm destructor called" << RESET << std::endl;
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

//isSigned getter
bool AForm::getIsSigned() const
{
	return _isSigned;
}

//member functions
void AForm::beSigned(const Bureaucrat &b)
{
	if (_isSigned == true)
		throw AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << "The form: " << _name << " has been signed" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	else if (_gradeToExecute < executor.getGrade())
		throw GradeTooLowException();
	else
		this->beExecuted();
}

//exceptions
const char* AForm::GradeTooHighException::what()
const throw()
{
	return "the grade is too high!";
}

const char* AForm::GradeTooLowException::what()
const throw()
{
	return "the grade is too low!";
}

const char* AForm::AlreadySignedException::what()
const throw()
{
	return "The Form is already signed! Forms can only be signed only once!";
}

const char* AForm::NotSignedException::what()
const throw()
{
	return "The Form is not signed yet! Only signed forms can be executed!";
}

//overload << operator
std::ostream &operator<<(std::ostream &out, const AForm &entity)
{
	return out << GREEN << entity.getName() << ", form signed (?): " << (entity.getIsSigned() ? "yes" : "no") << " with a grade needed to sign it " << entity.getGradeToSign() <<  " and a grade needed to execute it: " << entity.getGradeToExecute() << RESET << std::endl;
}