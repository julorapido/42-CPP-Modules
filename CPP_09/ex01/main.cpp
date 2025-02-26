/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:36 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/26 12:31:11 by jsaintho         ###   ########.fr       */
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
        std::cout << "\033[33m";
        if(z == 3)
            std::cout << "Warning: 'notation should finish with an operator.' [+*/-]" << std::endl;
        else if (z == 2)
            std::cout << "Error: 'numbers should be spaced.' [123 => 1 2 3]" << std::endl;
        else if (z == 5)
            std::cout << "Error: 'operators should be spaced.' [1 5 ** 2 => 1 5 * 2]" << std::endl;
        else if (z == 4)
            std::cout << "Error: 'only 2 consecutive numbers' [1 8 3 + 4 - => 1 8 + 4 -]" << std::endl;
        else if (z == 6)
            std::cout << "Error: 'consecutive operators can only be placed at the end.' [1 5 + - 2 + => 1 5 + 2 + -]" << std::endl;
        else if (z == 7)
            std::cout << "Error: 'at least 2-operands 1-operation polish notation.' " << std::endl;    
        else if (z == 8)
            std::cout << "Error: 'notation should start with 2-spaced-operands.' " << std::endl;  
        else if (z == 9)  
            std::cout << "Error: 'cant have even number of operands/operators.' " << std::endl;  
        else                
            std::cout << "Error: args only: [0-9][*, -, +, /]" << std::endl;
        std::cout << "\033[0m";
        return (1);
    }
    // ReversePolishNotation->stack_args(argc, argv);
    ReversePolishNotation->handle_args(argc, argv);
    std::cout << "\033[32m"<<ReversePolishNotation->get_res() << "\033[0m" << std::endl;
    return 0;
}
