/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:14:00 by jsaintho          #+#    #+#             */
/*   Updated: 2025/01/31 14:04:51 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp = NULL;

    // cant equip mull material
    me->equip(tmp);

    // equip 'ice'
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // equip 'cure'
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    //test leqrning too muchmaterial
    for(int a = 0; a < 12; a++)
    {
        src->learnMateria(new Ice());
    }
    // test = operator
    AMateria *ae = (tmp);
    std::cout << "- TESTING: " << ae->getType() << std::endl;
   
    ICharacter *cc = (me);
    std::cout << "Character: '" << cc->getName() << "' vs '" << me->getName() << "' "<< std::endl;
    // test character constructor 
    delete bob;
    delete me;
    delete src;
    return 0;
}