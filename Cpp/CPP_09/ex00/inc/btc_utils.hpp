/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:54:31 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/22 10:15:14 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_H
# define BTC_H

#include <string>

bool check_date_format(std::string str);
bool check_Value(std::string str);
void trim(std::string &str);
float str_to_float(std::string str);
bool try_parse_float(const std::string &str, float &out);

#endif