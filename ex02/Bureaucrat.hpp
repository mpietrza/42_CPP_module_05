/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:22:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:39:24 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define GRAY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		//getters:
		std::string getName() const;
		int getGrade() const;
		
		//memeber functions:
		void increaseGrade(int number);
		void decreaseGrade(int number);
		
		void signForm(AForm &form);
		void executeForm(AForm &form);

		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

//overload << operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &entity);

#endif
