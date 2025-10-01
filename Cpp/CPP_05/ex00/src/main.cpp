/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:19:45 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/02 16:08:06 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

int	main()
{
std::cout << B "======================================\n" E << std::endl << std::endl;

	Bureaucrat	julien = Bureaucrat("Julien", 5);
	std::cout << "\t" << julien << std::endl << std::endl;

std::cout << B "======== Test incrémentations ========\n" E << std::endl;

	try
	{
		for (int i = 0; i < 10; i++)
		{
			julien.incrementGrade();
			std::cout << "\t" << julien << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << "❌ Problem catched..." << std::endl;
	}

	std::cout << std::endl;

std::cout << B "======== Test copy ========\n" E << std::endl;

	Bureaucrat	julien_copy = julien;
	std::cout << "\t" << julien_copy << std::endl;

	std::cout << std::endl;

std::cout << B "======== Test décrémentation ========\n" E << std::endl;

	Bureaucrat	didi = Bureaucrat("didi", 149);
	std::cout << "\t" << didi << std::endl;

	std::cout << std::endl;

	try
	{
		didi.decrementGrade();
		std::cout << "\t" << didi << std::endl;
		didi.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << e.what() << std::endl;
	}

	std::cout << std::endl;

std::cout << B "======== Test instancier hors limites ========\n" E << std::endl;
	try
	{
		Bureaucrat	lou = Bureaucrat("Lou", 151);
		std::cout << lou << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return 0;
}
