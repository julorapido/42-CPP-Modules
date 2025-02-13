/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:58:22 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/13 16:49:08 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdbool.h>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> s;
    public:
        RPN(void);
        ~RPN(void);
        RPN(const RPN &src);
        RPN &operator=(const RPN &cpy);
        void    handle_args(int a, char **argv);
        void    stack_args(int a, char **argv);
        int     verif_args(int a, char **argv);
        int     get_res(void);
};

#endif
