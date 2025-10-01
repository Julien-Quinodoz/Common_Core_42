/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:29 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 17:32:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "\033[38;5;177m -> Default Animal constructor\033[0m" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric Animal constructor\033[0m" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "\033[38;5;177m  -> Copy Animal constructor\033[0m" << std::endl;
	*this = src;
}

Animal	&Animal::operator =(const Animal &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement Animal\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "\033[38;5;177m -> Animal destructor\033[0m" << std::endl;
}

std::string	Animal::get_Type(void) const
{
	return this->_type;
}

void	Animal::make_Sound(void) const
{
	std::cout << "\033[38;5;167mAs an animal, I don't really have a sound...\033[0m" << std::endl;
}

Brain *Animal::get_Brain(void) const
{
	return 0;
}
