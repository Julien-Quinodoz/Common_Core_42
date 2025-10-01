/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:31:34 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:43:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
	std::cout<< "Weapon " << this->_type << " 💀 \033[38;5;210mdestroyed\033[0m" << std::endl;
}

void	Weapon::set_Type(std::string type)
{
	this->_type = type;
}

const std::string &Weapon::get_Type() const
{
	return this->_type;
}


