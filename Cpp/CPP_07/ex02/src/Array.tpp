/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:46:45 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 15:31:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T>

Array<T>::Array(void): _size(0)
{
	this->_array = NULL;
}

template<class T>
Array<T>::Array(unsigned int size): _size(size)
{
	this->_array = new T[this->_size];
}

template<class T>
Array<T>::Array(const Array<T> &src): _size(src._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = src._array[i];
	}
	else
		_array = NULL;
}

template<class T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template<class T>
Array<T>	& Array<T>::operator =(const Array<T> &src)
{
	if (this != &src)
	{
		delete [] _array;
		_size = src._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = src._array[i];
		}
		else
		_array = NULL;
	}
	return *this;
}

template<class T>
T	&Array<T>::operator [](const int index) // lecture , ecriture
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->_size)
		throw Array::out_of_range();
	return this->_array[index];
}

template<class T>
const T	&Array<T>::operator [](const int index) const // lecture seul
{
	if (index < 0 || static_cast<unsigned int>(index) >= this->_size)
		throw Array::out_of_range();
	return this->_array[index];
}

template<class T>
unsigned int	Array<T>::size(void) const
{
	return this->_size;
}

template<class T>
const char* Array<T>::out_of_range::what(void) const throw()
{
	return ( "Array index out of bounds  :(  "  ) ;
}
