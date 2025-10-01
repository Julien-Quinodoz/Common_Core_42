/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:32:06 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/29 11:41:31 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <string>

class ClapTrap
{
	protected:

		std::string		_name;
		unsigned int	_hit_pts;
		unsigned int	_energy_pts;
		unsigned int	_attack_pts;

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap		&operator = (const ClapTrap &src);
		virtual ~ClapTrap(void);

		std::string		get_Name(void) const;
		unsigned int	get_Hit_pts(void) const;
		unsigned int	get_Energy_pts(void) const;
		unsigned int	get_Attack_pts(void) const;

		void			attack(const std::string &target);
		void			take_Damage(unsigned int amount);
		void			be_Repaired(unsigned int amount);

};

#endif
