/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:00:39 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/02 18:13:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form(void);
		~Form(void);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &src);
		Form &operator =(const Form &src);

		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void		beSigned(const Bureaucrat bur);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char *what(void) const throw();
		};
};

std::ostream	&operator <<(std::ostream &o, const Form &form);

#endif
