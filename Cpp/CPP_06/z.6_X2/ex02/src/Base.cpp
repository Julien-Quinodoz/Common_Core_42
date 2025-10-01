/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:35:04 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/04 11:59:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include <iostream>
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <stdexcept>

Base::~Base(){}

Base* generate(void)
{
    int randomNum = rand() % 3;

    switch (randomNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            throw "Invalid random number in generate()";
    }        
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    { 
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try 
    {
        dynamic_cast<A&>(p);
        
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        try {
            dynamic_cast<B&>(p);

            std::cout << "B" << std::endl;
            return;
        }
        catch (const std::exception& e)
        {
            try {
                dynamic_cast<C&>(p);

                std::cout << "C" << std::endl;
                return;
            } 
            catch (const std::exception& e)
            {
            
                std::cerr << "Error: cast failed" << std::endl;
            }
        }
    }
}

