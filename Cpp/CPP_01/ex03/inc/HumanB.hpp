/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:19:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:39:35 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAIN_B_H
# define HUMAIN_B_H

# include "Weapon.hpp"

class HumanB
{
	private:

		std::string _name;
		Weapon		*_weapon;

	public:

		HumanB(std::string name);
		~HumanB(void);

		void	attack(void);
		void	set_Weapon(Weapon &weapon);
};

#endif
