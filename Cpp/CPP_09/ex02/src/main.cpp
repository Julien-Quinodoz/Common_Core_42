/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:39:19 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/14 19:07:07 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstring>
#include <limits>
#include <cstdio>

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
	struct timeval now;
	gettimeofday (&now, NULL);
	return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

/*

Le programme valide les entrées (entiers non négatifs, sans doublons, compris dans la plage INT),
affiche la séquence d'entrée, la trie par fusion-insertion pour std::vector et std::deque,
affiche la séquence triée et mesure le temps pour chaque conteneur.

--> std::vector : Ses éléments sont stockés dans un bloc de mémoire contigu
	ce qui le rend ultra-rapide pour l'accès aléatoire et les tris
	Mais, l'ajout ou la suppression d'éléments au début ou au milieu est lent

--> std::deque : Ses éléments sont stockés dans plusieurs blocs de mémoire,
	ce qui permet des ajouts ou des suppressions très rapides aux deux extrémités (plus lent au milieux)
	Moins efficace que *vector* pour les opérations qui nécessitent un parcours contigu, comme le tri

	--> Accès : vector ~30% plus rapide
	--> Parcours : vector ~20% plus rapide
	--> push_back : similaire
	--> push_front : deque infiniment plus rapide     */

int main(int ac , char **av)
{
	if(ac < 2) {
		std::cerr << R "Used : " E << av[0] << B " <arguments> <arguments> ..." E << std::endl;
		return (1);
	}

	std::vector<int> vector_data;
	std::deque <int> deque__data;

// --> Création data
	for(int i = 1; i < ac; i++)
	{
		for(size_t j = 0; j < strlen(av[i]); j++)
		{
			if(av[i][j] == '-' && j == 0)
			{
				std::cerr << R "Error: " << av[i] << " is negative" E << std::endl;
				return (1);
			}
			if (!isdigit(av[i][j]))
			{
				std::cerr << R "Error: " << av[i] << " is not a number" E << std::endl;
				return (1);
			}
		}
		if (atol(av[i]) > std::numeric_limits<int>::max())
		{
			std::cerr << R "Error: " << av[i] << " int-max dépassé : --> " E  << std::numeric_limits<int>::max() << std::endl;
			return (1);
		}

		vector_data.push_back(atoi(av[i]));
		deque__data.push_back(atoi(av[i]));
	}

// Contrôle si des nombres sont en double
	std::vector<int> sorted;
	std::copy(vector_data.begin(), vector_data.end(), std::back_inserter(sorted));
	std::sort(sorted.begin(), sorted.end());

	std::vector<int>::iterator it_unique;
	it_unique = std::unique(sorted.begin(), sorted.end());	//	unique déplace les doublons à la fin (à utiliser après un sort)
	if (it_unique != sorted.end())
	{
		std::cerr << R "Error: double values !" E << std::endl;
		return (1);
	}

// Before : Affiche la liste des nombre avant

	std::cout << J "Before:\t" E ;
	for (size_t i = 0; i < vector_data.size(); i++)
		std::cout << vector_data[i] << " ";
	std::cout << std::endl;

// --> std:: VECTOR

	timestamp_t start = get_timestamp();  								// START timer

	PmergeMe<int, std::vector> vector_merge;							// objet de classe PmergeMe template
	std::vector<int> vector_sorted = vector_merge.sort(vector_data);	// méthode sort avec vector

	std::cout << G "After :\t" E ;

	for (size_t i = 0; i < vector_sorted.size(); i++) 					// Affiche la liste des nombre après
	std::cout << vector_sorted[i] << " " ;

	timestamp_t end = get_timestamp(); 									// STOP timer

	std::cout << std::endl << B "Time to process a range of " J << vector_data.size() ;
	std::cout << B " elements with std::" G "vector : " J << end - start << E " us" << std::endl;

// --> std:: DEQUE

	start = get_timestamp();  											// START timer

	PmergeMe<int, std::deque> deque_merge;								// objet de classe PmergeMe template
	std::deque<int> deque_sorted = deque_merge.sort(deque__data);		// méthode sort avec deque

	end = get_timestamp();												 // STOP time

	std::cout << B "Time to process a range of " J << deque__data.size() ;
	std::cout << B " elements with std::" G "deque  : " J << end - start <<  E " us" << std::endl;

// --> CONTROLES

		for (size_t i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] != vector_sorted[i] || sorted[i] != deque_sorted[i])
		{
			std::cerr << R "Error: bad sort" E << std::endl;
			return (1);
		}
	}
		if (sorted.size() != vector_sorted.size() || sorted.size() != deque_sorted.size())
	{
		std::cerr << R "Error: bad sort" E  << std::endl;
		return (1);
	}

	return 0;
}

