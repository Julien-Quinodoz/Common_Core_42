/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:16:42 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/03 17:19:51 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <time.h>

#include "MutantStack.hpp"

int main(void)
{

		std::cout << J "\n*** TESTE STACK MutantStack ***\n" E << std::endl;

		MutantStack<int>	mstack;

		std::cout << B "Test de TOP de 505-42-17 : \n" V ;

		mstack.push(505);
		mstack.push(42);
		mstack.push(17);

		std::cout << "Top actuel \t\t--> : " E << mstack.top() << std::endl;

		std::cout << B "\nTest de POP (size avant et après 2 pop): \n"  ;

		std::cout << V "Taille actuel ]\t\t--> : " E << mstack.size() << std::endl;

		mstack.pop();
		mstack.pop();

		std::cout << V "Taille après 2 pop \t--> : " E << mstack.size() << std::endl;

		std::cout << B "\nTest de PUSH de 33-66-737-2-42-999 et affiche : \n"  ;
		mstack.push(33);
		mstack.push(66);
		mstack.push(737);
		mstack.push(2);
		mstack.push(42);
		mstack.push(999);


		std::cout << B "\nAffiche le début \t--> : " E ;

		MutantStack<int>::iterator it = mstack.begin();

		std::cout << *it << std::endl;

		std::cout << V "\nAffiche le dernier \t--> : " E ;

		MutantStack<int>::iterator ite = mstack.end(); // end() pointe sur la position juste après le dernier élément

		ite--;											// -1 pour afficher le dernier
		std::cout << *ite << std::endl;

		ite++;

		std::cout << B "\nAffiche tout \t\t--> : \n" E ;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}


/////////////////////////////////////////////////////////////////////////////
	{
		std::cout << J "\n*** TESTE LISTE MutantStack ***\n" E << std::endl;

		std::list<int>		mstack;

		mstack.push_back(5);
		mstack.push_back(6);
		mstack.push_back(7);

		std::cout << B "\nAffiche le  dernier nb \t--> : " E ;
		std::cout << mstack.back() << std::endl;

		std::cout << B "\nAffiche la size \t--> : " E ;
		std::cout << mstack.size() << std::endl;

		mstack.pop_back();		//pop le 7

		std::cout << B "\nsize + pop_back \t--> : " E ;
		std::cout << mstack.size() << std::endl;

		mstack.push_back(8);
		mstack.push_back(9);
		mstack.push_back(10);
		mstack.push_back(11);

		std::cout << J "\n+ 8 - 9 - 10 - 11 \n" E ;


		std::list<int>::iterator it_liste = mstack.end();

		--it_liste;			// pour atteindre le dernier nb

		std::cout << *it_liste << std::endl;

		--it_liste;

		std::cout << *it_liste << std::endl;

		--it_liste;

		std::cout << *it_liste << std::endl << std::endl;


		std::list<int>::iterator ite_liste = mstack.begin();

		std::cout << *ite_liste << std::endl;

		++ite_liste;

		std::cout << *ite_liste << std::endl;

		std::cout << B "\nAffiche tout \t\t--> : \n" E ;

		it_liste = mstack.begin();
		ite_liste = mstack.end();

		while (it_liste != ite_liste)
		{
			std::cout << *it_liste << std::endl;
			++it_liste;
		}
	}



// Test 2: Copie et affichage
	{
	std::cout  << J "\n*** TESTE COPIE DE MutantStack ***\n" E << std::endl;

		MutantStack<int> mstack_original;
		mstack_original.push(11);
		mstack_original.push(22);
		mstack_original.push(33);

		MutantStack<int> mstack_copie = mstack_original;

		std::cout << V "Top de l'originale 	: " E << mstack_original.top() << std::endl;
		std::cout << V "Top de la copie 	: " E << mstack_copie.top() << std::endl;

		std::cout << B "\nContenu de la copie : " E << std::endl;
		MutantStack<int>::iterator it_copy = mstack_copie.begin();
		MutantStack<int>::iterator ite_copy = mstack_copie.end();
		while (it_copy != ite_copy)
		{
			std::cout << *it_copy << std::endl;
			++it_copy;
		}

		std::cout << B "\nAjout d'un element 999 à la copie... " E << std::endl;

		mstack_copie.push(999);

		std::cout << V "Nouveau top de la copie : " E << mstack_copie.top() << std::endl;

		std::cout << B "\n*********************************************** \n" E << std::endl;

	}

	return 0;
}

