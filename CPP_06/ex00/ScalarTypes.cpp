/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:17:26 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 15:00:14 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypes.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Created ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructed ScalarConverter" << std::endl;
}
// Overloaded Operators
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class
	return *this;
}



template<typename T>
T atoi_impl(const char* str)
{
    while (std::isspace(static_cast<unsigned char>(*str)))
        ++str;
    bool negative = false;
    int n = 0;
    while(*str == '+' || *str == '-')
    {
        if(*str == '-')
            n ++;
        (++str);
    }
    if(n % 2 != 0)
        negative = true;
    T result = 0;
    for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
    {
        int digit = *str - '0';
        result *= 10;
        result -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
    }
 
    return negative ? result : -result;
}
 

static int get_s_type(std::string s)
{
    (void)(s);
    return (1);
}

static long long s_to_int(std::string s)
{
    const char *cstr = s.data();
    return (atoi_impl<long long>(cstr));
}

static double s_to_float(std::string s)
{
    return(atof(s.c_str()));
}


static bool valid_s(std::string s)
{
    if((s == "-inff") || (s == "+inff") 
        ||  s == "nan" || s == "nanf" || (s == "-inf") || (s == "+inf"))
        return (true);
    int d = 0;
    for(size_t i = 0; i < s.length(); i++)
    {
        if(std::isdigit(s[i]))
            d++;
        // catches `-42+-`
        if(i > 0 && ((s[i] == '-' || s[i] == '+') && std::isdigit(s[i - 1] )))
        {
            std::cout << " error: catched '42+-5+-' " << std::endl;
            return (false);
        }
    }
    if (d == 0)
    {
        std::cout << " error: At least 1 digit plz [0-9] " << std::endl;
        return (false);
    }
    if(s.find_first_of(".") != s.find_last_of(".") || // catches `0..0`
			isdigit(s[s.find_first_of(".") + 1]) == 'f')
    {
        std::cout << " error: catched '0..0' " << std::endl;
        return (false);
    }
    if (s.find('f') < s.length())
    {
        if (s.find_first_of("f") != s.find_last_of("f") || // catches `0.0ff`
            s.find_first_of(".") != s.find_last_of(".") || // catches `0..0f`
            s.find_first_of("f") - s.find_first_of(".") == 1 || //catches `0.f`
            s.find_first_of(".") == 0 || // catches `.0f`
            s[s.find_first_of("f") + 1] != '\0') // catches `0.0f0`
        {
            std::cout << " error: catched ['0.0ff', '0.f', '0..0f', '0.+-[aA-zZ]0f', '0.0f0'] " << std::endl;
            return (false);
        }
    }
    if(s.find('.') > s.length() && s.find('f') < s.length())
    {
        std::cout << "error: invalid suffix 'f' on integer constant " << std::endl;
        return (false);
    }
    for(size_t i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i]) && s[i] != 'f')
            return (false);
        if(s[i] > 0 && s[i] < 47)
            if(s[i] != '.' && s[i] != '-' && s[i] != '+')
                std::cout << "non-printable character" << std::endl;
    }
    return (true);
}
static char s_to_char(std::string s)
{
    if(s_to_int(s) <= 0 || (s_to_int(s) > 0 && s_to_int(s) < 31)
        || s_to_int(s) > 127)
        return ('\0');
    char c = static_cast<char>(s_to_int(s));
    return (c);
}


void ScalarConverter::convert(std::string s)
{
    int s_type;

    if(!valid_s(s))
    {
        std::cout << "\033[31m Non-Valid INPUT.\033[0m" << std::endl;
        return ;
    }
    s_type = get_s_type(s);


    // CHAR
    if(s == "nan" || s == "nanf" || s == "-inff" || s == "+inff"
      || s == "-inf" || s == "+inf")
    {
            std::cout << "Char: Impossible" << std::endl;
            std::cout << "Int: Impossible" << std::endl;
    }else
    {
        if(s_to_char(s) == '\0')
            std::cout << "Char: not-displayable" << std::endl;
        else
            std::cout << "Char: " << (s_to_char(s)) << std::endl;


        // INT
        if(s_to_int(s) > INT_MAX || s_to_int(s) < INT_MIN)
            std::cout << "Int: " << "INTEGER_OVERFLOW" << std::endl;
        else
            std::cout << "Int: " << (s_to_int(s)) << std::endl;
    }

    // 42.0 42.0f
    bool f_end = false;
    if(s_to_float(s) - s_to_int(s) != 0)
        f_end = true;
    std::cout << "Float: " << std::setprecision (15) << s_to_float(s)  << (!f_end ? ".0f" :  "f") << std::endl;
    std::cout << "Double: " << s_to_float(s) << (!f_end ? ".0" : "") << std::endl;
}