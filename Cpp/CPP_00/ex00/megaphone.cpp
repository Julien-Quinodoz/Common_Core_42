/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:45:29 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/11 22:14:28 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int i;
	int j;
	int check;

	i = 1;
	j = 0;
	check = 0;
	while(av[i])
	{
		if(av[i][0])
			check = 1;
		i++;
	}
	if(ac == 1 || check == 0)
	std::cout <<"\033[1;34m* LOUD AND UNBEARABLE FEEDBACK NOISE *\e[0m" << std:: endl;
	else
	{
		i = 1;
		while(av[i])
		{
			j = 0;
			while(av[i][j])
			{
				std::cout << (char)std::toupper(av[i][j]);
				j++;
			}
			if (av[i + 1])
					std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}

/*
1 Si aucun argument n'est fourni, affiche * LOUD AND UNBEARABLE FEEDBACK NOISE *.
2 Sinon, convertit chaque argument en majuscules et les affiche en les séparant par des espaces.
3 Gère correctement l'affichage en s'assurant qu'un espace ne soit pas ajouté après le dernier mot.
*/