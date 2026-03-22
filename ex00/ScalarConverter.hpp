/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:35 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/22 16:21:29 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter

{
    private: 
        ScalarConverter();
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other );
        ~ScalarConverter();

    public: // delete car on ne peut pas instancier la classe 
        static void convert(const std::string&  str);
        
};

static bool isChar(const std::string& literal);
static bool isInt(const std::string& literal);
static bool isFloat(const std::string& literal);
static bool isDouble(const std::string& literal);
static std::string detectType(const std::string& str);
static void printChar(std::string& string);
static void printInt(int nbrInt);
static void printFloat(float nbrFloat);
static void printDouble(double nbrDouble);

#endif