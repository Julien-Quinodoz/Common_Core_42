/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:03:33 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/03 08:43:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src){
	(void)src;
}
ScalarConverter & ScalarConverter::operator = (const ScalarConverter& src){
	(void)src;
	return *this;
}


void ScalarConverter::toChar(double val)
{
	std::cout << J "char: \t" E;

	if (std::isnan(val) || val < 0 || val > 127 || val != static_cast<int>(val)) // isnan = "Not a Number ?
		throw std::invalid_argument(R "🚫 impossible" E);

	char c = static_cast<char>(val);

	if (!std::isprint(c))
		throw std::invalid_argument(G "pas affichable ❕" E);
	else
		std::cout << "'" << c << "'" << std::endl;
}


void ScalarConverter::toFloat(double val)
{
	std::cout << J "float: \t" E ;
	if (std::isnan(val))								//si pas un nombre
		std::cout << "nanf" << std::endl;
	else if (std::isinf(val))							// si pas une valeur infinie + ou -
		std::cout << (val > 0 ? "+inff" : "-inff") << std::endl;
	else {
		std::cout << static_cast<float>(val) << "f" << std::endl;
	}
}

void ScalarConverter::toInt(double val)
{
	std::cout << J "int: \t" E ;
	if (std::isnan(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		throw std::invalid_argument( R "🚫 impossible" E);
	else
		std::cout << static_cast<int>(val) << std::endl;
}

void ScalarConverter::toDouble(double val)
{
	 std::cout << J "double: " E ;
	if (std::isnan(val))
		std::cout << "nan" << std::endl;
	else if (std::isinf(val))
		std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << val << std::endl;
}

bool is_Char(const std::string &value)
{
	return value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]);
}

double ScalarConverter::parseInput(const std::string &value)
{
	if (is_Char(value))
		return static_cast<double>(value[0]); //converti le premier char en double pour uniformiser

	try
	{
		std::size_t pos = 0;
		double result;

		if (value == "+inff" || value == "-inff" || value == "nanf") // Teste : les trois cas spéciaux pour f float (infinity positif/négatif, not-a-number) "chaînes de caractères littérales"
			return std::stof(value);								//convertit directement la chaîne spéciales en float et  sera automatiquement converti (promu) en double
																	// Si value vaut exactement "nanf", "inff", ou "nanf" → alors std::stof(value) est exécuté.

//																	Et donc il retourne un float spécial :

		if (value.back() == 'f')					// récupère le dernier caractère de la chaîne --> si 'f':
		{
			result = std::stof(value, &pos);		//conversion en float
			if (pos != value.length())				// Vérifier si toute la chaîne a été convertie
				throw std::invalid_argument(R " 🚫 invalide" E);
			return result;
		}
		else
		{
			result = std::stod(value, &pos);		// conversion en double
			if (pos != value.length())				// Vérifier si toute la chaîne a été convertie
				throw std::invalid_argument(R " 🚫 invalide" E);
			return result;
		}
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument(R " 🚫 invalide" E);
	}
}

void ScalarConverter::convert(std::string value)
{
	double value_double;

	try
	{
		value_double = parseInput(value);
	}
	catch (const std::exception& e)
	{
		std::cout << R "char: \t 🚫 impossible" << std::endl;
		std::cout << "int: \t 🚫 impossible" << std::endl;
		std::cout << "float: \t 🚫 impossible" << std::endl;
		std::cout << "double:  🚫 impossible" E << std::endl;
		return ;
	}
	try
	{
		toChar(value_double);
	}
	catch (const std::exception& e){std::cout << e.what() << std::endl;}

	try
	{
		toInt(value_double);
	}
	catch (const std::exception& e){std::cout << e.what() << std::endl;}

	try
	{
		toFloat(value_double);
	}
	catch (const std::exception& e){std::cout << e.what() << std::endl;}

	try
	{
		toDouble(value_double);
	}
	catch (const std::exception& e){std::cout << e.what() << std::endl;}
}

