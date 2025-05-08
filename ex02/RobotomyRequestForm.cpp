/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:59:32 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/08 17:41:11 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("generic target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::beExecuted() const
{
	std::srand(std::time(NULL));

	std::cout << "VRRRR! DRRRR! VRRRR! BRRRRRRRRRRRRRRRRRRRRRRR!" << std::endl;
	std::cout << _target << (std::rand() % 2 == 0 ? " has been successfully robotomized!" : "'s robotomy failed.") << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	return out << form.getTarget + " " << form.getName() << "needs a grade " << form.getGradeToSign() << " to be signed, and a grade " << form.getGradeToExecute() << " to be executed and it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet.");
}

