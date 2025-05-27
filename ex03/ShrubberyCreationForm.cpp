/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:24:58 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/23 16:01:01 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("generic target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parametric constructor called - target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
	
void ShrubberyCreationForm::beExecuted() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str(), std::ios_base::out);
	if (!outfile.is_open())
		std::cout << "Error: outfile error!" << std::endl;
	else
	{
		outfile << "    &&&  &&&\n";
		outfile << "  &&&&&\\/&&#&&\n";
		outfile << " &&&#&&&#&&&&&\n";
		outfile << " &&#&&&&&&&&\n";
		outfile << "   &&&||&#&\n";
		outfile << "      ||\n";
		outfile << "      ||\n";
		outfile << "     /__\\\n";
		outfile.close();
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	return out << form.getTarget() + " " << form.getName() << "needs a grade " << form.getGradeToSign() << " to be signed, and a grade " << form.getGradeToExecute() << " to be executed and it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet.");
}