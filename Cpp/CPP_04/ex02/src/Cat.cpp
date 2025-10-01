/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:32 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 16:37:35 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "\033[38;5;162m -> Default Cat constructor\033[0m" << std::endl;
	this->_brain = new Brain();
}
/*
Cat::Cat(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric Cat constructor\033[0m" << std::endl;
}
*/

Cat::Cat(const Cat &src) : AAnimal(src._type)
{
	std::cout << "\033[38;5;162m  -> Copy Cat constructor\033[0m" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat 	&Cat::operator =(const Cat &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;162m -> Copy assignement Cat\033[0m" << std::endl;
		this->_type = src._type;
		this->_brain->set_Ideas(src._brain->get_Ideas());
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "\033[38;5;162m -> Cat destructor\033[0m" << std::endl;
	delete this->_brain;
}

void	Cat::make_Sound(void) const
{
	std::cout << "\033[1;21m\033[38;5;220mMeow Meowww Meow MoooooWWWw meow !\033[0m" << std::endl;
}

Brain			*Cat::get_Brain(void) const
{
	return this->_brain;
}
