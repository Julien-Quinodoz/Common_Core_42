/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:06:55 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 09:56:13 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
	private:

		std::string _name;

	public:

		Zombie(std::string name);
		~Zombie(void);

		void announce( void );


};

Zombie 	*newZombie(std::string name);
void	randomChump(std::string name);

#endif