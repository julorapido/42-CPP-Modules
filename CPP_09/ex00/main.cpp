/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:32 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 12:18:25 by jsaintho         ###   ########.fr       */
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

static void get_lines(BitcoinExchange *b)
{
    std::ifstream *a[2] = {&(b->infile), &(b->csv)};
    std::deque<std::pair<std::string, float> >  *c[2] = {&(b->dq_infile), &(b->dq_csv)};

    for(int i = 0; i < 2; i ++)
    {
        int l = 0;
        std::string line;
        while (std::getline(*a[i], line))
        {
            // each line
            if(i == 0) // infile parsing
            {
                        l++;
                if(line == ("date | value"))
                    continue;
                size_t p = line.find("|");
                if(p >= line.length())
                {
                    (*c[i]).push_back(std::pair<std::string, float>(
                        std::string("Error: bad input => " + line), (0)
                    ));    
                    continue;
                }
                std::string beforePipe = line.substr(0, p - 1);
                std::string aftPipe = line.substr(p + 1, line.length());
                if(beforePipe.length() != 10 || // YYYY-MM-DD
                    (aftPipe.length() > 10 || aftPipe.length() == 0) // INT
                ){
                    (*c[i]).push_back(std::pair<std::string, float>(
                        std::string("Error: invalid formats => " + line), (0)
                    ));    
                    continue;                
                }else
                {
                    // parse left part
                    for(unsigned long i = 0; i < beforePipe.length(); i++)
                    {
                        if((i != 4) && (i != 7) && (i < 10))
                        {
                            if(! (beforePipe[i] >= '0' && beforePipe[i] <= '9')){
                                beforePipe = ("Error: not a valid Date");
                                break;
                            }
                        }else{
                            if(!(beforePipe[i] == '-' || beforePipe[i] == ' ')){
                                beforePipe = ("Error: not a valid Date");
                                break;
                            }
                        }
                    }
                    // parse right part
                    for(unsigned long i = 0; i < aftPipe.length(); i++)
                    {   
                        if(!(aftPipe[i] >= '0' && aftPipe[i] <='9') 
                            && (aftPipe[i] != ' ' && aftPipe[i] != '.' && aftPipe[i] != '-')
                        )
                        {
                            beforePipe = ("Error: not a valid Date");
                            break;
                        }
                    }
                    // Create a stringstream object
                    int nn; std::stringstream ss(aftPipe); ss >> nn;
                    long long ln; std::stringstream sw(aftPipe); sw >> ln;
                    if(nn < 0)
                        beforePipe = ("Error: not a positive number.");
                    if(ln > 1000)
                        beforePipe = ("Error: too large number.");
                    float n; std::stringstream as(aftPipe); as >> n;
                    (*c[i]).push_back(std::pair<std::string, float>(beforePipe, (n)));    
                }
            }else // csv
            {
                size_t pos = line.find(',');
                std::string left = line.substr(0, pos);
                std::string right = line.substr(pos + 1, line.length());
                float n; std::stringstream as(right); as >> n;
                (*c[i]).push_back(std::pair<std::string, float>(left, (n)));    
            }
        }
        if ((*a[i]).fail() && !(*a[i]).eof()) {
            std::cerr << "Error reading from file." << std::endl;
        }
        (*a[i]).close();
    }
}
static unsigned long long lexicographical_v(const std::string& str)
{
    unsigned long long value = 0;

    for (size_t i = 0; i < str.length(); ++i) {
        // Shift previous value to the left (multiply by 256 to make room for the next character)
        value *= 256;
        // Add the ASCII value of the current character
        value += static_cast<unsigned char>(str[i]);
    }

    return value;
}
static void convertBitcoin(BitcoinExchange *b)
{
    for(std::deque<std::pair<std::string, float> >::iterator it = (b->dq_infile.begin());
        it != (b->dq_infile.end()); it++)
    {
        if ((it->first).find("Error:") != std::string::npos)
        {
            std::cout << "\033[37m"<< it->first << "\033[0m"<< std::endl;
        }
        else
        {
            unsigned long long f_date = lexicographical_v((b->dq_csv.begin())->first) 
                - lexicographical_v(it->first);
            std::pair<std::string, float> selected = *(b->dq_csv.end());
            // find closest date of deque->infile inside the csv
            for(std::deque<std::pair<std::string, float> >::iterator jt = (b->dq_csv.begin());
                jt != (b->dq_csv.end());
                jt++)
            {
                if((lexicographical_v(jt->first) 
                - lexicographical_v(it->first)) < (f_date))
                {
                    f_date = ((lexicographical_v(jt->first) 
                    - lexicographical_v(it->first)) < (f_date));
                    selected = *jt;
                }
            }
            std::cout << it->first << " => " << it->second << " => " 
                << (it->second * selected.second) << std::endl;
            // std::cout << "Comparing [\t{"
            // << it->first << ": " << it->second 
            // << "} vs {" <<
            // selected.first << ": " << selected.second << "}\t]" << std::endl;
        }
    }
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
    get_lines(bc);
    convertBitcoin(bc);
    delete bc;
    return (0);
}