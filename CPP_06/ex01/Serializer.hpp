/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:08:48 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 15:34:11 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP


# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
using namespace std;

struct Data
{
	std::string s1;
	std::string s2;
};

class Serializer
{
	private:
		Serializer();
	public:
		static Data*		deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data* ptr);
		static Serializer& getInstance();
		~Serializer();
};

#endif
