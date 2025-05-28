/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:24:58 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:47:09 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("generic target")
{
	std::cout << GRAY << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GRAY << "ShrubberyCreationForm parametric constructor called - target: " << target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
	std::cout << GRAY << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << GRAY << "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GRAY << "ShrubberyCreationForm destructor called" << RESET << std::endl;
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
	return out << YELLOW << form.getTarget() + " " << form.getName() << "needs a grade " << form.getGradeToSign() << " to be signed, and a grade " << form.getGradeToExecute() << " to be executed and it" << (form.getIsSigned() ? "'s already signed." : " isn't signed yet.") << RESET;
}