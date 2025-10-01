/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:53 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 17:26:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_H
# define  ANIMAL_CLASS_H

# include <string>

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
};
#endif
