/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:29:42 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/03 15:16:39 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/DataStructure.hpp"
#include <iostream>

int main()
{
    Data testData;

    testData.num = 42;
    testData.doub = 4.5;
    testData.str = "Hello World";
    testData.isTested = true;
    testData.list.push_back(2);
    testData.list.push_back(55);
    testData.list.push_back(32);
    testData.list.push_back(56);

    Data* originalPtr = &testData;

    std::cout << "Original pointer: " << originalPtr << std::endl;

    uintptr_t serialized = Serializer::serialize(originalPtr);

    std::cout << "Serialized value: " << serialized << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(serialized);

    std::cout << "Deserialized value: " << deserializedPtr << std::endl;

    std::cout << "Pointers match: " << (originalPtr == deserializedPtr ? "Yes" : "No") << std::endl;
    std::cout << "Data integrity check: " << std::endl;
    std::cout << "int: " << testData.num << std::endl;
    std::cout << "double: " << testData.doub << std::endl;
    std::cout << "string: " << testData.str << std::endl;
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = testData.list.begin(); it != testData.list.end(); ++it)
    { 
        if (it != testData.list.begin()) 
        {
            std::cout << ", "; 
        } 
        std::cout << *it;
    }
    std::cout << std::endl;
    std::cout << "bool: " << testData.isTested << std::endl;

    std::cout << "Data integrity check through original pointer: " << std::endl;
    std::cout << "Original pointer num: " << originalPtr->num << std::endl;

    std::cout << "Data itnegrity check through deserialized pointer: " << std::endl;
    std::cout << "Deserialized pointer num: " << deserializedPtr->num << std::endl;

    return 0;
}
