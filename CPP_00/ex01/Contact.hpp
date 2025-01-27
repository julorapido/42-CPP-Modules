/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:51:45 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/17 15:41:33 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{

	private:
		std::string	f_name;
		std::string l_name;
		std::string phone_nbr;
		std::string secret;
	public:
		~Contact(void);
		Contact(void);
		void		Contact_Field(std::string value, int n);
		std::string	Get_Contact_Field(int n);
};
