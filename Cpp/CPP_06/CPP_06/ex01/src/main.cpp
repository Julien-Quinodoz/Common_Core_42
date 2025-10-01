/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:41:37 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/17 19:31:32 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// 1: Create de Data en dinamique
	Data *original = new Data();
	original->id = 101;
	original->name = "Objet_test !";
	original->value = 42.42;

	// Affiche la Data original
	std::cout << G "Original Data object:\n" E ;
	std::cout << J "ID: \t" E << original->id << std::endl;
	std::cout << J "Name: \t" E << original->name << std::endl;
	std::cout << J "Value: \t" E << original->value << std::endl;

	// 2:  transforme l'adresse mémoire contenue dans ptr en un entier uintptr_t,
	uintptr_t adresse_en_int = Serializer::serialize(original);
	std::cout << G "\nSerialized uintptr_t: " J << adresse_en_int << "\n" E ;

	//  3: inverse -> entier uintptr_t en adreese memoire contenant un ptr
	Data* deserialized = Serializer::deserialize(adresse_en_int);

	// Contôle de la deserialisation
	std::cout << G "\nDeserialized Data object:\n" E ;
	std::cout << J "ID: \t" E << deserialized->id << std::endl;
	std::cout << J "Name: \t" E << deserialized->name << std::endl;
	std::cout << J "Value: \t" E << deserialized->value << std::endl;

	//  4: Contôle si il y a pas eu de pertes d'infos
	if (original == deserialized)
	{
		std::cout << G "\nOriginal et pointeur deserialized sont pareils ✅\n" E ;
	}
	else
	{
		std::cout << R "\nOriginal et pointeur deserialized ne correspondent pas ❌ \n" E;
	}
	delete original;
	return 0;
}
