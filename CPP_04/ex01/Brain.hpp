/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:31:23 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/28 14:08:50 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP
# include <iostream>

using namespace std;

class Brain
{
	public:
			Brain();
			Brain(const Brain &copy);
			~Brain();
			Brain & operator=(const Brain &src);
			const std::string 	*getIdeaAddress(size_t i)const;
			const std::string	getIdea(size_t i)const;
			void				setIdea(size_t i, std::string idea);
	protected:
			std::string _ideas[100];
};

#endif
