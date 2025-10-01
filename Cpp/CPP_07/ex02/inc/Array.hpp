/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:02:18 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 15:30:15 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <typename T>

class Array {
private:
	unsigned int		_size;
	T					*_array;

public:
	Array <T>(void);
	~Array<T>(void);
	Array <T>(unsigned int size);
	Array <T>(const Array<T> &src);

	Array<T> & operator =	(const Array<T> &src);
	T		 & operator []	(const int index);			// Version non-const
	const T	 & operator []	(const int index) const;	// Version const


	unsigned int	size(void) const;


class out_of_range : public std::exception {
	public:
		virtual const char *what(void) const throw();
	};
};

# include "../src/Array.tpp"

#endif
