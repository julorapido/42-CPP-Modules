/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:06:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 13:10:24 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <cerrno>  // For errno
#include <cstdio>  // For perror()
#include <clocale>
#include <cstring>
#include <fstream>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <queue>
#include <map>

class BitcoinExchange
{
    private:
 
    public:
        //  :/
        /*
        std::deque<std::pair<std::string, float> > dq_csv;
        std::deque<std::pair<std::string, float> > dq_infile;
        */
        std::map<std::string, float> dq_csv;
        std::map<std::string, float> dq_infile;
        std::ifstream   infile;
        std::ifstream   csv;
        int             parsing_err_line;
        BitcoinExchange(void);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
};

#endif