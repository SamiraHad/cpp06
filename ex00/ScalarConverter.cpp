/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:02 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/23 17:15:39 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &literal) // je verifie si lateral est 'a' format classique ou un seul char non chiffre a, @, ...
{
    if((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') //'a'
     || (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))) //le caractère n’est pas un chiffre
        return true;
    return false;
}

static bool isPseudoLateral(const std::string& lateral) //je verifie si not a numbre || infini
{
    if(lateral == "nan" || lateral == "-inf" || lateral == "+inf" ||
        lateral == "nanf" || lateral == "-inff" || lateral == "+inff")
            return true;
    return false;
}

static bool isInt(const std::string &literal)
{
    if(isPseudoLateral(literal) || literal.empty())
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
    if(isPseudoLateral(literal) || literal.empty())
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
    if(isPseudoLateral(literal) || literal.empty())
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

static std::string detectType(const std::string &literal)
{
    if(isPseudoLateral(literal))
        return "pseudo";
    else if(isChar(literal))
        return "char";
    else if(isInt(literal))
        return "int";
    else if(isFloat(literal))
        return "float";
    else if(isDouble(literal))
        return "double";
    else
        return "unknown";
}

static void printChar(char c)
{
    if(c < 0 || c > 127 || std::isnan(c))
        std::cout << " char: impossible" << std::endl;
    else if(!std::isprint(static_cast<unsigned char>(c)))
        std::cout << " char: Non displayable" << std::endl;
    else
        std::cout << " char: '" << c << "'" << std::endl; 
    std::cout << " int: " << static_cast<int>(c)<< std::endl;
    std::cout << " float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << " double: " << static_cast<double>(c) << std::endl;     
}

static void printInt(int nbrInt)
{
    if(nbrInt < 0 || nbrInt > 127 || std::isnan(nbrInt) || std::isinf(nbrInt))
        std::cout << " char: impossible" << std::endl;
    else if(!isprint(static_cast<unsigned char>(nbrInt)))
        std::cout << " char: Non displayable" << std::endl;
    else   
        std::cout << " char: '" << static_cast<char>(nbrInt) << "'" << std::endl; 
    std::cout << " int: " << nbrInt << std::endl;
    std::cout << " float: " << static_cast<float>(nbrInt) << "f" << std::endl;
    std::cout << " double: " << static_cast<double>(nbrInt) << std::endl;  
}

static void printFloat(float nbrFloat)
{
    if(nbrFloat < 0 || nbrFloat > 127 || std::isnan(nbrFloat) || std::isinf(nbrFloat))
        std::cout << " char: impossible" << std::endl;
    else if(!isprint(static_cast<unsigned char>(nbrFloat)))
        std::cout << " char: Non displayable" << std::endl;
    else
        std::cout << " char: '" << static_cast<char>(nbrFloat) << "'" << std::endl; 
    std::cout << " int: " << static_cast<int>(nbrFloat) << std::endl;
    std::cout << " float: " << nbrFloat << "f" << std::endl;
    std::cout << " double: " << static_cast<double>(nbrFloat) << std::endl;  
}
    
static void printDouble(double nbrDouble)
{
    if(nbrDouble < 0 || nbrDouble > 127 || std::isnan(nbrDouble) || std::isinf(nbrDouble))
        std::cout << " char: impossible" << std::endl;
    else if(!isprint(static_cast<unsigned char>(nbrDouble)))
        std::cout << " char: Non displayable" << std::endl;
    else    
        std::cout << " char: '" << static_cast<char>(nbrDouble) << "'" << std::endl; 
    std::cout << " int: " << static_cast<int>(nbrDouble) << std::endl;
    std::cout << " float: " << static_cast<float>(nbrDouble) << "f" << std::endl;
    std::cout << " double: " << nbrDouble << std::endl;  
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string type = detectType(literal);
    
    if(type == "char")
    {
        char c;
        if(literal.size() == 3)
            c = literal[1];
        else
            c = literal[0];
        printChar(c);
            
    }
    else if(type == "int") 
    {
        int value = static_cast<int>(std::strtod(literal.c_str(), NULL));
        printInt(value);
    } 
    else if(type == "float") 
    {
        float value = static_cast<float>(std::strtod(literal.c_str(), NULL));
        printFloat(value);
    }  
    else if(type == "double")
    {
        double value = std::strtod(literal.c_str(), NULL);
        printDouble(value);
    }
    else if(type == "pseudo")
    {
        double value = std::strtod(literal.c_str(),NULL);
        printDouble(value);   
    }
    else
        std::cout << " Error input" << std::endl;
}