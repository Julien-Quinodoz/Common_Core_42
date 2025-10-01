/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:29 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 16:26:05 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "\033[38;5;177m -> Default AAnimal constructor\033[0m" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric AAnimal constructor\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "\033[38;5;177m  -> Copy AAnimal constructor\033[0m" << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator =(const AAnimal &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement AAnimal\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "\033[38;5;177m -> AAnimal destructor\033[0m" << std::endl;
}

std::string	AAnimal::get_Type(void) const
{
	return this->_type;
}

void	AAnimal::make_Sound(void) const
{
	std::cout << "\033[38;5;167mAs an animal, I don't really have a sound...\033[0m" << std::endl;
}
