/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:14 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 10:10:12 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	jul = ClapTrap("Jul");

	std::cout << std::endl << "\033[38;5;220m\033[1;21mJul attack 2 X :\033[0m" << std::endl;
	jul.attack("a sock ");
	jul.attack("a sock ");

	std::cout << std::endl <<  "\033[38;5;220m\033[1;21mJul is touching 8 X :\033[0m" << std::endl;
	jul.take_Damage(8);

	std::cout << std::endl << "\033[38;5;220m\033[1;21mCreat ScavTrap name Marc :\033[0m" << std::endl;
	ScavTrap	marc = ScavTrap("Marc");

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mCreat 3 ClapTrap default_name :\033[0m" << std::endl;
	ScavTrap	jean[3];

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mMarc attack 2 X :\033[0m" << std::endl;
	marc.attack("a humain");
	marc.attack("a humain");

	marc.guard_Gate();
	marc.guard_Gate();
	jul.be_Repaired(2);

	marc.be_Repaired(1);
	marc.be_Repaired(1);

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mJul is touching 8 X :\033[0m" << std::endl;
	jul.take_Damage(8);
	jul.be_Repaired(2);

	std::cout <<  std::endl << "\033[38;5;220m\033[1;21mJul Copy of Marc :\033[0m" << std::endl;

	jul = marc;

	jul.be_Repaired(42);


}

