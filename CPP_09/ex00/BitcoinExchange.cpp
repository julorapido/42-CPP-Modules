/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:03:41 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 13:24:08 by jsaintho         ###   ########.fr       */
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


int BitcoinExchange::open_file(std::string s, int mode)
{
    if(s.empty())
        return (1);

    const char* ptr = s.c_str();
    std::ifstream *fd = (mode == 0) ? 
        &this->csv :  fd = &this->infile;
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

void BitcoinExchange::get_lines(void)
{
    std::ifstream *a[2] = {&(this->infile), &(this->csv)};
    std::map<std::string, float>  *c[2] = {&(this->dq_infile), &(this->dq_csv)};

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
                    (*c[i]).insert(std::pair<std::string, float>(
                        std::string("Error: bad input => " + line), (0)
                    ));    
                    continue;
                }
                std::string beforePipe = line.substr(0, p - 1);
                std::string aftPipe = line.substr(p + 1, line.length());
                if(beforePipe.length() != 10 || // YYYY-MM-DD
                    (aftPipe.length() > 10 || aftPipe.length() == 0) // INT
                ){
                    (*c[i]).insert(std::pair<std::string, float>(
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
                    (*c[i]).insert(std::pair<std::string, float>(beforePipe, (n)));    
                }
            }else // csv
            {
                size_t pos = line.find(',');
                std::string left = line.substr(0, pos);
                std::string right = line.substr(pos + 1, line.length());
                float n; std::stringstream as(right); as >> n;
                (*c[i]).insert(std::pair<std::string, float>(left, (n)));    
            }
        }
        if ((*a[i]).fail() && !(*a[i]).eof()) {
            std::cerr << "Error reading from file." << std::endl;
        }
        (*a[i]).close();
    }
}
unsigned long long BitcoinExchange::lexicographical_v(const std::string& str)
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
void BitcoinExchange::convertBitcoin(void)
{
    for(std::map<std::string, float>::iterator it = (this->dq_infile.begin());
        it != (this->dq_infile.end()); it++)
    {
        if ((it->first).find("Error:") != std::string::npos)
        {
            std::cout << "\033[37m"<< it->first << "\033[0m"<< std::endl;
        }
        else
        {
            unsigned long long f_date = lexicographical_v((this->dq_csv.begin())->first) 
                - lexicographical_v(it->first);
            std::pair<std::string, float> selected = *(this->dq_csv.end());
            // find closest date of deque->infile inside the csv
            for(std::map<std::string, float>::iterator jt = (this->dq_csv.begin());
                jt != (this->dq_csv.end());
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
        }
    }
}