/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:27:48 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:08:31 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"




void	Zombie::announce(void)
{
	std::cout<< this->_name <<"\033[38;5;198m BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
	return;
}

Zombie::Zombie(std::string name): _name(name)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " : Yes, one less zombie --> 💀\033[38;5;210mdestroyed\033[0m"<< std::endl;
}