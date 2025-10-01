/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:17:58 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 15:00:03 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

# include <string>
#include <iostream>

template < typename T, typename F >
void iter(T *arr, size_t len, F fonction)
{
	for (std::size_t i = 0; i < len; ++i)
		fonction(arr[i]);
}

template < typename T, typename F >
void iter(T const *arr, size_t len, F fonction)
{
	for (std::size_t i = 0; i < len; ++i)
		fonction(arr[i]);
}

#endif