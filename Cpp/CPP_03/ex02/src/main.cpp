/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:14 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 14:17:21 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

int main(void)
{
	ClapTrap	jul = ClapTrap("Jul");

	std::cout << std::endl << "\033[38;5;220m\033[1;21mJul attack 2 X :\033[0m" << std::endl;
	jul.attack("a sock ");
	jul.attack("a sock ");

	std::cout << std::endl <<  "\033[38;5;220m\033[1;21mJul is touching 9 X :\033[0m" << std::endl;
	jul.take_Damage(9);

	FragTrap	lol = FragTrap("LoL");


	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mCreat 3 FragTrap default_name :\033[0m" << std::endl;
	FragTrap	jean[3];

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mLoL attack 3 X :\033[0m" << std::endl;
	lol.attack("a humain");
	lol.attack("a humain");
	lol.attack("a humain");
	lol.high_Fives_Guys();
	lol.be_Repaired(5);

}

