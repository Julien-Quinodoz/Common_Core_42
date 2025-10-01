/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:57 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 15:29:32 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H
# define BLUE "\033[38;5;75m"
# define S "\033[0m"
# define VT "\033[38;5;177m"
# define C "\033[38;5;220m"

# include <iostream>

class Fixed
{
	private:
		int					_nvf;
		static const int	_b_frac = 8;

	public:
				Fixed(void);
				~Fixed(void);
				Fixed(const int x);
				Fixed(const float f);
				Fixed(Fixed const &src);

		Fixed	&operator=(Fixed const &src);

		int		get_RawBits(void) const;
		void	set_RawBits(const int raw);
		float	to_Float(void) const;
		int		to_Int(void) const;

		/* comparison */
		bool	operator >	(Fixed const &src) const;
		bool	operator <	(Fixed const &src) const;
		bool	operator >=	(Fixed const &src) const;
		bool	operator <=	(Fixed const &src) const;
		bool	operator ==	(Fixed const &src) const;
		bool	operator != (Fixed const &src) const;

		/* arithmetic */
		Fixed	operator +	(Fixed const &src) const;
		Fixed	operator -	(Fixed const &src) const;
		Fixed	operator *	(Fixed const &src) const;
		Fixed	operator /	(Fixed const &src) const;

		/* incre decrement */

		Fixed	&operator 	++();	//prefix
		Fixed	operator 	++(int);//postfix
		Fixed	&operator 	--();	//prefix
		Fixed	operator 	--(int);//postfix

		static 		 Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed		&min(const Fixed &a, const Fixed &b);
		static 		 Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed		&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &i);

#endif