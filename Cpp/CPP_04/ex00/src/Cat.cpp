/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:32 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 15:41:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "\033[38;5;177m -> Default Cat constructor\033[0m" << std::endl;
}
/*
Cat::Cat(std::string type): _type(type)
{
	std::cout << "\033[38;5;177m -> Parametric Cat constructor\033[0m" << std::endl;
}
*/

Cat::Cat(const Cat &src) : Animal(src._type)
{
	std::cout << "\033[38;5;177m  -> Copy Cat constructor\033[0m" << std::endl;
	*this = src;
}

Cat 	&Cat::operator =(const Cat &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;177m -> Copy assignement Cat\033[0m" << std::endl;
		this->_type = src._type;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "\033[38;5;177m -> Cat destructor\033[0m" << std::endl;
}

void	Cat::make_Sound(void) const
{
	std::cout << "\033[1;21m\033[38;5;220mMeow Meowww  Meow MoooooWWWw meow !\033[0m" << std::endl;
}
