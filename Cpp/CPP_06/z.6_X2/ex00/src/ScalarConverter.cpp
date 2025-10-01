/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:13:13 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/03 10:54:05 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void ScalarConverter::printAllTypes(int value)
{
    if (value >= 32 && value <= 126)
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << value << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printAllTypes(float value)
{
    if (value >=32.0 && value <= 126.0 && value == static_cast<int>(value))
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }

    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl; 
}

void ScalarConverter::printAllTypes(double value)
{
    if (value >= 32.0 && value <= 126.0 && value == static_cast<int>(value))
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }

    if (value >= std::numeric_limits<float>::min() && value <= std::numeric_limits<float>::max())
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
}


bool ScalarConverter::isSpecialValue(const std::string& str)
{
    bool isNaN = (str == "nan" || str == "nanf");
    bool isPosInf = (str == "inf" || str == "inff" || str == "+inf" || str == "+inff");
    bool isNegInf = (str == "-inff" || str == "-inf");

    return (isNaN || isPosInf || isNegInf);
}

void ScalarConverter::handleSpecialValue(const std::string& str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
        std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
    }
    else if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
        std::cout << "float: " << std::numeric_limits<float>::infinity() << std::endl;
        std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: " << -std::numeric_limits<float>::infinity() << std::endl;
        std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
    }

}

void ScalarConverter::printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    //pattern check
    if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
    {
        char c = str[1];
        std::cout << "char : '" << c << "'" << std::endl;
        std::cout << "int : " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << std::endl; 

        return ;
    }
    else if (str.size() == 1 && std::isprint(str[0]))
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;

        return ;
    }
    else if (isSpecialValue(str))
    {
        handleSpecialValue(str);
        return ;
    }
    else
    {
        char* endptr;

        if (str.length() > 1 && str[str.length() - 1] == 'f' && str.find('.') != std::string::npos)
        {
            std::string floatStr = str.substr(0, str.length() - 1);
            double temp = strtod(floatStr.c_str(), &endptr);

            if (*endptr == '\0' && endptr != floatStr.c_str())
            {
                float f = static_cast<float>(temp);
                printAllTypes(f);
            }
            else
                printImpossible();
        }
        else if (str.find('.') != std::string::npos)
        {
                double d = strtod(str.c_str(), &endptr);

                if (*endptr == '\0' && endptr != str.c_str())
                {
                    printAllTypes(d);
                }
                else 
                    printImpossible();
        }
        else
        {
            long temp = strtol(str.c_str(), &endptr, 10);

            if (*endptr == '\0' && endptr != str.c_str())
            {
                if (temp >= std::numeric_limits<int>::min() && temp <= std::numeric_limits<int>::max())
                {
                    int i = static_cast<int>(temp);
                    printAllTypes(i);            
                }
                else
                    printImpossible();
            }
            else
                printImpossible();
        }
    }
}
