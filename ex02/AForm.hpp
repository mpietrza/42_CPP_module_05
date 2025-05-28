/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:04:25 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/28 15:37:17 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define GRAY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat; // Forward declaration to avoid circular dependency
class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		//getters
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		virtual std::string getTarget() const = 0;

		//member functions
		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void beExecuted() const = 0;

		//exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class NotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

//overload << operator
std::ostream &operator<<(std::ostream &out, const AForm &entity);

#endif
