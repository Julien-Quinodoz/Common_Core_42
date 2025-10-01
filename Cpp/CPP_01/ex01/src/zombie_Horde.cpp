/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_Horde.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:32:31 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/05 10:18:49 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombie_Horde(int nb, std::string name)
{
	int i;

	i = 0;
	Zombie *horde = new Zombie[nb];

	while(i < nb)
	{
		horde[i].set_name(name);
		i++;
	}
	return (horde);
}
