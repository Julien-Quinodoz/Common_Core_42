/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:19:23 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 14:16:29 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include <iostream>
# include <string>

FragTrap::FragTrap(void)
{
	std::cout << "\033[38;5;114m\033[3mDefault FragTrap constructor\033[0m" << std::endl;
	this->_hit_pts		= 100;
	this->_energy_pts	= 50;
	this->_attack_pts	= 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[38;5;114m\033[3mParametric FragTrap constructor for: \033[0m" << this->_name << std::endl;
	this->_hit_pts		= 100;
	this->_energy_pts	= 100;
	this->_attack_pts	= 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "\033[38;5;114m\033[3mCopy ScavTrap constructor for : \033[0m" << src.get_Name() << std::endl;
	*this = src;
}

FragTrap	&FragTrap::operator = (const FragTrap &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;114m\033[3mCopy assignement FragTrap for : \033[0m" << src.get_Name() << std::endl;
		this->_name 		= src.get_Name();
		this->_hit_pts		= src.get_Hit_pts();
		this->_energy_pts 	= src.get_Energy_pts();
		this->_attack_pts	= src.get_Attack_pts();
	}
	return *this;
}


FragTrap::~FragTrap(void)
{
	std::cout << "\033[38;5;114m\033[3mDestructor FrahTrap for : \033[0m" << this->_name << std::endl;
}


void FragTrap::high_Fives_Guys(void)
{
    std::cout<< std::endl << "\033[1;35m" << this->_name << " : ACTIVATING HIGH-FIVE MODE...\033[0m\n" << std::endl;
    std::cout << "\033[1;36m";
    std::cout << "██╗  ██╗██╗ ██████╗ ██╗  ██╗    ███████╗██╗██╗   ██╗███████╗\n";
    std::cout << "██║  ██║██║██╔════╝ ██║  ██║    ██╔════╝██║██║   ██║██╔════╝\n";
    std::cout << "███████║██║████████╗███████║    █████╗  ██║██║   ██║█████╗  \n";
    std::cout << "██╔══██║██║██║   ██║██╔══██║    ██╔══╝  ██║╚██╗ ██╔╝██╔══╝  \n";
    std::cout << "██║  ██║██║╚██████╔╝██║  ██║    ██║     ██║ ╚████╔╝ ███████╗\n";
    std::cout << "╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═══╝  ╚══════╝\n";
    std::cout << "\033[0m\n";
    std::cout << "\033[1;33m" << std::endl;
}