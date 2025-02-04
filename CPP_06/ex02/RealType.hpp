/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:45:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 16:30:05 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALTYPE_HPP

# define REALTYPE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;
class Base
{
    public:
        virtual ~Base();
        static Base *generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

class A : public Base
{ 
    public:
        A(){ std::cout << "A-Class spawned." << std::endl;}
};

class B : public Base
{ 
    public:
        B(){ std::cout << "B-Class spawned." << std::endl;}   
};

class C : public Base
{
    public:
        C(){ std::cout << "C-Class spawned." << std::endl;}
};

#endif

