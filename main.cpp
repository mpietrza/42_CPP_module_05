/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:31:26 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/14 18:36:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;

		b1.increaseGrade(1);
		std::cout << b1 << std::endl;

		b1.increaseGrade(1); // Should throw GradeTooHighException
	} 
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 140);
		std::cout << b2 << std::endl;

		b2.decreaseGrade(10);
		std::cout << b2 << std::endl;

		b2.decreaseGrade(1); // Should throw GradeTooLowException
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat b3("Charlie", 0); // Should throw GradeTooHighException
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat b4("Diana", 151); // Should throw GradeTooLowException
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
