/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:16:00 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 12:05:58 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CAT_CLASS_H
# define 	CAT_CLASS_H

# include 	<string>
# include 	"Animal.hpp"

class Cat : public Animal
{
	private:

		Brain	*_brain;

	public:
		Cat(void);
		//Cat(std::string type);
		Cat(const Cat &src);
		Cat &operator	=(const Cat &src);
		virtual			~Cat(void);

		virtual void	make_Sound(void) const;

		Brain			*get_Brain(void) const;
};
#endif
