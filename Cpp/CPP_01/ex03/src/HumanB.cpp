/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:25:04 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:41:54 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
# include "Weapon.hpp"

HumanB::HumanB(std::string name):_name(name)
{
}

HumanB::~HumanB(void)
{
	std::cout<<"HumanB : " << this->_name << " 💀 \033[38;5;210mdestroyed\033[0m" << std::endl;
}

void	HumanB::set_Weapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << "\033[38;5;167m attacks with their : \033[0m" << this->_weapon->get_Type() << std::endl;
}