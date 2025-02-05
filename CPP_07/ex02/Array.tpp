/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:15:15 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 15:01:11 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->arr = new T[DEFAULT_ARR_SIZE];
	this->s = DEFAULT_ARR_SIZE;
}
template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->s = n;
}

template <typename T>
Array<T>::Array( const Array<T> & src )
{
    this->arr = nullptr;
    *this = src;
}

template <typename T>
Array<T>::~Array() {
    delete [] this->arr;
}


template <typename T>
unsigned int Array<T>::size()
{
	return (this->s);
}


template <typename T>
Array<T> & Array<T>::operator=(  const Array<T> & original )
{
    if ( this->arr != nullptr ) 
		delete [] this->arr;
	
    this->s = original.s;
    this->arr = new T[ this->s ];

    for(size_t p = 0; p < this->s; p++)
	{
        this->arr[p] = original.arr[p];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[]( size_t p ) const
{
    if ( p >= this->s || this->arr == NULL)
    {
        std::stringstream buffer;
        buffer << "Bad position " << p;
        throw std::out_of_range( buffer.str() ); 
    }
    return this->arr[ p ];
}

template <typename T>
T &Array<T>::operator[]( size_t p )
{
    if ( p >= this->s || this->arr == NULL)
    {
        std::stringstream buffer;
        buffer << "Bad position " << p;
        throw std::out_of_range( buffer.str() ); 
    }
    return this->arr[ p ];
}
