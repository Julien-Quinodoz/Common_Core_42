/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:37 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 10:18:43 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "\033[38;5;177m -> Default WrongAnimal constructor\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric WrongAnimal constructor\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "\033[38;5;177m -> Copy WrongAnimal constructor\033[0m" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "\033[38;5;177m -> WrongAnimal destructor\033[0m" << std::endl;
}

WrongAnimal	&WrongAnimal::operator =(const WrongAnimal &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement WrongAnimal\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

std::string	WrongAnimal::get_Type(void) const
{
	return this->_type;
}

void	WrongAnimal::make_Sound(void) const
{
	std::cout << "\033[38;5;167mI don't really have a sound...\033[0m" << std::endl;
}