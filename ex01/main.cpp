/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:20:21 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/24 16:47:02 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.name = "samira";
    data.id = 5;
    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* back = Serializer::deserialize(raw);

    std::cout << std::endl;

    std::cout << "original ptr: " << original << std::endl;
    std::cout << "back ptr: " << back << std::endl;
    std::cout << "raw value: " << raw << std::endl;
    std::cout << "original id: " << original->id << std::endl;
    std::cout << "back id: " << back->id << std::endl;
    std::cout << "original name: " << original->name << std::endl;
    std::cout << "back name: " << back->name << std::endl;

    if(original == back)
        std::cout << "original == back" << std::endl;
    else
        std::cout << "original != back" << std::endl;    
}
// static uintptr_t serialize(Data* ptr);
// static Data* deserialize(uintptr_t raw);