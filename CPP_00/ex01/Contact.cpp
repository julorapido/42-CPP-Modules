/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:19:25 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/17 15:44:21 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{ }

Contact::~Contact(void)
{ }

void	Contact::Contact_Field(std::string v, int n)
{
	switch(n){
		case 0:
			this->f_name = v;
			break;
		case 1:
			this->l_name = v;
			break;
		case 2:
			this->phone_nbr = v;
			break;
		case 3:
			this->secret = v;
			break;
	}
}

std::string	Contact::Get_Contact_Field(int n)
{
	if(this->f_name.empty())
		return (std::string("(nil)"));
	switch(n){
		case 0:
			return(this->f_name);
		case 1:
			return(this->l_name);
		case 2:
			return(this->phone_nbr);
		case 3:
			return(this->secret);
	}
	return ("");
}
