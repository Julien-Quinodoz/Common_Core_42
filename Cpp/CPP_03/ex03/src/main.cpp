/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:14 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 16:25:34 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"
# include <iostream>

int main(void)
{
	FragTrap	jul = FragTrap("Jul");

	std::cout << std::endl << "\033[38;5;220m\033[1;21mJul attack 2 X :\033[0m" << std::endl;
	jul.attack("a sock ");
	jul.attack("a sock ");

	std::cout << std::endl <<  "\033[38;5;220m\033[1;21mJul is touching 9 X :\033[0m" << std::endl;
	jul.take_Damage(9);

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mCreat 3 Hector DiamondTrap :\033[0m" << std::endl;

	DiamondTrap hector = DiamondTrap("Hector");

	jul.attack("a humain");
	jul.take_Damage(4);

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mCreat 3 FragTrap default_name :\033[0m" << std::endl;
	FragTrap	jean[3];


	hector.whoAmI();


	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mHector attack 3 X :\033[0m" << std::endl;
	hector.attack("a humain");
	hector.attack("a humain");
	hector.attack("a humain");
	hector.high_Fives_Guys();
	hector.be_Repaired(5);

}

