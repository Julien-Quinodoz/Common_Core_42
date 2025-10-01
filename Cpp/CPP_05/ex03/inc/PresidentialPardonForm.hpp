/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:06 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/03 16:56:04 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

# include <string>
# include "AForm.hpp"

# undef 	SIGN_GRADE				//UNDEF réinitalise le define, évite des erreurs
# define	SIGN_GRADE 25
# undef		EXEC_GRADE
# define	EXEC_GRADE 5

class PresidentialPardonForm: public AForm
{
	private:
		const std::string	_target;

		void	beExecuted(void) const;

	public:
		PresidentialPardonForm(void);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator =(const PresidentialPardonForm &src);
};

# endif