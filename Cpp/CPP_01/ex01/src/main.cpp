/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:11:12 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:26:46 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(int ac, char **av)
{
	if(ac != 3)
	{
		std::cout<<"./horde   < how many ?>    <name ?>     for create zombie 🧟 ?"<< std::endl;
		return 1;
	}

	int nb;
	std::string name = av[2];
	int i;

	nb = atoi(av[1]);
	i = 0;
	Zombie *horde;
	horde = zombie_Horde(nb, name);
	while(i < nb)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return 0;
}

