/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:31:26 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:58:43 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Testing Interns ===" << std::endl;
	try 
	{
		Intern intern;
		std::cout << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << std::endl;
		AForm *form1 = intern.makeForm("shrubberry creation", "Garden");
		std::cout << std::endl;
		std::cout << *form1 << std::endl;
		std::cout << std::endl;
		AForm *form2 = intern.makeForm("robotomy request", "RoboTarget");
		std::cout << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << std::endl;
		AForm *form3 = intern.makeForm("presidential pardon", "Criminal");
		std::cout << std::endl;
		std::cout << *form3 << std::endl;
		std::cout << std::endl;

		bureaucrat.signForm(*form1);
		std::cout << std::endl;
		bureaucrat.executeForm(*form1);
		std::cout << std::endl;
		delete form1;
		std::cout << std::endl;

		bureaucrat.signForm(*form2);
		std::cout << std::endl;
		bureaucrat.executeForm(*form2);
		std::cout << std::endl;
		delete form2;
		std::cout << std::endl;

		bureaucrat.signForm(*form3);
		std::cout << std::endl;
		bureaucrat.executeForm(*form3);
		std::cout << std::endl;
		delete form3;
		std::cout << std::endl;

		AForm *invalidForm = intern.makeForm("invalid form", "Target"); // Should throw FormNameDoesNotExistException
		std::cout << std::endl;
		delete invalidForm; // This line should not be reached
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
