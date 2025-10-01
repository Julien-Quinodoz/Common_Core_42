/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:52:50 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/05 12:02:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define E "\033[0m"

class Span {
private:
	unsigned int		_N;
	std::vector<int>	_v;			// tableau dynamique

public:
	Span(unsigned int n);
	~Span(void);
	Span &operator =(const Span &other);
	Span(const Span & src);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
	long int shortestSpan();		// calcule la plus petite différence ("span") entre deux éléments consécutifs dans le vecteur (après tri).
	long long int longestSpan() const ;

	class max_elements : public std::exception
	{
		virtual const char *what() const throw()
		{
			return  ( R "Nombre maximum d'éléments atteind ! " E )  ;
		}
	};

	class min_elements : public std::exception
	{
		virtual const char *what() const throw()
		{
			return  ( R "Le Span doit'être de 2 éléments minimum ! " E )  ;
		}
	};
};

#endif
