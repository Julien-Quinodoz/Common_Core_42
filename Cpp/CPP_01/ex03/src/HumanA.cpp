/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:25:04 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:40:44 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name),_weapon(weapon)
{}

HumanA::~HumanA(void)
{
	std::cout<<"HumanA : " << this->_name << " 💀 \033[38;5;210mdestroyed\033[0m" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << "\033[38;5;167m attacks with their : \033[0m" << this->_weapon.get_Type() << std::endl;
}