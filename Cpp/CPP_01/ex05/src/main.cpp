/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:58:27 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 14:05:37 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#include <Harl.hpp>

int main(void)
{
	Harl harl;
	std::cout << "DEBUG : ";
	harl.complain("debug");
	std::cout << std::endl << "INFO : ";
	harl.complain("info");
	std::cout << std::endl << "WARNING : ";
	harl.complain("warning");
	std::cout << std::endl << "ERROR : ";
	harl.complain("error");
	return 0;
}
