/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:04:25 by mpietrza          #+#    #+#             */
/*   Updated: 2025/05/09 12:48:41 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <iostream>

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
		void sign(AForm *entity);
		void execute(Bureaucrat const & executor) const;
		virtual void executeEntity() const = 0;

		//exceptions
		class GradeTooHighExecption: public std::exception
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
