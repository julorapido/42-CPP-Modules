/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:13:01 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 14:19:18 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
using namespace std;

class ScalarConverter
{
	private:
		// private Constructor and operator =
		ScalarConverter();
	public:		
		~ScalarConverter();
		static void *convert(void *any);
};
#endif
