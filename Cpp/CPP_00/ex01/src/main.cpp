/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:57:35 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/01 11:00:07 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook-app.hpp"

void	getinput(std::string &str, std::string txt)
{
	str.clear();
	while(str.empty())
	{
		std::cout << txt;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
	}
}

bool ft_str_isnum(std::string str)
{
	size_t i;

	i = 0;
	while (i < str.length())
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return false;
		i++;
	}
	return true;
}

int	main(void)
{
	PhoneBook	phonebook;
	bool		run;

	run = true;
	std::cout << "\033[1;34m==========================================\e[0m" << std::endl;
	std::cout << "Bienvenue dans ton annuaire téléphonique!" << std::endl;
	std::cout << "\033[1;34m===========================================\e[0m" << std::endl;
	std::cout <<"Choisi \033[38;5;177mADD\e[0m pour ajouter un contact, \033[38;5;177mSEARCH\e[0m pour rechercher ou \033[38;5;177mEXIT\e[0m pour sortir." << std::endl;
	while(run)
	{
		std::string str;
		getinput(str, "$> ");
		if (str.compare("ADD") == 0)
			phonebook.add_contact();
		else if (str.compare("EXIT") == 0)
			run = false;
		else if (str.compare("SEARCH") == 0)
		{
			std::string index;
			phonebook.list_contacts();
			getinput(index,"\tChoisi l'index pour afficher: " );
			std::cout << std::endl;
			if(ft_str_isnum(index))
				phonebook.display_contact(atoi(index.c_str()));
			else
				std::cout << "Entrer un numero SVP ! :( " << std::endl;
		}
		else if (str.length() > 0)
			std::cout << "Error, l'annuaire accepte seulement \033[38;5;177mADD\e[0m, \033[38;5;177mSEARCH\e[0m ou \033[38;5;177mEXIT\e[0m !" << std::endl;
	}
	return (0);
}
