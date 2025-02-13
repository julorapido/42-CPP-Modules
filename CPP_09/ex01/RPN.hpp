/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 14:57:06 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdbool.h>

class RPN
{
    private:
        std::stack<int> s;
    public:
        RPN(void);
        ~RPN(void);
        RPN(const RPN &src);
        RPN &operator=(const RPN &cpy);
        void    init_stack(char **argv);
        void    handle_args(int a, char **argv);
        bool    verif_args(int a, char **argv);
};

#endif
