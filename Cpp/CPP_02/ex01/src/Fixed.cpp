/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:15:55 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/12 16:48:38 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "\033[38;5;75mConstructor called\033[0m" << std::endl;
	this->_nvf = 0;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "\033[38;5;183mCalled destructor\033[0m" << std::endl;
}

Fixed::Fixed(const int x)
{
	std::cout << "\033[38;5;183mInt constructor called.\033[0m" << std::endl;
	this->_nvf = x << this->_b_frac;  //conversion binaire :  x << 8, c’est comme ajouter 8 zéros en binaire à droite, donc multiplier par 256.
	return;
}

Fixed::Fixed(const float f)
{
	std::cout << "\033[32;5;183mFloat constructor called.\033[0m" << std::endl;
	this->_nvf = round(f * (1 << this->_b_frac));  //conversion binaire de f flot + arrondi pour le int
	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "\033[35;5;183mCopy constructor called\033[0m" << std::endl;
	*this = src;
	return;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "\033[38;5;216mCopy assigement operateur called\033[0m" << std::endl;
	if (this != &src)					//  vérifie que l’objet (src) n’est pas le même que l’objet courant (this)
		this->_nvf = src.get_RawBits(); // on copie la valeur de _nvf de src dans _nvf de l’objet actuel.
	return *this;						// "*" this --> ce qui permet d’utiliser l’opérateur d’affectation en chaîne (par exemple : a = b = c;).
}

int	Fixed::get_RawBits(void) const
{
	return this->_nvf;
}

void	Fixed::set_RawBits(const int raw)
{
	this->_nvf = raw;					// raw est un nombre entier qui représente la valeur binaire brute que tu veux stocker dans _nvf.
}

float Fixed::to_Float(void) const
{
	int value = this->_nvf;						// Récupérer la valeur brute de _nvf (représentée en binaire
	int conversionFactor = 1 << this->_b_frac;   	// Calculer le facteur de conversion (1 << _b_frac) == 256
	float result = (float)value / (float)conversionFactor;  // Convertir la valeur brute en float en divisant par le facteur de conversion avec caste
 	return result;
}

int	Fixed::to_Int(void) const  				//  convertit  la  valeur  à  virgule  fixe  en  une  valeur  entière.
{
	int raw = this->_nvf;					//  récupérer la valeur brute
	int conversionFactor = 1 << this->_b_frac;		//calculer le facteur de conversion
	float floatValue =  (float)raw / conversionFactor;  // effectuer une division flottante pour ne pas perdre les décimales
	int result = roundf(floatValue);		//roundf() arrondit une valeur float à l’entier le plus proche.
	return result;
}

/* surcharge  de  l'opérateur  d'insertion  («) converti Fixed en float afin de l output */
/*  std::cout << "La valeur est : " << A << std::endl;*/
std::ostream	&operator<<(std::ostream &os, Fixed const &f)	// &os = std::cout
{
	os << f.to_Float();				// convertit le Fixed (f) en float grâce à to_Float() et on envoie ex: std:: << 42.42;
	return os;						//On retourne le flux pour permettre l'enchaînement : std::cout << fixed1 << fixed2 << std::endl;
}