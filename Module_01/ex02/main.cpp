/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:09:21 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 14:24:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string	&stringREF = s;;

	std::cout << "Adress of [s1] = "<< &s << std::endl;
	std::cout << "Adress of [stringPTR] = "<< stringPTR << std::endl;
	std::cout << "Adress of [stringREF] = "<< &stringREF << std::endl;

	std::cout << "Value of [s1] = " << s << std::endl;
	std::cout << "Value pointed by [stringPTR] = " << *stringPTR << std::endl;
	std::cout << "Value pointed by [stringREF] = " << stringREF << std::endl;
	return 0;
}
