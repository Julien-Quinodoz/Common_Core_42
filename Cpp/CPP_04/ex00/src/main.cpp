/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:04:34 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 10:30:56 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*ani = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << ani->get_Type() << ": " << std::endl;
	ani->make_Sound();
	std::cout << dog->get_Type() << ": " << std::endl;
	dog->make_Sound();
	std::cout << cat->get_Type() << ": " << std::endl;
	cat->make_Sound();

	delete ani;
	delete dog;
	delete cat;

	std::cout << std::endl;

	Animal	lamina = Animal();
	std::cout << lamina.get_Type() << ": " << std::endl;
	lamina.make_Sound();
	lamina = Cat();
	std::cout << lamina.get_Type() << ": "<< std::endl;
	lamina.make_Sound();

	std::cout << std::endl;

	const WrongAnimal*	w_ani = new WrongAnimal();
	const WrongAnimal*	w_cat = new WrongCat();

	std::cout << w_ani->get_Type() << ": "<< std::endl;
	w_ani->make_Sound();
	std::cout << w_cat->get_Type() << ": "<< std::endl;
	w_cat->make_Sound();

	delete w_ani;
	delete w_cat;

	std::cout << std::endl;
	return 0;
}
