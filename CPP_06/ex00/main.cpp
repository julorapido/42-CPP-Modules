/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:14:58 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 13:58:41 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypes.hpp"
#include <stdio.h>
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "1 Argument has to be given." << std::endl;
        return (0);
    }
    ScalarConverter *s = NULL;
    std::cout << "\033[34m-------------------  Run Conversion on: \033[32m "<< argv[1] << "\033[34m-------------------\033[0m" << std::endl;
    s->convert(argv[1]);
    return (0);
}