/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:33:42 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:45:07 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("generic target")
{
	std::cout << GRAY << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GRAY << "PresidentialPardonForm parametric constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
	std::cout << GRAY << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm  &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << GRAY << "PresidentialPardonForm copy assignment operator called" << RESET <<  std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GRAY << "PresidentialPardonForm destructor called" << RESET << std::endl;
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
	return out << YELLOW << form.getTarget() + " " << form.getName() << " needs a grade " << form.getGradeToSign() << " to be signed, and a grade "<< form.getGradeToExecute() << " to be executed eand it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet.") << RESET;
}
