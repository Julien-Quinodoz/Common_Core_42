/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:40 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/24 10:52:49 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BitcoinExchange.hpp"
#include "btc_utils.hpp"

/*Le programme lit un fichier d'entrée contenant des lignes au format
« AAAA-MM-JJ | valeur ».	Il valide le format de date, s'assure que la valeur
est un nombre positif inférieur ou égal à 1 000 et affiche le résultat converti
en utilisant le taux de la date précédente la plus proche, tel que spécifié dans data.csv.
Les lignes non valides sont signalées par des messages d'erreur clairs. */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc > 2)
			std::cerr << R "Error: trop d'arguments " E << std::endl;
		else
			std::cerr << R "Error: ./btc <files> " E << std::endl;
		return (1);
	}

	BitcoinExchange btc = BitcoinExchange("input/data.csv");
	try
	{
		btc.construct_data_base();
	}
	catch (BitcoinExchange::Cant_Read_Data_File &e)
	{
		std::cerr << e.what() << " (" << btc.db_Path() << ")"   << std::endl;
		return (1);
	}


	// Open file
	std::string line;
	std::ifstream inputfile(argv[1]);

	if (!inputfile.is_open())
	{
		std::cerr << R "Error: impossible d'ouvrir : (" << argv[1] << ")" E << std::endl;
		return (1);
	}

	// Read line by line
	int ctr = -1;
	while (getline(inputfile,line))
	{
		ctr++;
		if (ctr == 0)
			continue;

		bool ignore = false;

		// ignorer lignes vides ou commentaires
		std::string original = line;
		trim(line);
		if (line.empty() || (!line.empty() && line[0] == '#'))
			continue;

		// Valider le séparateur ' | ' et découper proprement
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << R "Error: bad input" J " => " E << original << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipePos);
		std::string value = line.substr(pipePos + 1);

		// trim des deux côtés
		trim(date);
		trim(value);

		if (date.empty() || value.empty())
		{
			std::cerr << R "Error: bad input" J " => " E << original << std::endl;
			continue;
		}

		// Check date format
		if (!check_date_format(date) && !ignore)
		{
			std::cerr << R "Error: bad input" J " => " E << original << std::endl;
			ignore = true;
		}
		// Parse and validate value
		if (!ignore)
		{
			float tmp;
			if (!try_parse_float(value, tmp))
			{
				std::cerr << R "Error: bad input" J " => " E << original << std::endl;
				ignore = true;
			}
			else if (tmp <= 0)
			{
				std::cerr << R "Error: not a " G "positive" R " number." E << std::endl;
				ignore = true;
			}
			else if (tmp > 1000)
			{
				std::cerr << R "Error: " G "too large" R " a number." E << std::endl;
				ignore = true;
			}
		}

		if (!ignore) {
			float result = str_to_float(value) * btc.get_Rate(date);
			std::cout << std::fixed << std::setprecision(2)
					  << date << J " => " E << value << J " \t= " G << result << E "" << std::endl;
		}

	}
	inputfile.close();
}

