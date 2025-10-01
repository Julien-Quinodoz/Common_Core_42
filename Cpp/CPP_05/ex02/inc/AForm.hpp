/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:00 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/03 16:32:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;

		virtual void	beExecuted(void) const = 0;

	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &src);
		AForm &operator =(const AForm &src);

		std::string		getName(void) const;
		bool			isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

		void			beSigned(const Bureaucrat bur);
		void			execute(const Bureaucrat &executor) const;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator <<(std::ostream &o, const AForm &form);

#endif
