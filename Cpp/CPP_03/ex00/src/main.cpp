/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:14 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/19 12:11:17 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	jul = ClapTrap("Jul");
	ClapTrap	marc = ClapTrap("Marc");

	std::cout << marc.get_Name() << std::endl;
	marc = jul;
	std::cout << marc.get_Name() << std::endl << std::endl;

	std::cout << "\033[38;5;220mCreat 4 ClapTrap default_name :\033[0m" << std::endl;
	ClapTrap	didi[4];

	std::cout << "\033[38;5;220mJul attack 3 X :\033[0m" << std::endl;
	jul.attack("a sock ");
	jul.attack("a sock ");
	jul.attack("a sock ");

	std::cout << "\033[38;5;220mJul is touching 4 X :\033[0m" << std::endl;
	jul.take_Damage(4);

	std::cout << "\033[38;5;220mJul is touching 12 X :\033[0m" << std::endl;
	jul.take_Damage(12);

	jul.attack("a sock ");

}

