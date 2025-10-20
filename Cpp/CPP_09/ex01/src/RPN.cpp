/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:15:52 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/14 11:58:51 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

	RPN::RPN	() 	{};
	RPN::~RPN	() 	{};

	RPN::RPN(const RPN &src){
		*this = src;
	}

	RPN & RPN::operator = (const RPN &src)	{
		(void) src;
		return *this;
	}

float RPN::result(const std::string expr)
{
	std::list<float> res;

	for (std::string::const_iterator it = expr.begin(); it != expr.end(); ++it)
	{
		if (*it == ' ')
			continue;

		if (isdigit(*it))					//promotion de *it en int et return true si entre 48 et 57 : numéro 0-9
		{
			res.push_back(*it - '0');		// atoi et ajoute à la pile.
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (res.size() < 2)
				throw RPN::Bad_expression();

			float b = res.back(); res.pop_back();	//  récupère le dernier élément et le suprime
			float a = res.back(); res.pop_back();	// 	b pour le dernier / a pour l'avant dernier

			switch (*it) {
				case '+':	res.push_back(a + b); break;
				case '-':	res.push_back(a - b); break;
				case '*':	res.push_back(a * b); break;
				case '/':
					if (b == 0) throw RPN::Division_0();
							res.push_back(a / b); break;
			}
		}
		else
		{
			throw RPN::Bad_expression();
		}
	}

	if (res.size() != 1)						//à la fin, la pile doit contenir exactement UN: le résultat final.
		throw RPN::Incomplete_Evaluation();

	return res.front();
}



const char*	RPN::Bad_expression::what(void) const throw(){
	return ( R "Error: mauvaise expression !  " E );
}

const char*	RPN::Division_0::what(void) const throw(){
	return ( R "Error: division par 0 est interdite" E );
}

const char*	RPN::Incomplete_Evaluation::what(void) const throw(){
	return ( R "Error: éléments restants ! " E );
}