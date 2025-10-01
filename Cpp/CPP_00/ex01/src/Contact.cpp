/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:30 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 09:53:12 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

Contact::Contact()
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::set_infos(std::string nom, std::string prenom,
	std::string surnom, std::string telephone, std::string code_secret)
{
	this->_nom				= nom;
	this->_prenom 			= prenom;
	this-> _surnom 			= surnom;
	this-> _telephone 		= telephone;
	this-> _code_secret 	= code_secret;
}

void	Contact::show_info(void)
{
	std::cout << "\tnom:\t\t" << this->_nom << std::endl;
	std::cout << "\tprenom:\t\t" << this->_prenom << std::endl;
	std::cout << "\tsurnom:\t\t" << this->_surnom << std::endl;
	std::cout << "\ttelephone:\t" << this->_telephone << std::endl;
	std::cout << "\tcode secret:\t" << this->_code_secret << std::endl;
}

std::string Contact::get_nom(long unsigned int size)
{
	if (size > 0 && this->_nom.length() > size)
	{
		std::string nom;
		nom = this->_nom.substr(0, size - 1);
		nom.push_back('.');
		return nom;
	}
	return this->_nom;
}

std::string Contact::get_prenom(long unsigned int size)
{
	if (size > 0 && this->_prenom.length() > size)
	{
		std::string prenom;
		prenom = this->_prenom.substr(0, size - 1);
		prenom.push_back('.');
		return prenom;
	}
	return this->_prenom;
}

std::string Contact::get_surnom(long unsigned int size)
{
	if (size > 0 && this->_surnom.length() > size)
	{
		std::string surnom;
		surnom = this->_surnom.substr(0, size - 1);
		surnom.push_back('.');
		return surnom;
	}
	return this->_surnom;
}

std::string Contact::get_telephone(void)
{
	return this->_telephone;
}

std::string	Contact::get_code_secret(void)
{
	return this->_code_secret;
}