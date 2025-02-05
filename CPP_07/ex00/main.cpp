/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:35:57 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:16 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template<typename T>
static void _swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
static T mmin(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}
template <typename T>
static T mmax(T a, T b)
{
    if (a < b)
        return b;
    else
        return a;
}

int main( void )
{

    int a = 2;
    int b = 3;
    _swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << mmin( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << mmax( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    _swap(c, d);
    
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << mmin( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << mmax( c, d ) << std::endl;
    return 0;
}
