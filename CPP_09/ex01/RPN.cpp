/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:31 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 15:05:07 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
    // std::cout << "- BitcoinExchange Class instantiated." << std::endl; 
}

RPN::~RPN(void)
{
    // std::cout << "- BitcoinExchange Class destroyed." << std::endl; 
}

RPN &RPN::operator=(const RPN &cpy)
{
    (void)(cpy);
    return *this;
}
RPN::RPN(const RPN &copy)
{
    *this = copy;
}
bool    RPN::verif_args(int a, char **argv)
{
    for(int i = 1; i < a; i++)
    {
        std::string s = std::string(argv[i]);
        for (size_t j = 0; j < s.length(); ++j)
        {
            if (!std::isdigit(s[j]) && !(
                    s[j] == '*' || s[j] == '-'
                    || s[j] == '+' || s[j] == '/'
                ))
                return false;  // if any character is not a digit, return false
        }
    }
    return (true);
}
void    RPN::handle_args(int a, char **argv)
{
    for(int i = 1; i < a; i++)
    {
        std::string str = std::string(argv[i]);
        bool a = false;
        for (size_t j = 0; j < str.length(); ++j)
        {
            if (!std::isdigit(str[i]))
            {
                a = true;
            }
        }
        if(a)
            this->s.push(str[i]);
        else
        {
            int a[2];
            for(int i = 0; i < 2; i ++)
            {
                a[i] = this->s.top();
                this->s.pop();
            }
        }
    }
}
