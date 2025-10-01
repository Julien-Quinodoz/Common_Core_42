/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:51 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/19 10:56:09 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed 		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed		c(42);

	std::cout << 	a 	<< std::endl;
	std::cout <<	b 	<< std::endl;
	std::cout << 	c 	<< std::endl<< std::endl;

	std::cout << BLUE "========= Opérateurs de comparaison =========\n" S << std::endl;

	std::cout << "Teste 1: \n" S;
	if(c > b )
		std::cout << C "-->  c est plus grand que b  \n" S;

	std::cout << "Teste 2: \n" S;
	if(b < c )
		std::cout << C "-->  b est plus petit que c \n" S;

	std::cout << "Teste 3: \n" S;
	if(b == b )
		std::cout << C "-->  b est egale à b \n" S;

	std::cout << "Teste 4: \n" S;
	if(b >= b )
		std::cout << C"-->  b est plus grand ou egale à b \n" S;

	std::cout << "Teste 5: \n";
	if(b != c )
		std::cout << C "-->  b n'est pas egale à c \n" S;

	std::cout << "Teste 6: \n"S;
	if(a != a )
		std::cout << C "-->  Teste false  \n" S;


	std::cout << std::endl << BLUE "========= Opérateurs Arithmétriques =========\n" S << std::endl;

		std::cout << C "b + b \t\t= " S 		<< b + b  			<< std::endl;
		std::cout << C "b + b - 3 - b \t= " S << b + b - 3 - b 	<< std::endl;
		std::cout << C "b + b / b \t= " S 	<< b + b / b 	 	<< std::endl;
		std::cout << C "b * b \t\t= " S 		<< b * b  			<< std::endl<< std::endl;


	std::cout << std::endl << BLUE "========= Opérateurs incré/décrémentation =========\n" S<< std::endl;

	std::cout << 	a 	<< std::endl<< std::endl;
	std::cout << 	++a << C " = 1 en valeur float du binaire _nvf avec 8 bits fractionaire" S << std::endl<< std::endl;	// a._nvf passe de 0 à 1-> a.to_Float() = 1 / 256 = 0.00390625
	std::cout << 	a 	<< std::endl<< std::endl;	// Il vaut toujours 1 donc encore 0.00390625.
	std::cout <<	a++ << std::endl<< std::endl;	// Cela affiche a dabord , puis l'incrémente. Il affiche 0.00390625 (encore 1) Ensuite, a._nvf passe à 2
	std::cout <<	a	<< C " = 2  en valeur float du binaire _nvf avec 8 bits fractionaire" S << std::endl<< std::endl;	//  a  vaut maintenant 2 --> a.to_Float() = 2 / 256 = 0.0078125



	std::cout << std::endl << BLUE "=========  max  ===  min   =========\n" S << std::endl;

	Fixed x(20);
	Fixed z(22);
	const Fixed x1(40);
	const Fixed z1(42);

	std::cout << VT "=== Appels sur objets modifiables ===" S << std::endl;
	std::cout << C "min(x, z)  = " S << Fixed::min(x, z) << std::endl;
	std::cout << C "max(x, z)  = " S << Fixed::max(x, z) << std::endl << std::endl;

	std::cout << VT "=== Appels sur objets constants ===" S << std::endl;
	std::cout << C "min(x1, z1) = " S << Fixed::min(x1, z1) << std::endl;
	std::cout << C "max(x1, z1) = " S << Fixed::max(x1, z1) << std::endl << std::endl;

	std::cout << VT "=== Appels mixtes (const + non-const) ===" S << std::endl;
	std::cout << C "min(x, x1)  = " S << Fixed::min(x, x1) << std::endl;
	std::cout << C "max(z, z1)  = " S << Fixed::max(z, z1) << std::endl << std::endl;

	std::cout << VT "=== Test de modification (uniquement avec version non-const) ===" S << std::endl;
	Fixed::min(x, z) = Fixed(100); // Modifie le plus petit entre x et z

	std::cout << C "Après modification : x = " S << x << C", z = " S << z << std::endl << std::endl;

	std::cout << VT "=== Tentative de modification via référence constante ===" S << std::endl;

	const Fixed &ref = Fixed::min(x1, z1); // ref = Fixed(200); //interdite car ref est const;

	std::cout << C "ref (min(x1, z1)) = " S << ref << std::endl;

	/*Version modifiable :
	Accepte des références non-const, donc les objets passés peuvent être modifiés.
	La référence retournée peut être utilisée pour modifier l'objet retourné :

	Version protégée (const) :
	Accepte des références constantes, donc aucune modification possible sur les arguments.
	Retourne une référence constante, donc le résultat ne peut pas être modifié : */



}
