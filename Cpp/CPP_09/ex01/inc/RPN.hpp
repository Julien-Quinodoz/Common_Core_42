/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:51:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/24 12:18:51 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_H
# define RPN_CLASS_H

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

#include <string>
#include <list>

class RPN
{
	public:
	RPN(void);
	~RPN(void);
	RPN(const RPN &src);
	RPN & operator = (const RPN &src);


	float result(const std::string expr);

	

	class Bad_expression : public std::exception{
		public:
			virtual const char * what(void) const throw();
	};
	class Division_0 : public std::exception{
		public:
			virtual const char * what(void) const throw();
	};
	class Incomplete_Evaluation : public std::exception{
		public:
			virtual const char * what(void) const throw();
	};

};

#endif