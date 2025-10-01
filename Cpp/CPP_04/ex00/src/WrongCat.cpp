/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:39 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 18:01:23 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "\033[38;5;177m -> Default WrongCat constructor\033[0m" << std::endl;
}

//WrongCat::WrongCat(std::string type): Animal(type)
//{
//	std::cout << "\033[38;5;177m -> Parametric WrongCat constructor\033[0m" << std::endl;
//}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src._type)
{
	std::cout << "\033[38;5;177m -> Copy WrongCat constructor\033[0m" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "\033[38;5;177m -> WrongCat destructor\033[0m" << std::endl;
}

WrongCat	&WrongCat::operator =(const WrongCat &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement WrongCat\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

void	WrongCat::make_Sound(void) const
{
	std::cout << "  meow !" << std::endl;
}

