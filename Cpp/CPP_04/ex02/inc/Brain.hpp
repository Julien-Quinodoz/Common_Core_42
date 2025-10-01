/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:10:06 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 11:45:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	BRAIN_H
# define	BRAIN_H

# define	BRAIN_IDEAS 100

# include <string>

class Brain
{
	private:
		std::string _ideas[BRAIN_IDEAS];
	public:
		Brain(void);
		Brain(const Brain &src);
		Brain &operator =(const Brain &src);
		~Brain(void);

		const std::string *get_Ideas(void) const;
		void	set_Ideas(const std::string *new_ideas);
		void	set_Idea(std::string idea, int index);
};

#endif