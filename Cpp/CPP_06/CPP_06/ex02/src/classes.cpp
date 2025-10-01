/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:50:04 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/18 10:02:50 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

Base::~Base() {}

Base * Base::generate(void)
{
	int random_num = std::rand() % 3;//Génére un INT aléatoire entre 0 et 2
	std::cout << "random num: " J << random_num << E "  -> 0:A / 1:B / 2:C " <<  std::endl;

	if(random_num == 0)				// Retourne une Base * pointant vers un nouvel objet A, B, ou C.
		return (new A());
	else if(random_num == 1)
		return (new B());
	else
		return (new C());
	return nullptr;					// pointeur null si autre;
}

/*
dynamic_cast est un opérateur de cast qui permet de convertir des pointeurs
ou références de manière sécurisée dans une hiérarchie de classes avec polymorphisme:
--> teste de caster en A B ou C <--   pas de catch car prtnull de base
*/
void Base::identify(Base *ptr) // pointeur
{
	A *aPtr = dynamic_cast <A*> (ptr);
	if (aPtr != nullptr){
		std::cout << J "Le pointeur  est une instance de class A" E<< std::endl;
		return;
	}

	B *bPtr = dynamic_cast <B*> (ptr);
	if (bPtr != nullptr){
		std::cout << J "Le pointeur  est une instance de class B" E << std::endl;
		return;
	}

	C *cPtr = dynamic_cast <C*> (ptr);
	if (cPtr != nullptr){
		std::cout << J "Le pointeur  est une instance de class C" E << std::endl;
		return;
	}

	std::cout << "Type inconnu !" << std::endl;
}

void Base::identify(Base & ptr) // teste de caster les referances
{
	try
	{
		A &a = dynamic_cast <A&>(ptr);
		(void)a;
		std::cout << G "La référence est une instance de class A" E << std::endl;
		return ;
	}
	catch(std::bad_cast &e){}
	try
	{
		B &b = dynamic_cast <B&>(ptr);
		(void)b;
		std::cout << G "La référence est une instance de class B" E << std::endl;
		return ;
	}
	catch(std::bad_cast &e) {}
	try
	{
		C &c = dynamic_cast <C&>(ptr);
		(void)c;
		std::cout << G "La référence est une instance de class C" E << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}		//msg prédéfini dans <typeinfo>

	std::cout << R "Type inconnu" E << std::endl;
}
