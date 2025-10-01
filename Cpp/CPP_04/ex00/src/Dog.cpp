/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:34 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 15:40:05 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "\033[38;5;177m -> Default Dog constructor\033[0m" << std::endl;
}
/*
Dog::Dog(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric Dog constructor\033[0m" << std::endl;
}
*/

Dog::Dog(const Dog &src) : Animal(src._type)
{
	std::cout << "\033[38;5;177m  -> Copy Dog constructor\033[0m" << std::endl;
	*this = src;
}

Dog 	&Dog::operator =(const Dog &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement Dog\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "\033[38;5;177m -> Dog destructor\033[0m" << std::endl;
}

void	Dog::make_Sound(void) const
{
	std::cout << "\033[1;21m\033[38;5;167m Woof Woof Woof Woof Woof Woof!\033[0m" << std::endl;
}
