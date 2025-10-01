/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:28:49 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 16:06:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>
# include <string>

Brain::Brain(void)
{
	std::cout << "\033[38;5;75m -> Default Brain constructor\033[0m" << std::endl;

}

Brain::Brain(const Brain &src)
{
	std::cout << "\033[38;5;75m  -> Copy Brain constructor\033[0m" << std::endl;
	*this = src;

}
Brain	&Brain::operator =(const Brain &src)
{
	if (this != &src)
	{
		std::cout << "\033[38;5;75m -> Copy assignement Brain\033[0m" << std::endl;
		*this->_ideas = *src._ideas;
	}
	return *this;

}

Brain::~Brain(void)
{
	std::cout << "\033[38;5;75m -> Brain destructor\033[0m" << std::endl;
}

const 	std::string *Brain::get_Ideas(void) const
{
	const std::string *pt_ideas = this->_ideas;
	return pt_ideas;
}

void	Brain::set_Ideas(const std::string *new_ideas)
{
	for (int i = 0; i < BRAIN_IDEAS; i++)
			this->_ideas[i] = new_ideas[i];
}

void	Brain::set_Idea(std::string idea, int index)
{
	if (index >= 0 && index < BRAIN_IDEAS)
			this->_ideas[index] = idea;
}
