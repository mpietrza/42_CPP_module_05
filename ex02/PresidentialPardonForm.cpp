/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:33:42 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/09 12:04:50 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("generic target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm  &other)
{
	if (this != other)
	{
		AForm::operator=(other)
		_target = other._target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	retrun out << form.getTarget + " " << form.getName() << " needs a grade " << form.getGradeToSign() << " to be signed, and a grade "<< form.getGradeToExecute() << " to be executed eand it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet."_);
}
