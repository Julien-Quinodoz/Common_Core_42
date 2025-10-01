/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:51 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:39:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
	private:

		std::string _type;

	public:

		Weapon(std::string type);
		~Weapon(void);

		void	set_Type(std::string type);

		const std::string &get_Type() const;
};

#endif