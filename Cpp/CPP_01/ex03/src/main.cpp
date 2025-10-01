/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:24 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 11:00:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	knife = Weapon("\033[38;5;228mkitchen knife\033[0m");
		HumanA	Alpha("Alpha", knife);
		Alpha.attack();
		knife.set_Type("\033[38;5;228mButterfly knife\033[0m");
		Alpha.attack();
	}
	std::cout << std::endl;
	{
		Weapon	knife = Weapon("\033[38;5;228mDagger\033[0m");
		HumanB	Beta("Beta");
		Beta.set_Weapon(knife);
		Beta.attack();
		knife.set_Type("\033[38;5;228mPocket knife\033[0m");
		Beta.attack();
	}
	return 0;
}
