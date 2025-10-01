/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:58:48 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 10:35:21 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target("untargeted")
{
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(src._target)
{
	*this = src;
}
RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &src)
{
	(void)src;
	return *this;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	// Initialisation de la randomisation (fait une seule fois)
	static bool initialized = false;
	if (!initialized)
	{
		std::srand(std::time(0));
		initialized = true;
	}

	// Génération du nombre aléatoire
	int rand = std::rand() % 2; // 0 ou 1
	if (rand == 1)
	{
		std::cout << B "* ⚙️ 🧨 Bruits de forage 🧨 ⚙️*" E << std::endl;
		std::cout << this->_target << G " a été robotomisé avec succès 🎉" E << std::endl;
	}
	 else
	{
		std::cout << B "* ⚙️ 🧨 Bruits de forage 🧨 ⚙️*" E << std::endl;
		std::cout << R "Oops... ⚠️ la robotomization n'a pas fonctioné pour " E << this->_target << "💥" << std::endl;
	}
}