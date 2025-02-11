/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:32 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/11 16:59:51 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange;

static int open_file(BitcoinExchange *b, std::string s, int mode = 0)
{
    if(!b || s.empty())
        return (1);

    const char* ptr = s.c_str();
    std::ifstream *fd = (mode == 0) ? 
        &b->csv :  fd = &b->infile;
    // Open the file
    (*fd).open(ptr);
    // Check if the file was opened successfully
    if ((*fd).fail())
    {
        std::cerr << "File open failed: " << std::strerror(errno) << std::endl;
        std::cerr << "Error opening the file: " << s << std::endl;
        return 1;  // Return a non-zero value to indicate error
    }

    return 0;
}

static int  get_lines(BitcoinExchange *b)
{
    std::ifstream *a[2] = {&(b->infile), &(b->csv)};
    std::deque<std::string> *c[2] = {&(b->dq_infile), &(b->dq_csv)};

    for(int i = 0; i < 2; i ++)
    {
        std::string line;
        while (std::getline(*a[i], line))
        {
            // each line
            if(i == 0) // infile parsing
            {
                if(line == ("date | value"))
                    continue;
                size_t p = line.find("|");
                if(p >= line.length())
                    return -1;
                std::string beforePipe = line.substr(0, p);
                std::string aftPipe = line.substr(p + 1, line.length());
                std::cout << aftPipe.length() << aftPipe << "-"<< std::endl;
                std::cout << beforePipe.length() << beforePipe << "-"<< std::endl;
                if(beforePipe.length() != 11 || // YYYY-MM-DD
                    (aftPipe.length() > 10 || aftPipe.length() == 0) // INT
                ){
                    return -2;
                }else
                {
                    // parse left part
                    for(unsigned long i = 0; i < beforePipe.length(); i++)
                    {
                        if((i >= 0 && i < 4) || (i >= 5 && i < 7)){
                            if(! (beforePipe[i] >= '0' && beforePipe[i] <= '9'))
                                return -3;
                        }else{
                            std:cout << "beforePipe" << i << " = " << beforePipe[i] << std::endl;
                            if(!(beforePipe[i] == '-') && !(beforePipe[i] == ' '))
                                 return -4;
                        }
                    }
                    // parse right part
                    for(unsigned long i = 0; i < aftPipe.length(); i++)
                    {   
                        if(!(aftPipe[i] >= '0' && aftPipe[i] <='9') && !(aftPipe[i] == ' '))
                            return -5; 
                    }
                }
            }else // csv
            {
                (*c[i]).push_front(line);
            }
        }
        if ((*a[i]).fail() && !(*a[i]).eof()) {
            std::cerr << "Error reading from file." << std::endl;
        }
        (*a[i]).close();
    }
    return (0);
}

static void convertBitcoin(BitcoinExchange *b)
{
    
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Program take 1 file as argument. " << std::endl;
        return (1);
    }
    BitcoinExchange *bc = new BitcoinExchange();
    if(open_file(bc, "data.csv") != 0 || open_file(bc, argv[1], 1) != 0)
    {
        std::cout << "..." << std::endl;       
        delete bc;
        return (1);
    }
    int gl = get_lines(bc);
    if(gl != 0)
    {
        std::cout << "Error(" << gl <<")parsing: "<< argv[1] << std::endl;       
        delete bc;
        return (1);
    }
    convertBitcoin(bc);
    delete bc;
    return (0);
}