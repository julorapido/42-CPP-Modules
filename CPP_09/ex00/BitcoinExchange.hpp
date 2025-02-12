/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:06:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/12 13:58:59 by jsaintho         ###   ########.fr       */
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
#include <deque>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <limits.h>

class BitcoinExchange
{
    private:
 
    public:
        std::deque<std::pair<std::string, float> > dq_csv;
        std::deque<std::pair<std::string, float> > dq_infile;
        std::ifstream infile;
        std::ifstream csv;
        int             parsing_err_line;
        BitcoinExchange(void);
        ~BitcoinExchange();
};

#endif