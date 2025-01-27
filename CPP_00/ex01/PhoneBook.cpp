/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:07:44 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/18 12:52:37 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "8-Contact PhoneBook intialized." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

void PhoneBook::setCount(int n)
{
	this->us_count = n;
}

void PhoneBook::add(void)
{
	static int i = 0, b = 0;
	const std::string prompts[4] = {"First Name", "Last Name", "Phone Number", "Dark Secret"};
	std::string v;

	Contact c;
	std::cout << "========   Creating Contact ["  << i + 1 << "]   ========" << std::endl;
	for(int j = 0; j < 4; j ++)
	{
		std::cout << prompts[j] << ":" << std::endl;
		std::cin >> v;
		c.Contact_Field(v, j);
	}
	this->contacts_[i] = c;
	if (!b)
		std::cout << MAGENTA << "Contact" << i + 1 << " Successfully created !" << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "Contact" << i + 1 << " Successfully modified !" << DEFAULT << std::endl;
	if(b == 0)
		setCount(i + 1);
	if(i + 1 == 8)
		b = 1;
	i++;
	if(i == 8) i = 0;
}

void	PhoneBook::search(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for(int i = 0; i < this->us_count; i++)
	{	
		std::cout << "|" << std::setw(10) << i;
		for(int j = 0; j < 3; j ++){
			std::string info = this->contacts_[i].Get_Contact_Field(j);
			int l = info.length();	
			std::cout << "|" << std::setw(10) << info.substr(0, 9) + ((l > 9) ? (".") : (""));
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "Type index of the entry to continue." << std::endl;
	int a; std::cin >> a;
	if(!std::cin)
		return ;
	if(!(a >= 0 && a < 9) || a > (this->us_count - 1)){
		std::cout << RED << "Index out of PhoneBook Range." << DEFAULT << std::endl;
	}else{
		const std::string cl[4] = {"First Name : ", "Last Name : ", "Nickname : ", "Secret : "};
		for(int j = 0; j < 4; j ++)
			std::cout << cl[j] << this->contacts_[a].Get_Contact_Field(j) << std::endl;
	}
}
