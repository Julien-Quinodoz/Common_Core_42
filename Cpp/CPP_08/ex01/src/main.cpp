/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:54:57 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/04 10:03:44 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <vector>

void
Tests_du_sujet() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(2);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << B "shortestSpan --> \t" E << sp.shortestSpan() << std::endl;
	std::cout << B "longestSpan  --> \t" E << sp.longestSpan() << std::endl;
}

void
Tests_sup() {

	std::cout << V "ESSAI DE CAS MAX INT MIN INT" E << std::endl;
	Span sp = Span(5);
	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);
	std::cout << B "LongestSpan: " E << sp.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << sp.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "TESTE SURCHARGE = COPY" E << std::endl;
	Span spcopy = sp;
	std::cout << B "LongestSpan: " E << spcopy.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << spcopy.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "ESSAYER 1 et 0" E << std::endl;
	Span onezero = Span(50);
	onezero.addNumber(1);
	onezero.addNumber(0);
	std::cout << B "LongestSpan: " E << onezero.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << onezero.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout <<  V "ESSAYE 0 ET 0" E << std::endl;
	Span zerozero = Span(2);
	zerozero.addNumber(0);
	zerozero.addNumber(0);
	std::cout << B "LongestSpan: " E << zerozero.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << zerozero.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "TESTE 0 et 1" E << std::endl;
	Span spzeroone = Span(2);
	spzeroone.addNumber(0);
	spzeroone.addNumber(1);
	std::cout << B "LongestSpan: " E << spzeroone.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << spzeroone.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "TESTE -1 ET -1" E << std::endl;
	Span minusone = Span(2);
	minusone.addNumber(0);
	minusone.addNumber(0);
	std::cout << B "LongestSpan: " E << minusone.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << minusone.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "Teste -40 , 40 et 4" E << std::endl;
	Span psneg = Span(50);
	psneg.addNumber(-40);
	psneg.addNumber(40);
	psneg.addNumber(4);
	std::cout << B "LongestSpan: " E << psneg.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << psneg.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout <<  V "ESSAI DE SPAN de 10 000" E << std::endl;
	Span sp10000 = Span(10000);
	for (int i = 0; i < 10000; i++)
		sp10000.addNumber(i);
	std::cout << B "LongestSpan: " E << sp10000.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: "  E << sp10000.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "TESTE 50 NUMÉROS (0-49)" E << std::endl;
	Span sp50 = Span(50);
	for (int i = 0; i < 50; i++)
		sp50.addNumber(i);
	std::cout << B "LongestSpan: " E << sp50.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << sp50.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "ESSAI DU CONSTRUCTEUR DE COPIE DE 50 NOMBRES (0-49)" E << std::endl;
	Span spcopyc = Span(sp50);
	std::cout << B "LongestSpan: " E << spcopyc.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << spcopyc.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "100 NOMBRES DE -50 A 49" E << std::endl;
	Span sp100 = Span(100);
	for (int i = 0; i < 100; i++)
		sp100.addNumber(i - 50);
	std::cout << B "LongestSpan: " E << sp100.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << sp100.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "100 TOUS ÉGAUX" E << std::endl;
	Span spégal = Span(100);
	for (int i = 0; i < 100; i++)
		spégal.addNumber(42);
	std::cout << B "LongestSpan: " E << spégal.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << spégal.shortestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << V "TEST AVEC addNumber(LISTE)" E << std::endl;
	Span sp_liste = Span(5);
	std::vector<int> my_list;
	my_list.push_back(10);
	my_list.push_back(20);
	my_list.push_back(5);
	my_list.push_back(15);
	my_list.push_back(25);

	sp_liste.addNumber(my_list.begin(), my_list.end());

	std::cout << B "LongestSpan: " E << sp_liste.longestSpan() << std::endl;
	std::cout << B "ShorterSpan: " E << sp_liste.shortestSpan() << std::endl << std::endl;

/////////////////////////////////////////////////////////////////////////////////////

	std::cout << J "*** EXCEPTIONS *** " E << std::endl << std::endl;


	std::cout << V "RÉSULTATS À PARTIR D'UNE PORTÉE VIDE :" E << std::endl;

	Span spexception(3);
	try
	{   /*
		spexception.addNumber(1);
		spexception.addNumber(2);
		spexception.addNumber(3);
		*/

		std::cout << B "LongestSpan: " E << spexception.longestSpan() << std::endl;
		std::cout << B "ShorterSpan: " E << spexception.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << V "\nRÉSULTATS AVEC UN SEUL NUMÉR0 :" E << std::endl;

	spexception.addNumber(1);
	try
	{
		std::cout << B "LongestSpan: " E << spexception.longestSpan() << std::endl;
		std::cout << B "ShorterSpan: " E  << spexception.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	spexception.addNumber(2);
	spexception.addNumber(3);


	std::cout << V "\nESSAYEZ D'AJOUTER UN NOMBRE DE PLUS QUE MAX :" E << std::endl;
	try
	{
		spexception.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << J "*** FIN DES TESTS ***" E << std::endl << std::endl;
}


int main() {

	std::cout << J "\n \n Tests du sujet --> \n" E << std::endl;

	Tests_du_sujet();

	std::cout << std::endl;
	std::cout << J " Tests_sup \t--> \n" E << std::endl;
	Tests_sup();

}