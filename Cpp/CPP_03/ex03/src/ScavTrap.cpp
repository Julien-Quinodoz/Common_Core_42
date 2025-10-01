/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:09 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 15:20:54 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "\033[38;5;177m\033[3mDefault ScavTrap constructor\033[0m" << std::endl;
	this->_hit_pts		= 100;
	this->_energy_pts	= 50;
	this->_attack_pts	= 20;
	this->_guard_mode	= false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[38;5;177m\033[3mParametric ScavTrap constructor for: \033[0m" << this->_name << std::endl;
	this->_hit_pts		= 100;
	this->_energy_pts	= 50;
	this->_attack_pts	= 20;
	this->_guard_mode 	= false;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "\033[38;5;177m\033[3mCopy ScavTrap constructor for : \033[0m" << src.get_Name() << std::endl;
	*this = src;
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m\033[3mCopy assignement ScavTrap for : \033[0m" << src.get_Name() << std::endl;
		this->_name 		= src.get_Name();
		this->_hit_pts		= src.get_Hit_pts();
		this->_energy_pts 	= src.get_Energy_pts();
		this->_attack_pts	= src.get_Attack_pts();
		this->_guard_mode	= src.get_Guard_mode();
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[38;5;177m\033[3mDestructor ScavTrap for : \033[0m" << this->_name << std::endl;
}

bool		ScavTrap::get_Guard_mode(void) const
{
	return this->_guard_mode;
}

void		ScavTrap::guard_Gate(void)
{
	if (this->_guard_mode)
		std::cout << "\e[48;5;150mScavTrap: " << this->_name << "  was already in guard gate mode.\033[0m" << std::endl;
	else
		std::cout << "\e[48;5;150mScavTrap: " << this->_name << "  is now in guard gate mode !\033[0m" << std::endl;
	this->_guard_mode = true;
}


void	ScavTrap::attack(const std::string &target)
{
	if(this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{
		std::cout << "\e[48;5;150mScavTrap:\033[0m " << this->_name << " \e[48;5;156mhas no hit pts or has no energy pts !\033[0m" << std::endl;
		return;
	}
	std::cout << "\e[48;5;150mScavTrap:\033[0m " << this->_name << "\033[38;5;210m attacks \033[0m" << target << ", \e[48;5;217mcausing " << this->_attack_pts << " pts of domage !\033[0m" << std::endl;
	this->_energy_pts--;
}
