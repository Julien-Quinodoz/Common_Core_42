/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:40 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 09:53:02 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASSE_H
# define  PHONEBOOK_CLASSE_H

#include "PhoneBook-app.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	*_contacts;
		int 	_size;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		get_size();
		void	add_contact();
		void	display_contact(int index);
		void	list_contacts();
};

#endif
