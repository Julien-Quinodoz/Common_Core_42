/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:03 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/03 15:40:32 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASSE_H
# define BUREAUCRAT_CLASSE_H

# include <iostream>
# include <string>
# include "AForm.hpp"

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

# define HIGHT_GRADE 1
# define LOW_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator =(const Bureaucrat &src);

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm &form) const;
		void			executeForm(AForm &form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif