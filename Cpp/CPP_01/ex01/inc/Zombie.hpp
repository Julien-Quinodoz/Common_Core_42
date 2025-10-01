/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:14:51 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/06 13:42:48 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>
# include <cstdlib>

class Zombie
{
	private :

		std::string	_name;

	public :

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	set_name(std::string name);

} ;

Zombie *zombie_Horde(int nb, std::string name);

#endif