/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:43:06 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 13:29:06 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
