/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:13:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:14 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits.h>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iomanip>


class ScalarConverter
{
	private:
		// private Constructor and operator =
		ScalarConverter();
	public:		
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		static void	convert(std::string s);
};
#endif
