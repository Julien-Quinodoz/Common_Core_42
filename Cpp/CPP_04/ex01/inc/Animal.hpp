/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:53 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 17:32:08 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	ANIMAL_CLASS_H
# define  	ANIMAL_CLASS_H

# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &src);
		Animal 	&operator =(const Animal &src);
		virtual	~Animal(void);

		std::string		get_Type(void) const;
		virtual void	make_Sound(void) const;

		virtual Brain	*get_Brain(void) const;
};
#endif
