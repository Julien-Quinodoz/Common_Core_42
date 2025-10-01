/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:34 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 16:14:49 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "\033[38;5;114m -> Default Dog constructor\033[0m" << std::endl;
	this->_brain = new Brain();
}
/*
Dog::Dog(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric Dog constructor\033[0m" << std::endl;
}
*/

Dog::Dog(const Dog &src) : Animal(src._type)
{
	std::cout << "\033[38;5;114m -> Copy Dog constructor\033[0m" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog 	&Dog::operator =(const Dog &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;114m -> Copy assignement Dog\033[0m" << std::endl;
		this->_type = src._type;
		this->_brain->set_Ideas(src._brain->get_Ideas());
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "\033[38;5;114m -> Dog destructor\033[0m" << std::endl;
	delete this->_brain;
}

void	Dog::make_Sound(void) const
{
	std::cout << "\033[1;21m\033[38;5;167m Woof Woof Woof Woof Woof Woof!\033[0m" << std::endl;
}

Brain	*Dog::get_Brain(void) const
{
	return this->_brain;
}