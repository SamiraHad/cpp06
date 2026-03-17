/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:42:02 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/17 14:03:00 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScalarConverter.hpp"

std::string ScalarConverter::detectType(const std::string& str)
{
    if(str.empty())
        return "unknows";
    else if(!isdigit(str[0]))
        return "char";
    else if(isdigit(str[0]))
        return "int";
    else if(isdigit(str[0]) && str[1] = "." && str[2] = "f"))
        return "float";
    else (isdigit(str[0]) && str[1] = "." && str[2] != "f"))
        return "double";
    else
        return "unknows";
    
}

void convert(const std::string&  str)
{
    
}
