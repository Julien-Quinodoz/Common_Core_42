/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:09 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/03 16:57:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

# include <string>
# include "AForm.hpp"

# undef  SIGN_GRADE
# define SIGN_GRADE 72
# undef  EXEC_GRADE
# define EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
	private:
		const 	std::string _target;
		void	beExecuted(void) const;

	public:
		RobotomyRequestForm(void);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator =(const RobotomyRequestForm &src);
};

#endif