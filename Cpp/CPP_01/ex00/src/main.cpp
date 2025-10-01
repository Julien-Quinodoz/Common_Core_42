/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:36:03 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:06:35 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
	std::cout<<"--> Create the Zombie \033[1;34mAlpha\e[0m." << std::endl;
	Zombie alpha = Zombie("Alpha");
	alpha.announce();

	std::cout<<"--> Create the Zombie \033[1;34mBeta\e[0m with \033[38;5;220mnewZombie()\e[0m."<< std::endl;
	Zombie *beta = newZombie("Beta");
	beta->announce();
	delete beta;

	std::cout<<"--> Create the Zombie \033[1;34mOmega\e[0m with \033[38;5;220mrandomChump()\e[0m."<< std::endl;
	randomChump("Omega");

	return 0;
}

/*La principale différence entre les trois zombies est leur gestion en mémoire :

-->alpha est créé sur la pile et sera automatiquement détruit à la fin de la fonction main
-->beta est créé sur le tas via newZombie() et doit être explicitement libéré avec delete
-->Omega est créé (tmp) et géré entièrement à l'intérieur de la fonction randomChump() et actionne announce
*/