/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:03:41 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 12:31:04 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    // std::cout << "- BitcoinExchange Class instantiated." << std::endl; 
}

BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout << "- BitcoinExchange Class destroyed." << std::endl; 
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    (void)(cpy);
    return *this;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}