/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:00:22 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/01 17:59:43 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 12

int main()
{
	std::cout << std::endl << "\e[48;5;223mCreating Animals...\n\033[0m" << std::endl;

	AAnimal	*animals[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i < ARRAY_SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->make_Sound();
	}

	std::cout << "\n\e[48;5;223mDeleting Animals...\033[0m\n" << std::endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
		delete animals[i];

	std::cout << "\n\e[48;5;223mTesting deep copy...\033[0m\n" << std::endl;

	Dog scooby;
	std::cout << std::endl;

	scooby.get_Brain()->set_Idea("I want eat !", 0);

	Dog milou = scooby;
	scooby.get_Brain()->set_Idea("I want a nap !", 0);

	std::cout << "\n\e[48;5;223mOriginal Dog Brain scooby:\033[0m " << scooby.get_Brain()->get_Ideas()[0] << std::endl;
	std::cout << "\n\e[48;5;210mCopied Dog Brain   milou :\033[0m " <<  milou.get_Brain()->get_Ideas()[0] << std::endl;

	std::cout << "******************************" << std::endl;

	// AAnimal teste; /* Teste class abstrait ex02 */

	return 0;
}
