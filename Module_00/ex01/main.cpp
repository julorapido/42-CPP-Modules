/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:03:31 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/18 12:33:30 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb_;
	std::string	s;

	std::cout << "[ADD, SEARCH, EXIT]" << std::endl;
	std::cout << "Please enter a command :" << std::endl;
	while(std::cin >> s)
	{		
		if(s == "ADD")
			pb_.add();
		else if (s == "SEARCH")
			pb_.search();
		else if (s == "EXIT")
			break;
		else
			std::cout << BOLDBLUE << "(Please enter a valid command !)" << DEFAULT << std::endl;
	}
	return (0);
}
