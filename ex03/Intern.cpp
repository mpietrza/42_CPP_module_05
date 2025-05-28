/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:50:58 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:54:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//default constructor
Intern::Intern()
{
	std::cout << GRAY << "Intern created with a default constructor" << RESET << std::endl;
}

//copy constructor
Intern::Intern(const Intern &other)
{
	*this = other; // Use assignment operator to copy
	std::cout << GRAY << "Intern copy constructor called" << RESET << std::endl;

}

//assignment operator
Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this; // Handle self-assignment
	std::cout << GRAY << "Intern assignment operator called" << RESET << std::endl;
	return *this;
}

//destructor
Intern::~Intern()
{
	std::cout << GRAY << "Intern destructor called" << RESET << std::endl;
}

//member functions:
AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm *(Intern::*func[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
	std::string forms[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
		if (formName == forms[i])
			return (this->*func[i])(formTarget);
	std::cout << RED << "Intern couldn't crate a Form " << formName + "." << RESET << std::endl;
	throw FormNameDoesNotExistException();
}

AForm *Intern::makeShrubbery(std::string formTarget)
{
	std::cout << "Intern has created a ShrubberyCreationForm for " << formTarget << std::endl;
	return new ShrubberyCreationForm(formTarget);
}

AForm *Intern::makeRobotomy(std::string formTarget)
{
	std::cout << "Intern has created a RobotomyRequestForm for " << formTarget << std::endl;
	return new RobotomyRequestForm(formTarget);
}

AForm *Intern::makePresidential(std::string formTarget)
{
	std::cout << "Intern has created a PresidentialPardonForm for " << formTarget << std::endl;
	return new PresidentialPardonForm(formTarget);
}

const char *Intern::FormNameDoesNotExistException::what() const throw()
{
	return (RED "There is no such form." RESET);
}
