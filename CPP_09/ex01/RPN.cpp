/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:31 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 16:50:50 by jsaintho         ###   ########.fr       */
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
int RPN::verif_args(int a, char **argv)
{
    for(int i = 1; i < a; i++)
    {
        std::string s = std::string(argv[i]);
        for (size_t j = 0; j < s.length(); ++j)
        {
            if (!std::isdigit(s[j]) && !(
                    s[j] == '*' || s[j] == '-'
                    || s[j] == '+' || s[j] == '/'
                    || s[j] == ' '
                ))
                return 1;  // if any character is not a digit, return false
            else{
                // "12 + 3 - 9"
                if(std::isdigit(s[j]) && std::isdigit(s[j + 1]))
                    return 2;
                // "1 8 3 + 4 - 2"
                if(s[j + 2] && s[j + 4])
                    if(std::isdigit(s[j]) && std::isdigit(s[j + 2]) && std::isdigit(s[j + 4]))
                        return 4;
            }
        }
        int k = s.length() - 1;
        if (!( s[k] == '*' || s[k] == '-'
            || s[k] == '+' || s[k] == '/'
            ))
        return (3);
    }
 
    return (0);
}
/*
void    RPN::stack_args(int a, char **argv)
{
     for(int i = 1; i < a; i++)
    {
        std::string s = std::string(argv[i]);
        std::string s2; 
        std::cout << "stacking: " << s << std::endl;    
        for (size_t j = 0; j < s.length(); ++j)
        {
            if (!std::isdigit(s[j]) || !s[j + 1])
            {
                if(!s[j + 1])
                    s2.push_back(s[j]);
                int num = atoi(s2.c_str());
                if(s2 != ""){
                    this->s.push(num);
                    std::cout << ">pushing " << num << " to stack." << std::endl;    
                }  
                s2 = "";
            }else
            {
                s2.push_back(s[j]);
            }
        }
    }
}*/

void    RPN::handle_args(int a, char **argv)
{
    for(int j = 1; j < a; j++)
    {
        std::string str = std::string(argv[j]);
        for (size_t i = 0; i < str.length(); ++i)
        {
            if (std::isdigit(str[i]))
            {
                int b = (str[i]) - '0';
                // std::cout << ">pushing " << b << " to stack." << std::endl;    
                this->s.push(b);    
            }
            else // operator
            {
                if(str[i] != ' ')
                {
                    int c[2] = {0, 0};
                    for(int i = 0; i < 2; i ++)
                    {
                        c[i] = this->s.top();
                        this->s.pop();
                    }
                    std::cout << c[1] << str[i] << c[0] << std::endl;    
                    if(c[0] != 0 && c[1] != 0)
                    {
                        switch (str[i])
                        {
                            case '+':
                                this->s.push(c[0] + c[1]);
                                break;
                            case '-':
                                this->s.push(c[1] - c[0]);
                                break;
                            case '*':
                                this->s.push(c[0] * c[1]);
                                break;
                            case '/':
                                this->s.push(c[1] / c[0]);
                                break;
                        }
                    }
                }
            }
        }
  
    }
}

int    RPN::get_res(void)
{
    return (this->s.top());
}

