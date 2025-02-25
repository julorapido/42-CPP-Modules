/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:08:18 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/25 15:22:52 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGME_HPP
# define PMERGME_HPP

#include <utility>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <iomanip>
/*
	Tri par fusion-insertion ou algorithme de Ford-Johnson:
 	- Il utilise moins de comparaisons dans le pire des cas que le tri par 
      insertion et le tri fusion qui sont les meilleurs algorithmes connus auparavant

*/
class PmergeMe
{
	private:
		int					count;
		std::vector<int>	a;
		std::deque<int>		b;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		int	init_containers(int argc, char **argv);
		void display_inf(void);
		// template <typename T>
		// static void insertionSort(T& container);
		// template <typename T>
		// static void fordJohnsonMerge(T& L, T& R, T& result);

};

#endif
