/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:23:45 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/05 16:34:08 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
class ValueNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Value not found in container";
		}
};

template <typename T>
void	easyfind(T &container, int value)
{
	// Déclare une variable it de type itérateur du conteneur T.
	// std::find() : Recherche la première occurrence de value dans le conteneur,
	// si elle n'est pas trouvée, retourne un itérateur pointant vers la fin du conteneur.
	// https://cplusplus.com/reference/algorithm/find/
	typename T::iterator it = std::find(
		container.begin(), container.end(), value
	);
	if (it == container.end())
		throw ValueNotFoundException();
	std::cout << "\033[32m Value " << value << " found in container \033[0m" << std::endl;
}

#endif