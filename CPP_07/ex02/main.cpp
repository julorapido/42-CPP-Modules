/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:56:11 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 15:06:02 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int	main(void)
{
	unsigned int a = 5;
    // An array of strings
	std::cout << "---------An array of strings------ "<< std::endl; 
    Array<std::string> strArray( a );
    strArray[0] = "begin";
    strArray[1] = "middle";
    strArray[2] = "end";
	for(int i = 0; i < 3; i ++)
    	std::cout << i << ": " << strArray[i] << std::endl; 
 
    //A copy of first array
	std::cout << "---------copy of 1st arr------ "<< std::endl; 
    Array<std::string> copy = strArray;
    copy[1] = "other";
	for(int i = 0; i < 3; i ++)
    	std::cout << i << ": " << copy[i] << std::endl;
 
    //An array of integers
	std::cout << "---------An array of integers------ "<< std::endl; 
    Array<int> intArray( 5 );
    try 
	{
	    size_t i = 0;
        while( true )
		{
            intArray[ i] = i * 10;
			i++;
        }
    }catch( std::exception  & e )
	{
        std::cout << e.what() << std::endl;
    }
	
	for(int i = 0; i < 5; i ++)
    	std::cout << i << ": " << intArray[i] << std::endl; 
    return 0;
}
