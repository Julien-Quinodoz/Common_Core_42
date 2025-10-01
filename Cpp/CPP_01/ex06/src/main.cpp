/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:58:27 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/17 21:14:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#include <Harl.hpp>

int main(int ac , char ** av)
{
	Harl harl;

	if (ac >= 2)
		harl.complain(av[1]);
	else
		harl.complain("");
	return 0;
}
