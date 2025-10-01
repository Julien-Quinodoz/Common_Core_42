/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:04:05 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/17 18:57:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::cout << B "==========================================" E << std::endl;
	try
	{
		if (argc != 2)
			throw std::invalid_argument( R "1 paramètre <     >" E );

		std::cout << std::fixed << std::setprecision(1); // manipulateurs de flux
		//->fixed : affiche les nombres flottants en notation décimale classique (pas scientifique)
		//-> setprecision(1) : affiche un seul chiffre après la virgule.

		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << B "==========================================" E << std::endl;
	return 0;
}