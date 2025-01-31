/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:14:58 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 14:24:29 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypes.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "1 Argument has to be given." << std::endl;
        return (0);
    }
    ScalarConverter *s = NULL;
    s->convert(argv[0]);
    return (0);
}