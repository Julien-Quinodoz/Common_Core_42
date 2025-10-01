/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:15:26 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/30 18:03:27 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_CLASS_H
# define WRONG_CAT_CLASS_H

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		//WrongCat(std::string type);
		WrongCat(const WrongCat &src);
		WrongCat &operator	=(const WrongCat &src);
		virtual		~WrongCat(void);

	void			make_Sound(void) const;
};

#endif
