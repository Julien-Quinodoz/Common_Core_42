/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:03:45 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 10:33:15 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}
Intern::Intern(const Intern &src)
{
	*this = src;
}
Intern::~Intern(void)
{
}
Intern	&Intern::operator =(const Intern &src)
{
	(void)src;
	return *this;
}

static AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm				*createdForm = NULL;
	const std::string	formsNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formsFun[])(std::string target) = {&createShrubbery, &createRobotomy, &createPresident};

	std::transform(name.begin(), name.end(), name.begin(), ::tolower); 				// transforme en minuscules
	for (size_t cur = 0; cur < (sizeof(formsNames) / sizeof(formsNames[0])); cur++) //calcule le nombre d'éléments : (formsNames) / sizeof(formsNames[0])
	{
		if (name == formsNames[cur])
		{
			createdForm = formsFun[cur](target);
			break;
		}
	}
	if (!createdForm)
		std::cout << R "Il n'y a pas de formulaire avec le nom \" " E << name << G " \", mais je peux faire les formulaires suivants : \n\"shrubbery creation\", \"robotomy request\", \"presidential pardon\"." E<< std::endl;
	return createdForm;
}
