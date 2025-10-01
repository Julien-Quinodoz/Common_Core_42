/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:15:58 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/12 16:51:39 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>
// # include <iomanip>		// std::setprecision(8) force l'arondit a 8 chiifres


int	main(void)
{
	// std::cout << std::fixed << std::setprecision(8);

	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);				// f = flot et non un double

										std::cout << std::endl;
	Fixed const	d(b);

										std::cout << std::endl;
	a = Fixed(1234.4321f);				// créer un Fixed float tmp , copie dans a et le détruit; gerer automatiquement par le compilateur

										std::cout << std::endl;


	std::cout << C"a is --> "S << a << std::endl;  	//surcharge d'0perateur << pour afficher un float a partir d'un objet Fixed
	std::cout << C"b is --> "S << b << std::endl;
	std::cout << C"c is --> "S << c << std::endl;		//retour différent car float est arrondit lors de la convertion , puis le result est diviser
	std::cout << C"d is --> "S << d << std::endl << std::endl;
	std::cout << C"a is --> "S << a.to_Int() << B"\t as integer"S	<< std::endl;	//roundf() arrondit une valeur float à l’entier le plus proche.
	std::cout << C"b is --> "S << b.to_Int() << B"\t as integer"S << std::endl;
	std::cout << C"c is --> "S << c.to_Int() << B"\t as integer"S << std::endl;
	std::cout << C"d is --> "S << d.to_Int() << B"\t as integer"S << std::endl;

										std::cout << std::endl;

	return 0;
}

//dif entre a - c --> std::cout utilise une précision limitée (souvent 6 chiffres significatifs),
