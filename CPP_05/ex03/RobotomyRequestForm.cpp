/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:27:14 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 15:41:14 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include <bits/stdc++.h>

// Constructors
RobotomyRequestForm::RobotomyRequestForm():
    Form("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
    Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor for target " << 
        this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): Form("RobotomyRequestForm", 25, 5), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;

	*this = src;
}

// Deconstructors
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

// Public Methods
void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getRequiredGradeExec())
		throw (Bureaucrat::TooLowException());
	else if (this->getIsSignedBool() == false)
		throw (Form::FormNotSignedException());
	else
    {
        std::cout << "\033[33mbrrrrrrrrrrrrrrrrrrrrrrrrrrrrr!!!! \033[0m" << std::endl;
        std::srand(static_cast<unsigned int>(std::time(0)));
        int randomValue = std::rand() % 2;
        std::cout << "Random value: " << randomValue << std::endl;
        if((randomValue) == 1)
            std::cout << "\033[31m The robotomy failed. \033[0m" << std::endl;
        else
            std::cout << "\033[32m The robotomy was a SUCCESS ! \033[0m" << std::endl;
    }
}

// Getter
std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}


// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getRequiredGradeSign() <<
	"\n\texec-grade:\t" << a->getRequiredGradeExec() <<
	"\n\tis signed:\t" << a->getIsSignedBool() <<
	std::endl;
	return (o);
}