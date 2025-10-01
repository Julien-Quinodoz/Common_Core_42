/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:50:02 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 16:07:30 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASSE_H
# define FIXED_CLASSE_H
# define B "\033[38;5;75m"
# define S "\033[0m"
# define VT "\033[38;5;177m"
# define C "\033[38;5;220m"

class Fixed
{
	private:
		int					_nvf;				//nombre  à virgule fixe : stocke une représentation binaire d’un nombre réel, mais encodée dans un int.
		static const int	_b_frac = 8;		//nombre de bits fractionnaires :  indique combien de bits sont réservés à la partie fractionnaire.

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &src); //surchage d'opérateur de copie
		~Fixed(void);

		int		get_RawBits(void) const;	  //renvoie  la  valeur brute _nvf  :  la  nombre  à  virgule  fixe.
		void	set_RawBits(const int raw);   // définit _nvf  : la  valeur brute  du  nombre  à  virgule  fixe.
};
#endif