/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:55:16 by ocartier          #+#    #+#             */
/*   Updated: 2025/07/03 19:02:59 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &src);
		Intern	&operator =(const Intern &src);

		AForm	*makeForm(std::string name, std::string target);
};

#endif
