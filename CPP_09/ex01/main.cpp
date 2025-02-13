/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:36 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:00 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    int z;
    if(argc != 2)
    {
        std::cout << "Error: ./RPN ' your Polish-notation here. '" << std::endl;
        return (1);
    }
    RPN *ReversePolishNotation = new RPN();
    z = ReversePolishNotation->verif_args(argc, argv);
    if(z != 0)
    {
        if(z == 3)
            std::cout << "Error: 'notation should finish with an operator.' [+*/-]" << std::endl;
        else if (z == 2)
            std::cout << "Error: 'numbers should be spaced.' [123 => 1 2 3]" << std::endl;
        else if (z == 4)
            std::cout << "Error: 'only 2 consecutive numbers' [1 8 3 + 4 - => 1 8 + 4 -]" << std::endl;
        else                
            std::cout << "Error: args only: [0-9][*, -, +, /]" << std::endl;
        return (1);
    }
    // ReversePolishNotation->stack_args(argc, argv);
    ReversePolishNotation->handle_args(argc, argv);
    std::cout << ReversePolishNotation->get_res() << std::endl;
    return 0;
}
