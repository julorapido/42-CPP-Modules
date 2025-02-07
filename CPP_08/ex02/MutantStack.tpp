/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:36:13 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/07 15:42:28 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout<< "MutantStack iniatlized. " << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout<< "MutantStack destroyed. " << std::endl;
}
