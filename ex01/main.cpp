/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:31:26 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/27 17:35:44 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	/*try 
	{
		Bureaucrat b1("Troye", 2);
		std::cout << b1 << std::endl;

		b1.increaseGrade(1);
		std::cout << b1 << std::endl;

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
		std::cout << b2 << std::endl;

		b2.decreaseGrade(10);
		std::cout << b2 << std::endl;

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
	}*/

	try
	{
		std::cout << "\n=== Form Tests: Valid signing ===" << std::endl;
		Form f1("F1", 50, 20); 
		Bureaucrat b1("Alice", 49);
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Grade too low to sign ===" << std::endl;
		Form f2("F2", 10, 5); 
		Bureaucrat b2("Bob", 20);
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Additional Form tests

	try
	{
		std::cout << "\n=== Form Tests: Form grade too high ===" << std::endl;
		Form f3("F3", 0, 10); // Should throw GradeTooHighException
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Form grade too low ===" << std::endl;
		Form f4("F4", 151, 10); // Should throw GradeTooLowException
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Execute grade too high ===" << std::endl;
		Form f5("F5", 10, 0); // Should throw GradeTooHighException
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Execute grade too low ===" << std::endl;
		Form f6("F6", 10, 151); // Should throw GradeTooLowException
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Double signing ===" << std::endl;
		Form f7("F7", 100, 50);
		Bureaucrat b3("Clara", 50);
		b3.signForm(f7);
		b3.signForm(f7); // Should not throw, but should indicate already signed
		std::cout << f7 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Form Tests: Multiple bureaucrats signing ===" << std::endl;
		Form f8("F8", 100, 50);
		Bureaucrat b4("Dylan", 120);
		Bureaucrat b5("Emma", 90);
		b4.signForm(f8); // Should fail
		b5.signForm(f8); // Should succeed
		std::cout << f8 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
