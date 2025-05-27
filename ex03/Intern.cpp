/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:50:58 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/27 18:00:52 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//default constructor
Intern::Intern()
{
	std::cout << "Intern created with a default constructor" << std::endl;
}

//copy constructor
Intern::Intern(const Intern &other)
{
	std::cout << "Intern copied" << std::endl;
}

//assignment operator
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

//destructor
Itern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

//member functions:
AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	if (formName
}
