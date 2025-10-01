/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:54 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 15:52:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	//std::cout << "\033[38;5;75mConstructor called\033[0m" << std::endl;
	this->_nvf = 0;
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "\033[38;5;183mCalled destructor\033[0m" << std::endl;
}

Fixed::Fixed(const int x)
{
	//std::cout << "\033[38;5;183mInt constructor called.\033[0m" << std::endl;
	this->_nvf = x << this->_b_frac;
	return;
}

Fixed::Fixed(const float f)
{
	//std::cout << "\033[32;5;183mFloat constructor called.\033[0m" << std::endl;
	this->_nvf = roundf(f * (1 << this->_b_frac));
	return;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "\033[35;5;183mCopy constructor called\033[0m" << std::endl;
	*this = src;
	return;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	//std::cout << "\033[38;5;216mCopy assigement operateur called\033[0m" << std::endl;
	if (this != &src)
		this->_nvf = src.get_RawBits();
	return *this;
}

int	Fixed::get_RawBits(void) const
{
	return this->_nvf;
}

void	Fixed::set_RawBits(const int raw)
{
	this->_nvf = raw;
	return;
}

float Fixed::to_Float(void) const
{
	int value = this->_nvf;									// Récupérer la valeur brute de _nvf (représentée en binaire
	int conversionFactor = 1 << this->_b_frac;   			// Calculer le facteur de conversion (1 << _b_frac)
	float result = (float)value / (float)conversionFactor;  // Convertir la valeur brute en float en divisant par le facteur de conversion avec caste
 	return result;
}

int	Fixed::to_Int(void) const  								//  convertit  la  valeur  à  virgule  fixe  en  une  valeur  entière.
{
	int raw = this->_nvf;									//  récupérer la valeur brute
	int conversionFactor = 1 << this->_b_frac;				//calculer le facteur de conversion
	float floatValue =  (float)raw / conversionFactor;  	// effectuer une division flottante pour ne pas perdre les décimales
	int result = roundf(floatValue);						//roundf() arrondit une valeur float à l’entier le plus proche.
	return result;
}

/*******   Comparison   *******/
bool	Fixed::operator >	(Fixed const &src) const
{
	return this->_nvf > src._nvf;
}

bool	Fixed::operator <	(Fixed const &src) const
{
	return this->_nvf < src._nvf;
}

bool	Fixed::operator >=	(Fixed const &src) const
{
	return this->_nvf >= src._nvf;
}

bool	Fixed::operator <=	(Fixed const &src) const
{
	return this->_nvf <= src._nvf;
}

bool	Fixed::operator ==	(Fixed const &src) const
{
	return this->_nvf == src._nvf;
}

bool	Fixed::operator !=	(Fixed const &src) const
{
	return this->_nvf != src._nvf;
}

/*******   Arithmetic   *******/
Fixed	Fixed::operator +	(Fixed const &src) const
{
	Fixed	result;

	result.set_RawBits(this->_nvf + src._nvf);
	return result;
}

Fixed	Fixed::operator -	(Fixed const &src) const
{
	Fixed	result;

	result.set_RawBits(this->_nvf - src._nvf);
	return result;
}

Fixed	Fixed::operator *	(Fixed const &src) const		//  multiplies deux nombres _nvf
{
	Fixed	result;

	result.set_RawBits((this->_nvf * src._nvf) >> this->_b_frac); // résult est aussi _nvf (donc divisé une seule fois par 256).
	return result;
}
Fixed	Fixed::operator /	(Fixed const &src) const
{
	Fixed	result;

	result.set_RawBits((this->_nvf << this->_b_frac) / src._nvf);
	return result;
}

/*******   incre decrement   *******/
Fixed	&Fixed::operator 	++()
{
	this->_nvf++;
	return *this;
}

Fixed	Fixed::operator 	++(int)
{
	Fixed tmp(*this);				//retourne un tmp avant incrementation

	this->_nvf++;
	return tmp;
}

Fixed	&Fixed::operator 	--()
{
	this->_nvf--;
	return *this;
}

Fixed	Fixed::operator 	--(int)
{
	Fixed tmp(*this);

	this->_nvf--;
	return tmp;
}

/******* max - min  *******/

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const 	Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const 	Fixed	&Fixed::max(const Fixed &a,const Fixed &b)	//Elle retourne une référence vers le plus grand.
{
	if (a > b)
		return a;
	return b;
}

/*******  ostream overloading  *******/
std::ostream	&operator<<(std::ostream &os, Fixed const &f)
{
	os << f.to_Float();
	return os;
}