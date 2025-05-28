/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:59:32 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:49:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("generic target")
{
	std::cout << GRAY "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GRAY << "RobotomyRequestForm parametric constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	std::cout << GRAY << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << GRAY << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GRAY << "RobotomyRequestForm destructor called" << RESET << std::endl;
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
	return out << YELLOW << form.getTarget() + " " << form.getName() << " needs a grade " << form.getGradeToSign() << " to be signed, and a grade " << form.getGradeToExecute() << " to be executed and it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet.");
}

