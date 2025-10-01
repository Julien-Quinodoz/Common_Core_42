/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:55:18 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/05 12:02:17 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _N(n) {}

Span::~Span(void) {}

Span & Span::operator = (const Span & src){
	if (this == &src)
		return *this;
	_N = src._N;
	_v = src._v;
	return *this;
}

Span::Span(const Span &src) : _N(src._N), _v(src._v) {}


void Span::addNumber(int n){			//add élément par élément
	if(_v.size() == _N)					//si _V est plein , égale à  _N -> exeption max
		throw max_elements();
	_v.push_back(n);					// pusch_back -> STL (conteneur vector) rajoute à la fin
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last){   //  // ajoute a parire d'une liste et des 2 iterateur begin - end
	if (_v.size() + std::distance(first, last) > _N)  		// contrôle de la taille de la liste -> exeption max
		throw max_elements();
	for (   ; first != last ; first++)
			_v.push_back( *first);						//rajoute les éléments un par un
}

long int Span::shortestSpan(){				// calcule la plus petite différence ("span") entre deux éléments consécutifs dans le vecteur (après tri).
	if(_v.size() < 2)
		throw min_elements();
	std::vector<long int> sortedVec(_v.begin(), _v.end());// copie de la lise de _v dans sortedVec
	std::sort(sortedVec.begin(), sortedVec.end());	// puis on trie ce vecteur
	long int i = 1;
	int size = sortedVec.size();
	long int res;
	res = sortedVec[i] - sortedVec[i - 1];			// Calcul du premier écart : On initialise le résultat res avec la différence entre les deux

	while( i < size){
		if (sortedVec[i] - sortedVec[i - 1] < res)  // On parcourt le vecteur trié à partir du second indice.
			res = sortedVec[i] - sortedVec[i - 1];  // si la différence entre deux éléments consécutifs est inférieure à res, on met à jour res.
		i++;
	}
	return res;
}

long long int Span::longestSpan() const { // Trouver l'élément le plus grand et le plus petit sans trie
	if (_v.size() < 2)
		throw min_elements();
	long long int min = *std::min_element(_v.begin(), _v.end()); // std::min_element et max  sont des fonctions  de la bibliothèque standard, qui se trouvent dans l'en-tête <algorithm>
	long long int max = *std::max_element(_v.begin(), _v.end());

return max - min;
}







