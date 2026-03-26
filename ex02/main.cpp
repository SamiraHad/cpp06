/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:43:31 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/26 16:07:49 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>  //srand: sert à initialiser le générateur de nombres aléatoires
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));
    
    for(int i = 0; i < 10; i++)
    {
        Base* base = generate();
        std::cout << "Pointer : ";
        identify(base);  //version pointeur → Base*
        std::cout << "Reference : ";
        identify(*base); // version référence → Base& : Pour appeler la version reference, on defererence le pointeur avec *.
        delete base;
    }
    
}