/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:32 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 13:24:05 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange;

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Program take 1 file as argument. " << std::endl;
        return (1);
    }
    BitcoinExchange *bc = new BitcoinExchange();
    if(bc->open_file("data.csv", 0) != 0 || bc->open_file(argv[1], 1) != 0)
    {
        std::cout << "..." << std::endl;       
        delete bc;
        return (1);
    }
    bc->get_lines();
    bc->convertBitcoin();
    delete bc;
    return (0);
}