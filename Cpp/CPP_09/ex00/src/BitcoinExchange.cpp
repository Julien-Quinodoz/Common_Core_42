/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:51:20 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/24 11:36:40 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "btc_utils.hpp"



BitcoinExchange::BitcoinExchange(void) : _db_path("input/data.csv") { }

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string db_path) : _db_path(db_path) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db_path(src._db_path){
	this-> _db = src._db;
}

/* "std::map" gère déjà sa copie; Elle définit un constructeur de copie
		parcourent tous les éléments de  map et copiant chaque paire clé/valeur.
		boucle auto  : vide this->_db et insère chaque élément de src._db */
BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &src) {
	if (this != &src)
	{
		this->_db_path = src._db_path;
		this->_db = src._db;
	}
	return *this;
}


std::string BitcoinExchange::db_Path(void) const{
	return this->_db_path;
}

void BitcoinExchange::construct_data_base() {
	std::ifstream copy_path(this->_db_path);			// Copy le chemin dans copy_path

	if (!copy_path.is_open())
		throw BitcoinExchange::Cant_Read_Data_File(); 	// exception si échec ouverture

		this->_db.clear();								// On vide la map interne avant de recharger les données

	std::string line;

	std::getline(copy_path, line);						// Lecture et "saut" de la première ligne du fichier (l'en-tête CSV) (la line sera écrasée à la prochiane écriture)

	 while (std::getline(copy_path, line))
	{

		std::stringstream copy_line(line);				// Ici, on met la ligne entière dans un stringstream : copy_line

		std::string date, value;

		if (!std::getline(copy_line, date, ',') || !std::getline(copy_line, value, ',')) //teste date et value si faux → on passe à l'IT  suivante
			continue;

		trim(date);								// Trim pour enlever espaces et tabs autour
		trim(value);

		if (!check_date_format(date)) 	continue;			// Vérification du format de la date
		if (!check_Value(value)) 		continue;			// Vérification de la validité de la valeur

		this->_db[date] = str_to_float(value);				// Si tout ok : Conversion de la valeur en float et insertion dans map
	}
}

float BitcoinExchange::get_Rate(const std::string & date)
{
	if (_db.empty())
		return 0;

	std::map<std::string, float>::iterator it = _db.lower_bound(date); // lower_bound = premier élément >= date

	if (it == _db.end()) 				// toutes les dates de _db sont < date → on prend la dernière
	{
		 --it;
		 return it->second;				//it->first accède à la clé  / it->second accède à la valeur
	}

	if (it->first == date)				 // date exacte trouvée
		return it->second;

	if (it == _db.begin())				 // date est avant la première disponible
			return 0;
										// sinon on prend l'élément juste avant
		 --it;

		return it->second;
}


const char * BitcoinExchange::Cant_Read_Data_File::what(void) const throw(){
	return ( R "Error : impossible d'ouvrir file" E );
}
