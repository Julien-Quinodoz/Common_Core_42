/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:21:39 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/02 15:45:31 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASSE_H
# define BUREAUCRAT_CLASSE_H

# include <iostream>
# include <string>

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define E "\033[0m"

# define HIGHT_GRADE 1
# define LOW_GRADE 150

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