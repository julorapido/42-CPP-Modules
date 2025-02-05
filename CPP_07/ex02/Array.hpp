/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:57:24 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 14:58:36 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

# define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#define nullptr 0
#define DEFAULT_ARR_SIZE 10

template <typename T>
class Array
{
	private:
		T 				*arr;
		unsigned int	s;
	public:
		Array(unsigned int n);
		Array( const Array<T> & src);
		Array();
		~Array();
		unsigned int	size();
		
		Array<T> & operator=(  const Array<T> & original );
		T & operator[]( size_t p ) const;
		T & operator[]( size_t p );
};
#include "Array.tpp"

#endif
