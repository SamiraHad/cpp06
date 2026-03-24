/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:02 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/24 13:20:11 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &literal) // je verifie si literal est 'a' format classique ou un seul char non chiffre a, @, ...
{
    if((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') //'a'
     || (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))) //le caractère n’est pas un chiffre
        return true;
    return false;
}

static bool isPseudoliteral(const std::string& literal) //je verifie si not a numbre || infini
{
    if(literal == "nan" || literal == "-inf" || literal == "+inf" ||
        literal == "nanf" || literal == "-inff" || literal == "+inff")
            return true;
    return false;
}

static bool isInt(const std::string &literal)
{
    if(isPseudoliteral(literal) || literal.empty())
        return false;
        
    size_t i = 0;
    
    if(literal[0] == '+' || literal[0] == '-') // on gere les signes - et +
        i++;
    if((literal[0] == '+' || literal[0] == '-') && literal.size() == 1)  // on evite les cas invalides "-" et "+" : est-ce qu’il reste au moins un chiffre après le signe
        return false; 
    for(; i < literal.size(); i++) //ici on gere tous les chiffres
    {
        if(!std::isdigit(static_cast<unsigned char>(literal[i]))) //
            return false;
    }
    return true;
}
static bool isFloat(const std::string &literal)
{
    if(isPseudoliteral(literal) || literal.empty())
        return false;
    size_t i = 0;
    bool hasDot = false;
    
    if(literal[0] == '+' || literal[0] == '-') // on gere les signes - et +
        i++;
    if((literal[0] == '+' || literal[0] == '-') && literal.size() == 1)  // on evite les cas invalides "-" et "+" : est-ce qu’il reste au moins un chiffre après le signe
        return false;
    if(literal[literal.size() - 1] != 'f')
        return false;
    for(; i < literal.size() - 1; i++) //ici on gere tous les chiffres
        {
            if(literal[i] == '.')
            {
                if(hasDot)
                    return false;
                hasDot = true;
                continue;
            }
            if(!std::isdigit(static_cast<unsigned char>(literal[i]))) //
                return false;
        }
    if(!hasDot)
        return false;
    return true;
}

static bool isDouble(const std::string &literal)
{
    if(isPseudoliteral(literal) || literal.empty())
        return false;
    size_t i = 0;
    bool hasDot = false;
    
    if(literal[0] == '+' || literal[0] == '-') // on gere les signes - et +
        i++;
    if((literal[0] == '+' || literal[0] == '-') && literal.size() == 1)  // on evite les cas invalides "-" et "+" : est-ce qu’il reste au moins un chiffre après le signe
        return false;
    if(literal[literal.size() - 1] == 'f')
        return false;
    for(; i < literal.size(); i++) //ici on gere tous les chiffres
        {
            if(literal[i] == '.')
            {
                if(hasDot)
                    return false;
                hasDot = true;
                continue;
            }
            if(!std::isdigit(static_cast<unsigned char>(literal[i]))) //
                return false;
        }
    if(!hasDot)
        return false;
    return true;
} 

static void printChar(double value)
{
    if(value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
        std::cout << " char: impossible" << std::endl;
    else if(!std::isprint(static_cast<char>(value)))
        std::cout << " char: Non displayable" << std::endl;
    else
        std::cout << " char: '" << static_cast<char>(value) << "'" << std::endl;    
}

static void printInt(double value)
{
    if(std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible." << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}


static void printFloat(double value)
{
    if( std::isnan(value))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }

    if(std::isinf(value))
    {
        if(value < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: +inff" << std::endl;
        return;
    }
    float nbr =  static_cast<float>(value); 
    if(nbr == static_cast<int>(nbr))
        std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;  
    else
        std::cout << "float: " << nbr << "f" << std::endl;
}
    
static void printDouble(double value)
{
    if( std::isnan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }

    if(std::isinf(value))
    {
        if(value < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
        return;
    }
    
    if(value == static_cast<int>(value))
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;  
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    double value;
    if(isChar(literal))
    {
        char c;
        if(literal.size() == 3)
            c = literal[1];
        else
            c = literal[0];
        value = static_cast<double>(c);
            
    }

    else if(isPseudoliteral(literal))
       value = std::strtod(literal.c_str(),NULL); 
       
    else if(isInt(literal)) 
        value = std::strtod(literal.c_str(), NULL);
        
    else if(isFloat(literal)) 
        value = std::strtod(literal.c_str(), NULL);
        
    else if(isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}