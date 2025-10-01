/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:02:43 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/17 15:05:00 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		virtual ~ScalarConverter(void);
		ScalarConverter & operator = (const ScalarConverter &src);

	public:
		static void 	convert(std::string value);
		static void 	toChar(double value);
		static void 	toInt(double value);
		static void 	toFloat(double value);
		static void 	toDouble(double value);
		static double 	parseInput(std::string const &value);
};

#endif