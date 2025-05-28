/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:31:26 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:24:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat b1("Troye", 2);
		std::cout << b1 << std::endl; // test operator<<

		b1.increaseGrade(1);
		std::cout << b1 << std::endl; // test operator<< after increasing grade

		b1.increaseGrade(1); // Should throw GradeTooHighException

		std::cout << "QWERTYUIOP" << std::endl; // Just to check if the program is still running
	} 
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Billie", 140);
		std::cout << b2 << std::endl; // test operator<<

		b2.decreaseGrade(10);
		std::cout << b2 << std::endl; // test operator<< after decreasing grade

		b2.decreaseGrade(1); // Should throw GradeTooLowException

		std::cout << "QWERTYUIOP" << std::endl; // Just to check if the program is still running
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		std::cout << "Creating Charlie - a bureaucrat with a grade of 0:" << std::endl;
		Bureaucrat b3("Charlie", 0); // Should throw GradeTooHighException

		std::cout << "QWERTYUIOP" << std::endl; // Just to check if the program is still running
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		std::cout << "Creating Lorde - a bureaucrat with a grade of 151:" << std::endl;
		Bureaucrat b4("Lorde", 151); // Should throw GradeTooLowException

		std::cout << "QWERTYUIOP" << std::endl; // Just to check if the program is still running
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
