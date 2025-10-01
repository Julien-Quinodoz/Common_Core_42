/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:43:08 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/17 19:37:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer  &copy) {(void)copy;}
Serializer::~Serializer() {}
Serializer & Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr); // transforme l'adresse mémoire contenue dans ptr en un entier uintptr_t,
}

Data *Serializer::deserialize(uintptr_t adresse_en_int)
{
	return reinterpret_cast<Data*>(adresse_en_int);    // inverse -> entier uintptr_t en adreese memoire contenant un ptr
}
