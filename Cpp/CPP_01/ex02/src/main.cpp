/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:03 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/14 16:24:09 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		  brain		= "\033[4;32mHI THIS IS BRAIN\e[0m";
	std::string		* brain_PTR	= &brain;
	std::string		& brain_REF	= brain;

	std::cout << "(" << &brain 		<< ") brain value :\t\t\t" 				<< brain << std::endl;
	std::cout << "(" << brain_PTR 	<< ") Value pointed by brain_PTR :\t" 	<< *brain_PTR << std::endl;
	std::cout << "(" << &brain_REF 	<< ") Value pointed by brain_REF :\t"	<< brain_REF << std::endl;

	return 0;
}
