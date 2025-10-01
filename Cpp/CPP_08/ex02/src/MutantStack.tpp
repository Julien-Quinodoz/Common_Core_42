/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:16:45 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/04 10:10:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

template<class T>
MutantStack<T>::MutantStack()	{}

template<class T>
MutantStack<T>::~MutantStack()	{}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T> &src){
	*this = src;
}

template<class T>
MutantStack<T>  &MutantStack<T>::operator =(const MutantStack<T> &src){
	if (this != &src) {
		std::stack<T>::operator = (src);
	}
	return *this;
}

/*		begin() & end() ne font pas partie de <stack > mais d'un sous conteneur <std::deque>.
le --> * c * <-- est un membre protégé de <stack> pour utiliser utilise le conteneur sous-jacent (std::deque)
Pour permettre aux classes qui héritent d'elle d'accéder à ce conteneur, std::stack a un membre protégé nommé c.
c.begin()  est donc un appel à la méthode begin() du conteneur interne de la pile (std::deque), ce qui vous permet
de créer l'itérateur pour  MutantStack.
*/
template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void){
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void){
	return this->c.end();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const{
	return this->c.end();
}