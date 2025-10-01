/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:36:36 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 14:45:28 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "whatever.hpp"

int main(void)
{
	std::cout << G "\n************************\n" E << std::endl;

	int a = 109;
	int b = 901;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << B "\n====== SWAP INT ======\n" E << std::endl;
	::swap( a, b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout  << "MAX = " << ::max( a,  b )   <<  std::endl;
	std::cout  << "MIN = " << ::min( a,  b )   <<  std::endl;

	std::cout << G "\n************************\n" E << std::endl;



	float g = -42.42;
	float h = 99.99;


	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;

	std::cout << B "\n====== SWAP FLOAT ======\n" E << std::endl;
	::swap( g, h);
	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;

	std::cout  << "MAX = " << ::max( g,  h )   <<  std::endl;
	std::cout  << "MIN = " << ::min( g,  h )   <<  std::endl;

	std::cout << G "\n************************\n" E << std::endl;



	std::string x = "a un deux trois";
	std::string z = "z trois deux un";

	std::cout << "x = " << x << std::endl;
	std::cout << "z = " << z << std::endl;

	std::cout << B "\n====== swap string ======\n" E << std::endl;
	::swap( x, z);
	std::cout << "x = " << x << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout  << "MAX = " << ::max( x,  z )   <<  std::endl;
	std::cout  << "MIN = " << ::min( x,  z )   <<  std::endl;

	std::cout << G "\n************************\n" E << std::endl;

	size_t S = 404;
	size_t T = 404;

	std::cout << "S = " << S << std::endl;
	std::cout << "T = " << T << std::endl;

	std::cout << B "\n====== MAX MIN ======\n" E << std::endl;

	std::cout  << "MAX = " << ::max( S,  T )   <<  std::endl;
	std::cout  << "MIN = " << ::min( S,  T )   <<  std::endl;

	std::cout << G "\n************************\n" E << std::endl;


	return 0;
}
