/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:12:18 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/04 15:37:09 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	salut;

	salut.s1 = "Hola";
	salut.s2 = "Mundo";

    Serializer& serializer = Serializer::getInstance();
	std::cout << "Data (non=serialized): {" << salut.s1 << ", "<< salut.s2 << "}" << std::endl;


	uintptr_t	serialized_ptr = (serializer).serialize(&salut);
	std::cout << "Salut (serialized): " << serialized_ptr << std::endl;

	Data	*ptr = (serializer).deserialize(serialized_ptr);
	std::cout << "Salut (deserialized): " << ptr->s1 << " " << ptr->s2 << std::endl;
	return (0);
}
