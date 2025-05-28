/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:43:06 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:53:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GRAY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

class AForm; // Forward declaration of AForm class
class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		//member functions:
		AForm *makeForm(std::string formName, std::string formTarget);
		AForm *makeShrubbery(std::string formTarget);
		AForm *makeRobotomy(std::string formTarget);
		AForm *makePresidential(std::string formTarget);
		
		//exceptions
		class FormNameDoesNotExistException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
