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

# include <vector>
# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		// Default constructor
		MutantStack() {}
		// Copy constructor
		MutantStack(const MutantStack &src) {
			*this = src;
		}
		// Copy assignment operator
		MutantStack &operator=(const MutantStack &src) {
			this->c = src.c;
			return *this;
		}
		// Destructor
		~MutantStack() {}

		// Create aliases for the main.cpp using ::iterator :
		//	- The [container_type] is essentially an alias for the underlying container
		//	  type that is used internally by the std::stack.
		//  - Since the underlying container is usually a sequence container (like std::deque, std::vector, etc.), 
		//    the std::stack class doesn't expose the iterators of this container directly.
		//    However, if you want to access the iterator of the underlying container, 
		// 	  you can use the [container_type] type and its iterators.
		//	- In other words, std::stack<T>::container_type::iterator is the iterator type that allows you to iterate
		//	  through the elements in the underlying container (such as std::deque, std::vector, etc.).
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const {
			return this->c.rend();
		}
};

#endif
