/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:07:51 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 15:06:32 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    int c;
    if(argc > 5000 || argc < 3)
    {
        std::cout << "\033[31m error: program parameters are integers[> 2 && < 500] \033[0m" << std::endl;
        return (EXIT_FAILURE);
    }
    PmergeMe *hey = new PmergeMe();
    if(!hey)
        return(EXIT_FAILURE);
    c =  hey->init_containers(argc, argv);
    if(!(!c) )
    {
        if(c == 1)
            std::cout << "\033[31m error: program only takes integers(positive & negative)\033[0m" << std::endl;
        if(c == 2)
            std::cout << "\033[31m error: program doesnt handle integer overflows\033[0m" << std::endl;
        return (EXIT_FAILURE);     
    }
    hey->display_inf();
    delete hey;
    return 0;
}
