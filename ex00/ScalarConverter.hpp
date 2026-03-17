/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:35 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/17 13:36:48 by hsamira          ###   ########.fr       */
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
        static std::string detectType(const std::string& STR);
        static void printChar(std::string& string);
        static void printInt(int nbrInt);
        static void printFloat(float nbrFloat);
        static void printDouble(double nbrDouble);
            

    public: // delete car on ne peut pas instancier la classe 
        ScalarConverter() = delete;
        ScalarConverter( const ScalarConverter& other ) = delete;
        ScalarConverter& operator=( const ScalarConverter& other ) = delete;
    
        static void convert(const std::string&  str);
        
};

#endif