/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:20:21 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/26 10:37:15 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.name = "samira";
    data.id = 5;
    Data* originalPtr = &data;
    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* back = Serializer::deserialize(raw);

    std::cout << "Adresse originale: " << originalPtr << std::endl;
    std::cout << "raw value: " << raw << std::endl;
    std::cout << "original name: " << originalPtr->name << std::endl;
    std::cout << "original id: " << originalPtr->id << std::endl;
    std::cout << "Adresse interpretee: " << back << std::endl;
    std::cout << "back name: " << back->name << std::endl;
    std::cout << "back id: " << back->id << std::endl;

    if(originalPtr == back)
        std::cout << "original == back" << std::endl;
    else
        std::cout << "original != back" << std::endl;    
}
// static uintptr_t serialize(Data* ptr);
// static Data* deserialize(uintptr_t raw);