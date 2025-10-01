/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:49:28 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/18 09:43:05 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "classes.hpp"

int main()
{
	std::srand(std::time(0));

	Base *ptr = Base::generate();
	Base::identify(ptr);
	Base::identify( * ptr);		//déréférance du pointeur; ptr contient un référance de A B ou C

	delete ptr;

	return 0;
}