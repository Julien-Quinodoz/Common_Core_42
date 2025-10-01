/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:12:55 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 16:03:26 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# define B "\033[38;5;75m"
# define S "\033[0m"
# define VT "\033[38;5;177m"
# define C "\033[38;5;220m"

# include <iostream>

class Fixed
{
	private:
		int					_nvf;				//nombre  à virgule fixe : stocke une représentation binaire d’un nombre réel, mais encodée dans un int.
		static const int	_b_frac = 8;		//nombre de bits fractionnaires :  indique combien de bits sont réservés à la partie fractionnaire.

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int x);						//constructeru de int
		Fixed(const float f);					//constructeru de float
		Fixed(Fixed const &src);				//constructeur de copie

		Fixed	&operator=(Fixed const &src); 	//surchage d'opérateur de copie

		int		get_RawBits(void) const;		//renvoie  la  valeur brute _nvf  :  nombre à  virgule  fixe.
		void	set_RawBits(const int raw);		// définit  la  valeur brute _nvf du  nombre  à  virgule  fixe.
		float	to_Float(void) const;			//  convertit  la  valeur  à  virgule  fixe  en  une  valeur  à  virgule  flottante.
		int		to_Int(void) const;				//  convertit  la  valeur  à  virgule  fixe  en  une  valeur  entière.
};

std::ostream	&operator<<(std::ostream &os, Fixed const &f);

#endif

/*  Un nombre à virgule fixe est une manière de représenter des nombres réels (avec des décimales)
	en utilisant un  entiers. Au lieu de stocker directement la partie décimale d'un nombre
   (comme le ferait un nombre flottant), on utilise des bits réservés (_b_frac = 8) pour la
		 partie fractionnaire du nombre */