/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:23:22 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:21:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name): _name(name)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " 💀 \033[38;5;210mdestroyed\033[0m"<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout<< this->_name << "\033[38;5;198m : BraiiiiiiinnnzzzZ...\033[0m " <<std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}