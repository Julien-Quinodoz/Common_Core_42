/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:57:14 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 16:17:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "\033[38;5;210m\033[3mDefault DiamondTrap constructor\033[0m" << std::endl;
	this->_name			= "Diamon_Brut";
	this->_hit_pts		= this->FragTrap::_hit_pts;
	this->_energy_pts	= this->ScavTrap::_energy_pts;
	this->_attack_pts	= this->FragTrap::_attack_pts;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "\033[38;5;210m\033[3mParametric DiamondTrap constructor called for \033[0m" << name << std::endl;
	this->_name 		= name;
	this->_hit_pts		= this->FragTrap::_hit_pts;
	this->_energy_pts	= this->ScavTrap::_energy_pts;
	this->_attack_pts	= this->FragTrap::_attack_pts;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "\033[38;5;210m\033[3mCopy DiamondTrap constructor for : \033[0m" << src.get_Name() << std::endl;
	*this = src;
}

DiamondTrap	&DiamondTrap::operator =(const DiamondTrap &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;210m\033[3mCopy assignement DiamondTrap for : \033[0m" << src.get_Name() << std::endl;
		this->_name 		= src.get_Name();
		this->_hit_pts		= src.get_Hit_pts();
		this->_energy_pts 	= src.get_Energy_pts();
		this->_attack_pts	= src.get_Attack_pts();
		this->_guard_mode	= src.get_Guard_mode();
	}
	return *this;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\033[38;5;210m\033[3mDestructor ScavTrap for : \033[0m" << this->_name << std::endl;
}


void		DiamondTrap::whoAmI(void)
{

    std::cout << "\n\033[1;36m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m" << std::endl;
	std::cout << "\n     \e[1;34m🔷 WHO AM I...? 🔷\e[0m\n" << std::endl;
	std::cout << "\e[1;37mRevealing hidden identities...\e[0m\n" << std::endl;

	std::cout << "    \e[48;5;211mDiamond  name:\e[0m \e[1;35m" << this->_name << "\e[0m" << std::endl;
	std::cout << "    \e[48;5;153mClapTrap name:\e[0m \e[1;36m" << this->ClapTrap::_name << "\e[0m" << std::endl;

	std::cout << "\n\e[1;33m✨✨ Dual core personality initialized! ✨✨\e[0m\n" << std::endl;
    std::cout << "\033[1;36m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m" << std::endl;

}