/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:09 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 10:15:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "\033[38;5;177mDefault ClapTrap constructor\033[0m" << std::endl;
	this->_name 		= "** default_name **";
	this->_hit_pts		= 10;
	this->_energy_pts	= 10;
	this->_attack_pts	= 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "\033[38;5;177mParametric ClapTrap constructor for: \033[0m" << this->_name << std::endl;
	this->_hit_pts		= 10;
	this->_energy_pts	= 10;
	this->_attack_pts	= 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "\033[38;5;177mCopy constructor for : \033[0m" << src.get_Name() << std::endl;
	*this = src;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177mCopy assignement for : \033[0m" << src.get_Name() << std::endl;
		this->_name 		= src.get_Name();
		this->_hit_pts		= src.get_Hit_pts();
		this->_energy_pts 	= src.get_Energy_pts();
		this->_attack_pts	= src.get_Attack_pts();
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[38;5;177mDestructor ClapTrap for : \033[0m" << this->_name << std::endl;
}

std::string		ClapTrap::get_Name(void) const
{
	return this->_name;
}

unsigned int	ClapTrap::get_Hit_pts(void) const
{
	return this->_hit_pts;
}

unsigned int	ClapTrap::get_Energy_pts(void) const
{
	return this->_energy_pts;
}

unsigned int	ClapTrap::get_Attack_pts(void) const
{
	return this->_attack_pts;
}

void	ClapTrap::attack(const std::string &target)
{
	if(this->_hit_pts <= 0 || this->_energy_pts <= 0)
	{
		std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name << " \e[48;5;156mhas no hit pts or has no energy pts !\033[0m" << std::endl;
		return;
	}
	std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name << "\033[38;5;210m attacks \033[0m" << target << ", \e[48;5;217mcausing " << this->_attack_pts << " pts of domage !\033[0m" << std::endl;
	this->_energy_pts--;
}

void	ClapTrap::take_Damage(unsigned int amount)
{
	if(this->_hit_pts <= 0)
	{
		std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name << " \e[48;5;216m💀 doesn't have any hit points left.\033[0m" << std::endl;
		return;
	}
	if (this->_hit_pts > amount)
		this->_hit_pts -= amount;
	else
		this->_hit_pts = 0;
	std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name	<< " \e[48;5;194mtook " << amount << " \e[48;5;194mdamage, now have " << this->_hit_pts << " \e[48;5;194mhit pts left ...\033[0m" << std::endl;
}

void	ClapTrap::be_Repaired(unsigned int amount)
{
	if(this->_hit_pts <= 0 || this ->_energy_pts <= 0)
	{
		std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name << " \e[48;5;216mdoesn't have any hit pts left 💀 !\033[0m" << std::endl;
		return;
	}
	std::cout << "\e[48;5;153mClapTrap:\033[0m " << this->_name << " \e[48;5;183mwon " << amount << " hit pts ! now have : " << this->_hit_pts + amount <<  " !\033[0m" << std::endl;
	this->_hit_pts += amount;
	this->_energy_pts--;
}

