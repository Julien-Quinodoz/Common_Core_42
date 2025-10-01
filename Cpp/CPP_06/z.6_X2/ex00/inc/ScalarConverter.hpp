/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:50:33 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/03 10:44:44 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <exception>


class ScalarConverter
{
	private:
		//Orthodox Canonical Form
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

	public:
		static void convert(const std::string& str);
        static bool isSpecialValue(const std::string& str);
        static void handleSpecialValue(const std::string& str);
        static void printAllTypes(int value);
        static void printAllTypes(float value);
        static void printAllTypes(double value);
        static void printImpossible();
};

#endif
