/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:04:28 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 10:34:08 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "\e[48;5;111m" << std::endl;
	std::cout << "\n\n\n\n" << std::endl << std::endl;
	std::cout << B "\e[48;5;111m				CPP05 - EX03					" E << std::endl;
	std::cout << B "\e[48;5;111m" E << std::endl << std::endl;

	// Test des Bureaucrats
	std::cout << B "======== Test des Bureaucrats ========\n" E << std::endl;
	Bureaucrat	julien = Bureaucrat("Julien", 3);
	Bureaucrat	julien_copy = julien;
	Bureaucrat	didi = Bureaucrat("didi", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	std::cout << "Julien:\t" 	<< julien << std::endl;
	std::cout << "didi: \t" 	<< didi << std::endl;
	std::cout << "Lou: \t" 		<< lou << std::endl;

	// Test de l'Intern
	std::cout << B "\n======== Test formulaires créés par l'Intern ========\n" E << std::endl;
	Intern		Esclave = Intern();

	// Test des formulaires créés par l'Intern
	AForm	*f1 = Esclave.makeForm("shrubbery creation", "campus");
	AForm	*f2 = Esclave.makeForm("Robotomy request", "Rb-42");
	AForm	*f3 = Esclave.makeForm("presidential pardon", "Captain Sparrow ");

			std::cout << *f1 << std::endl;
			std::cout << *f2 << std::endl;
			std::cout << *f3 << std::endl;

	// Test avec un formulaire inconnu
	std::cout << B "\n=== Test avec un formulaire inconnu ===\n" E << std::endl;

			Esclave.makeForm("42", "Ecole de Lausanne");

	// Test des signatures et exécutions
	std::cout << B "\n======== Test des signatures et exécutions ========\n" E << std::endl;



	std::cout << B "\n=== Test avec Julien (grade 3) ===\n" E << std::endl;
	julien.executeForm(*f1);
	didi.signForm(*f1);
	julien.signForm(*f1);
	didi.executeForm(*f1);
	julien.executeForm(*f1);

	std::cout << std::endl << *f1 << std::endl;

	std::cout << B "\n=== Test avec Lou (grade 20) ===\n" E << std::endl;
	lou.signForm(*f2);
	lou.executeForm(*f2);

	std::cout << std::endl << *f2 << std::endl;

	std::cout << B "\n=== Test avec didi (grade 150) ===\n" E << std::endl;
	didi.signForm(*f3);
	lou.signForm(*f3);
	didi.executeForm(*f3);
	julien.executeForm(*f3);

	std::cout << std::endl << *f3 << std::endl;

	// Nettoyage
	std::cout << B "\n======== Nettoyage ========\n" E << std::endl;
	delete f1;
	delete f2;
	delete f3;

	std::cout << std::endl;
	std::cout << "\e[48;5;111m\n					FIN				" << std::endl;
	std::cout << "\n\n\n\n" << std::endl << std::endl;

	return 0;
}
