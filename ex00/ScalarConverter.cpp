/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:02 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/22 16:44:54 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &literal)
{
    if((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') ||
     (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))))
        return true;
    return false;
}

static bool isInt(const std::string &literal)
{
    
}
static bool isFloat(const std::string &literal) static bool isDouble(const std::string &literal) static std::string detectType(const std::string &str);
static void printChar(std::string &string);
static void printInt(int nbrInt);
static void printFloat(float nbrFloat);
static void printDouble(double nbrDouble);
