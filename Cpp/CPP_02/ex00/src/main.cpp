/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:50:24 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/08 16:08:12 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int main(void)
{									std::cout << std::endl  << C"Fixed a :"S << std::endl;
	Fixed a;
									std::cout << std::endl  << C"Fixed b(a):"S << std::endl;
	Fixed b(a);						//Copy constructor
									std::cout << std::endl  << C"Const c:"S << std::endl;
	Fixed c;
									std::cout << std::endl << C"c = b:"S << std::endl;
	c = b;							//Copy assigement operateur
									//pas de retour 0 car get_R est appeler pour copie _nvf dans c
									std::cout << std::endl << C"get_R --> a :"S << std::endl;
	std::cout << a.get_RawBits();
									std::cout << std::endl << C"get_R --> b :"S << std::endl;
	std::cout << b.get_RawBits();
									std::cout << std::endl << C"get_R --> c :"S << std::endl;
	std::cout << c.get_RawBits();
									std::cout << std::endl;
	return 0;
}
