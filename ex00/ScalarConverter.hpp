/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:35 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/23 17:09:40 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter

{
    private: 
        ScalarConverter();
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other );
        ~ScalarConverter();

    public: // delete car on ne peut pas instancier la classe 
        static void convert(const std::string&  literal);
        
};

#endif