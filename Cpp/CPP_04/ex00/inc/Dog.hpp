/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:16 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 17:32:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
		//Dog(std::string type);
		Dog(const Dog &src);
		Dog &operator	=(const Dog &src);
		virtual		~Dog(void);

		virtual void	make_Sound(void) const;
};
#endif
