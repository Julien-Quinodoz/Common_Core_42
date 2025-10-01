/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:12 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/03 17:00:00 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H

# include <string>
# include "AForm.hpp"

# undef  SIGN_GRADE
# define SIGN_GRADE 145
# undef  EXEC_GRADE
# define EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
	private:
		const	std::string _target;
		void	beExecuted(void) const;

	public:
		ShrubberyCreationForm(void);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &src);
};

#endif