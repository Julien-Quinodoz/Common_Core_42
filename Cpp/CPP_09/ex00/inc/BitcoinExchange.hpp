/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:52:22 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/14 09:47:31 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_H
# define BITCOINEXCHANGE_CLASS_H

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <map>
# include <ctime>
# include <sstream>
# include <utility>


# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

class BitcoinExchange{
	private:
		std::string _db_path;
		std::map<std::string, float> _db; //conteneur map stock une paire ; string/value en float

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const std::string db_path);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange	& operator =(const BitcoinExchange &src);

		std::string db_Path(void) const;
		float get_Rate(const std::string & date);
		void construct_data_base(void);


	class Cant_Read_Data_File: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};
};

#endif