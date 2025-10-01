/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:14:21 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/02 15:22:35 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <value_to_convert>" << std::endl;
        std::cout << "Examples:" <<std::endl;
        std::cout << " " << argv[0] << " 'c'" << std::endl;
        std::cout << " " << argv[0] << " 42" << std::endl;
        std::cout << " " << argv[0] << " 42.5f" << std::endl;
        std::cout << " " << argv[0] << " 42.5" << std::endl;
        std::cout << " " << argv[0] << " nan" << std::endl;
        std::cout << " " << argv[0] << " inf" << std::endl;
        return 1;
    }
    
    std::string input = argv[1];

    std::cout << "Converting: \"" << input << "\"" << std::endl;
    std::cout << "------------------------------------" << std::endl;
   
    try 
    {
        ScalarConverter::convert(input);
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Error :" << e.what() << std::endl;
        return 1;
    }
    return 0;
}

