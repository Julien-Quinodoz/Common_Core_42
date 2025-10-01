/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:19:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 18:49:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAIN_A_H
# define HUMAIN_A_H

# include "Weapon.hpp"

class HumanA
{
	private:

		std::string _name;
		Weapon		&_weapon;


	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void);
};

#endif