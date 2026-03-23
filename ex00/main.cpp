/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:29:55 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/23 16:35:24 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: Invalid arguments number ." << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(av[1]);
    return 0;
}