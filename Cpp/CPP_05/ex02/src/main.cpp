/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:38 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 09:42:54 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
std::cout << B "=========================================" E << std::endl;
std::cout << B "=========================================\n" E << std::endl << std::endl;


	// Test des grades limites
	Bureaucrat	julien = Bureaucrat("Julien", 3);
	Bureaucrat	didi = Bureaucrat("didi", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);
	Bureaucrat	maxGrade = Bureaucrat("Max", 1);
	Bureaucrat	minGrade = Bureaucrat("Min", 150);

	// Test des formulaires
	std::cout << B "======== Test des formulaires ========\n" E << std::endl;

	ShrubberyCreationForm	f1 = ShrubberyCreationForm("campus ");
	RobotomyRequestForm		f2 = RobotomyRequestForm("Rb42 ");
	PresidentialPardonForm	f3 = PresidentialPardonForm("Captain Sparrow ");

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	// Test avec un grade trop bas
	std::cout << B "\n=== Test avec un grade trop bas ===\n" E;
	try {
		Bureaucrat	tooLow = Bureaucrat("TooLow", 166);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Test avec un grade trop haut
	std::cout << B "\n=== Test avec un grade trop haut ===\n" E;
	try {
		Bureaucrat	tooHigh = Bureaucrat("TooHigh", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Test des signatures et exécutions
	std::cout << B "\n=== Test des signatures et exécutions ===\n";
	julien.executeForm(f1);
	didi.signForm(f1);
	julien.signForm(f1);
	didi.executeForm(f1);
	julien.executeForm(f1);

	// Test des grades insuffisants
	std::cout << B "\n=== Test des grades insuffisants ===\n" E;
	Bureaucrat stagière = Bureaucrat("Stagière", 140);
	stagière.signForm(f2);
	stagière.executeForm(f2);

	// Test des grades suffisants
	std::cout << B "\n=== Test des grades suffisants ===\n" E;
	maxGrade.signForm(f3);
	maxGrade.executeForm(f3);

	// Test des copies
	std::cout << B "\n=== Test des copies ===\n" E;
	Bureaucrat	julien_copy = julien;
	std::cout  << julien << std::endl;

	julien_copy.incrementGrade();
	std::cout << julien_copy << std::endl << std::endl;

	RobotomyRequestForm	f2_copy = f2;
	julien.signForm(f2);

	std::cout << "f2:\n " << f2 << std::endl;
	std::cout << "f2_copy: \n" << f2_copy << std::endl;


	// Test de la robotomisation
	std::cout << B "======== Test de la robotomisation  ========\n" E << std::endl;

	RobotomyRequestForm	robot1 = RobotomyRequestForm("Robot1");
	RobotomyRequestForm	robot2 = RobotomyRequestForm("Robot2");
	didi.signForm(robot1);
	julien.signForm(robot1);
	lou.signForm(robot2);

	for (int i = 0; i < 8; i++) {
		std::cout << V "\nTentative " E << i + 1 << ":" << std::endl;
		julien.executeForm(robot1);
		julien.executeForm(robot2);
	}


	std::cout << std::endl << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << B "=========================================" E << std::endl;
	std::cout << B "=========================================\n" E << std::endl << std::endl;

	return 0;
}
