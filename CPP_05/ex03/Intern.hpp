/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:36:05 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 13:51:45 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

# define INTERN_HPP

#include <iostream>

class Intern
{
	public:
		~Intern();
		Intern();
		Intern(const Intern &copy);
		Form *MakeForm(std::string a, std::string b);		
};

#endif

