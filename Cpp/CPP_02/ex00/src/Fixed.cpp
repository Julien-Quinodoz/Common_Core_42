/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:15:13 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 12:02:25 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <Fixed.hpp>
# include <iostream>

Fixed::Fixed(void)
{
	std::cout << "\033[38;5;75m--> Constructor called\033[0m" << std::endl;
	this->_nvf = 0;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "\033[38;5;183m--> Called destructor" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "\033[38;5;183m--> Copy constructor called\033[0m" << std::endl;
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

int		Fixed::get_RawBits(void) const
{
	std::cout << "\033[38;5;162m--> get_RawBits function called\033[0m" << std::endl;
	return this ->_nvf;					// renvoie _nvf la ligne binaire
}

void	Fixed::set_RawBits(const int raw)
{
	this->_nvf = raw;					// raw est un nombre entier qui représente la valeur binaire brute que tu veux stocker dans _nvf.
}
