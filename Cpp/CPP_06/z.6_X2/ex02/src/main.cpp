/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:48:45 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/04 11:56:25 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    
    for (int i = 1; i <= 5; i++)
    {
        std::cout << "Test " << i << ":" << std::endl;
        try 
        {
                Base* obj = generate();
                std::cout << "Testing identify(Base* p) - pointer object: " << std::endl;
                identify(obj);
                
                std::cout << std::endl;

                std::cout << "Testing identify(Base& p) - reference object: " << std::endl;
                identify(*obj);

                std::cout << std::endl;

                delete obj;
        } 
        catch (const std::exception& e)
        { 
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
