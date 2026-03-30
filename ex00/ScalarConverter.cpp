/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:02 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/29 18:08:00 by hsamira          ###   ########.fr       */
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

static void printChar(char value)
{
    if(!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << value << "'" << std::endl;    
}

static void printInt(int value)
{
    std::cout << "int: " << value << std::endl;
}

static void printFloat(float value)
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
    if(value == static_cast<int>(value))
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;  
    else
        std::cout << "float: " << value << "f" << std::endl;
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
    if(isChar(literal))
    {
        char c;
        if(literal.size() == 3)
            c = literal[1];
        else
            c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c)); 
    }
       
    else if(isInt(literal)) 
    {
        long l = std::strtol(literal.c_str(), NULL, 10);// pour gere les limites

        if(l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        } 

        int i = static_cast<int>(l);
        if(i < 0 || i > 127)
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
        
    else if(isFloat(literal)) 
    {
        double tmp = std::strtod(literal.c_str(), NULL);
        float f = static_cast<float>(tmp);
        
        if(std::isnan(f) || std::isinf(f) || f < 0 || f > 127 )
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(f));
        if(std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    } 
    else if(isDouble(literal) || isPseudoliteral(literal))
    {
        double d = std::strtod(literal.c_str(), NULL); 

        if(std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else
            printChar(static_cast<char>(d));

        if(std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } 
}


