/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:50:21 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/18 10:02:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <cstdlib> // random
#include <ctime>
#include <string>
#include <typeinfo>

# define BL "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

class Base
{
	public:
		virtual ~Base(void);
		static Base * generate(void);	//genere un objt au hasard
		static void identify(Base * ptr); //pointeur
		static void identify(Base & p); // referance
};

class A : public Base {};	// Classes vides qui herite de Base

class B : public Base {};

class C : public Base {};
#endif