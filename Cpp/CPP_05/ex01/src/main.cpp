/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:23:22 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 09:40:07 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
std::cout << B "=========================================" E << std::endl;
std::cout << B "=========================================\n" E << std::endl << std::endl;

	Bureaucrat	julien 		= Bureaucrat("Julien", 3);
	Bureaucrat	julien_copy = julien;
	Bureaucrat	didi 		= Bureaucrat("didi", 102);
	Bureaucrat	lol 		= Bureaucrat("Lol", 20);

	Form		f1 = Form("f1", 100, 1); //copie d'un TMP
	Form		f2 = Form("f2", 2, 1);
	Form		f3 = Form("f3", 20, 1);
	Form 		f4 = Form("f4", 18, 2);
	Form 		f4_copy = f4;

std::cout << B "======== Surchage << Form ========\n" E << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << f4 << std::endl;
	std::cout << f4_copy << std::endl;

std::cout << B "======== Incorrect Form Grade ========\n" E << std::endl;

	try
	{
		Form	f4 = Form("f4", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f4 = Form("f4", 1, 166);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

std::cout << B "======== SignForm: didi sign F1 ========\n" E << std::endl;

	try
	{
		didi.signForm(f1);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	didi.incrementGrade();
	didi.incrementGrade();
	std::cout << B "\tNew grade of didi : " E << didi.getGrade() << std::endl;

		try
	{
		didi.signForm(f1);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cout << B "======== BeSigned: Julien sign F2 ========\n" E << std::endl;

	try
	{
		f2.beSigned(julien);
		std::cout << G "\t\t ==> OK <==" E << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cout << B "======= BeSigned: Julien_copy (+1) sign F2 =======\n" E << std::endl;

	julien_copy.incrementGrade();

	try
	{
		f2.beSigned(julien_copy);
		std::cout << G "\t\t ==> OK <==\n" E << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cout << B "======== SignForm: Lol sign F3 ========\n" E << std::endl;

	try
	{
		lol.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cout << B "======== Comparison of the beginning ========\n" E << std::endl;

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << f4 << std::endl;
	std::cout << f4_copy << std::endl;

std::cout << B "==========================================" E << std::endl;
std::cout << B "==========================================\n" E << std::endl;

	return 0;
}