/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:58:45 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 10:35:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target("Untargeted")
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(src._target)
{
	*this = src;
}
PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &src)
{
	(void)src;
	return *this;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << V "est gracier par Zaphod 👑 Beeblebrox 🍀 " E << std::endl;
}