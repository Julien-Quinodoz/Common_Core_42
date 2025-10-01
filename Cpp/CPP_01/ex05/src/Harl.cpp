/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:53:42 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 13:56:18 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"


Harl::Harl(void)
{}

Harl::~Harl(void)
{}

void	Harl::complain(std::string level)
{
	int i = 0;

	void (Harl::*function[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string array_level[4] = {"debug", "info" , "warning" ,"error"};

	while (i < 4)
	{
		if (level == array_level[i])
		{
			(this->*function[i])();
			break ;
		}
		i++;
	}
}

void 	Harl::_debug(void)
{
	std::cout << "	😐 \033[38;5;159m — Harl fronce légèrement les sourcils. Rien de grave... pour l’instant.\033[0m" << std::endl;
}

void 	Harl::_info(void)
{
	std::cout << "		😠 \033[38;5;75m — Harl commence à s’échauffer. Quelque chose cloche, et il n’aime vraiment pas ça.\033[0m" << std::endl;
}

void 	Harl::_warning(void)
{
	std::cout << "	⚠️  \033[38;5;208m — Harl serre les poings. Trois bugs de plus et il balance le clavier par la fenêtre.\033[0m" << std::endl;
}

void 	Harl::_error(void)
{
	std::cout << "	💥 \033[38;5;196m — Harl est FURAX. Le terminal va brûler, l'ecran va voler, et toi… toi tu ferais mieux de courir.\033[0m" << std::endl;
}
