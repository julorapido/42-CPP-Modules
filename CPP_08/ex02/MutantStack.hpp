/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:36:07 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/07 15:45:10 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MUTANTSTACK_HPP

# define MUTANTSTACK_HPP

template <typename T>
class MutantStack
{
	public:
		MutantStack();
		MutantStack(const MutantStack &f);
		MutantStack <T>& operator=(const MutantStack & src);
		~MutantStack();
	private:
		std::vectprT	*stack;
		
};

#include "MutantStack.hpp"

#endif
