/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:28:38 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 16:35:17 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main(void)
{
	// TEST VECTORS
	std::vector<int> v;
	v.push_back(0);
	v.push_back(7);
	v.push_back(5);

	::easyfind(v, 7);

	return (0);
}
