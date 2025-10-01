/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:32 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 09:51:24 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
	private:
		std::string _nom;
		std::string _prenom;
		std::string _surnom;
		std::string _telephone;
		std::string _code_secret;

	public:

		Contact();

		~Contact(void);

		void set_infos(std::string nom, std::string prenom,
			std::string surnom, std::string telephone, std::string code_secret);

	void	show_info(void);

	std::string get_nom(long unsigned int size = -1);
	std::string get_prenom(long unsigned int size = -1);
	std::string get_surnom(long unsigned int size = -1);
	std::string get_telephone(void);
	std::string get_code_secret(void);
};

#endif
