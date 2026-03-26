/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:43:15 by hsamira           #+#    #+#             */
/*   Updated: 2026/03/26 15:29:39 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    
}

Base * generate(void) //La fonction generate instancie aléatoirement une classe dérivée de Base
{
    int b = rand() % 3;
    if(b == 0)
    {
        Base* a = new A;
        return a;
    }
    else if(b == 1)
    {
      Base* b = new B;
      return b;  
    }
    else
    {
        Base* c = new C;
        return c;
    }
}

void identify(Base* p)//identify utilise dynamic_cast pour déterminer son type réel.
{
    if(p == NULL)
        return;
    if(A* a = dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(B* b = dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(C* c = dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Cast failed" << std::endl;
}

void identify(Base& p)
//le programme va crasher direct si ce n’est pas un A car il ne retourne pas NULL
//la reference ne ne peut pas retourner Null en cas d'echec donc on utilise les exeptions
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}
    
   try
   {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
   }
   catch(...){}
   
   try
   {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
   }
   catch(...) {}
   
}