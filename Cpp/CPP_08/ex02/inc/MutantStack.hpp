/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:16:48 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/28 19:18:06 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MUTANTSTACK_H
# define MUTANTSTACK_H

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define E "\033[0m"

# include <stack>

template <typename T>

class MutantStack: public std::stack<T> {
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack<T> & src);
	MutantStack<T> & operator = (const MutantStack<T> &src);

	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	/*
		^^ création d'un raccourci pour le type d'itérateur du conteneur interne de la pile: (std::deque).
	 typename ici indique que c'est est un type et non une variable statique. */

	iterator		begin();
	const_iterator	begin() const;
	iterator		end();
	const_iterator	end() const;

};

# include "../src/MutantStack.tpp"


#endif