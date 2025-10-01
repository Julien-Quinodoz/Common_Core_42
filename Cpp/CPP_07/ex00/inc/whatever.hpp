/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:36:42 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 14:42:09 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define  WHATEVER_H

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

//template<typename T> signal au compilateur :
//“Je vais écrire du code qui dépend d’un type T que je ne connais pas encore.
// Quand tu compiles, tu remplaceras T par le vrai type utilisé.”
template <typename T>
void swap(T &a, T&b)
{
	T tmp 	= a;
	a 		= b;
	b 		= tmp;
}

template <typename T>
T const & max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

template <typename T>
T const & min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

#endif