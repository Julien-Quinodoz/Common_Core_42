/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:11:29 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/03 10:10:07 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>

#include "easyfind.hpp"

int main(int ac, char** av)
{
	if(ac != 2){
		std::cout << ( R "./easyfind  < argument > \n" E );
		return 1;
	}

	int nb = atoi(av[1]);
	std::list<int>	liste;		//création d'une liste chainée de <int>

	liste.push_back(42);		//pusch_back , ajout d'élément
	liste.push_back(21);
	liste.push_back(1337);
	liste.push_back(84);
	liste.push_back(69);

	std::list<int>::iterator it;	//déclares une variable "it" qui est un curseur   pour parcourir la liste std::list<int>.
	it = easyfind(liste, nb);

	if (it == liste.end())			//  liste.end() ;  un itérateur spécial qui pointe juste après le dernier élément si rien trouvé.
		std::cout << J "\n Elément non trouvé 🔍 ! \n" E << std::endl;
	else
		std::cout << J "\n Elément --> " V << *it <<  J "\n Trouvé ✅ \n" E << std::endl; // * it pour accéder à la valeur

	return 0;
}
