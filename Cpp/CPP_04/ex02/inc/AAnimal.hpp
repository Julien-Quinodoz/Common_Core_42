/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:53 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 17:48:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	AANIMAL_CLASS_H
# define  	AANIMAL_CLASS_H

# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		AAnimal 	&operator =(const AAnimal &src);
		virtual	~AAnimal(void);

		std::string		get_Type(void) const;
		virtual void	make_Sound(void) const;

		virtual Brain	*get_Brain(void) const = 0;
		/*le = 0 rend toute la class abstraite, cela veux que je ne peux
			pas declarer un abojet AAnimal */
};

#endif
