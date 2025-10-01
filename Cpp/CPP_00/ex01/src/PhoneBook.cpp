/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:38 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 09:53:17 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define MAX_CONTACTS 8

PhoneBook::PhoneBook(void)
{
	this->_size = 0;
	this->_contacts = new Contact[MAX_CONTACTS];
	return ;
}

PhoneBook::~PhoneBook(void)
{
        delete[] this->_contacts;
}

void	PhoneBook::add_contact()
{
	std::string Nom;
	std::string Prenom;
	std::string Surnom;
	std::string Telephone;
	std::string Code_secret;

	getinput(Nom, "\tNom\t\t--> : ");
	getinput(Prenom, "\tPrenom\t\t--> : ");
	getinput(Surnom, "\tSurnom\t\t--> : ");
	getinput(Telephone, "\tTelephone\t--> : ");
	getinput(Code_secret, "\tCode secret\t--> : ");

	if (this->_size >= MAX_CONTACTS)
	{
		this->_size--;
		int i = 0;
		while (i < this->_size)
		{
			this->_contacts[i].set_infos(
				this->_contacts[i + 1].get_nom(),
				this->_contacts[i + 1].get_prenom(),
				this->_contacts[i + 1].get_surnom(),
				this->_contacts[i + 1].get_telephone(),
				this->_contacts[i + 1].get_code_secret()
															);
			i++;
		}
	}
this->_contacts[this->_size].set_infos(Nom, Prenom, Surnom, Telephone, Code_secret);
if (this->_size < MAX_CONTACTS)
		this->_size++;
}

void	PhoneBook::list_contacts(void)
{
	int i;

	i = 0;
	std::cout << "\t\033[1;34m===\e[0mINDEX\033[1;34m========\e[0mNOM\033[1;34m======\e[0mPRENOM\033[1;34m====\e[0mSURNOM\033[1;34m====\e[0m" << std::endl;
	while (i < this->_size)
	{
		std::cout << "\t|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << this->_contacts[i].get_nom(10);
		std::cout << "|" << std::setw(10) << this->_contacts[i].get_prenom(10);
		std::cout << "|" << std::setw(10) << this->_contacts[i].get_surnom(10);
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "\t\033[1;34m=============================================\e[0m" << std::endl;
}

void	PhoneBook::display_contact(int index)
{
	if(index < this->_size && index >=0)
		this->_contacts[index].show_info();
	else
		std::cout << "\tL'index doit etre compris entre 0 et " << this->_size - 1 << std::endl;
}
