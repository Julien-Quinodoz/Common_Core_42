/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:15:42 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/14 11:34:41 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

/*
Le programme évalue une expression en notation polonaise inversée en argument
Il prend en charge les opérations à un seul chiffre avec les suffixes +, -, * et / 
et gère les erreurs (expression non valide, division par zéro, évaluation incomplète).
*/

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << R "Used :" E << av[0] << " < RPN ex: ''3 3 + ''> " << std::endl;
		return (1);
	}

	RPN rpn = RPN();

	try
	{
		std::cout << J "==> " G << rpn.result(av[1]) << "" E << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
