/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:49:31 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 16:31:13 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat::Bureaucrat()
{
    this->_name = "Default Bureaucrat.";
    this->_grade = 150;
    std::cout << "New Bureaucrat!" << std::endl;

}

Bureaucrat::Bureaucrat(std::string const &n)
{
    this->_name = n;
    this->_grade = 150;
    std::cout << "New Bureaucrat! (named: " << n << ")" << std::endl;
}
Bureaucrat::Bureaucrat(unsigned int n)
{
    try
    {
        /* code */
        if(n > 150)
            throw TooHighException();
        if(n < 1)
            throw TooLowException();
        this->_grade = (n);
        this->_name = "N-Bureaucrat!";
        std::cout << "New Bureaucrat! (grade: " << n << ")" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "\033[03 Caught exception: " << e.what() << std::endl;
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    this->_name = copy.getName();
    this->_grade = copy.getGrade();
    std::cout << "New Bureaucrat!" << std::endl;
}

void    Bureaucrat::executeForm(Form const & form)
{
    Form const &baseRef = form;  // Base reference to form object
    if(form.getRequiredGradeSign() == 145)
    {
        ShrubberyCreationForm const & A_A = static_cast<ShrubberyCreationForm const &>(baseRef);
        (A_A).execute(*this);
    }
    if(form.getRequiredGradeSign() == 72)
    {
        RobotomyRequestForm const & A_A = static_cast<RobotomyRequestForm const &>(baseRef);
        (A_A).execute(*this);
    }
    if(form.getRequiredGradeSign() == 25)
    {
        PresidentialPardonForm const & A_A = static_cast<PresidentialPardonForm const &>(baseRef);
        (A_A).execute(*this);
    }

}


Bureaucrat::~Bureaucrat()
{
    std::cout << "bye bye Bureaucrat!" << std::endl;
}
std::string     Bureaucrat::getName(void) const
{
    return (this->_name);
}

unsigned int    Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(void)
{
    try
    {
        if(this->_grade - 1 < 1)
        {
            throw TooHighException();  // Throw an instance of MyException
        }else
            this->_grade -= 1;
    }
    catch (std::exception & e)
    {
        std::cout << "\033[03 Caught exception: " << e.what() << std::endl;
    }
}


void    Bureaucrat::decrementGrade(void)
{
    try
    {
        // std::cout << "frere" << this->_grade << " - " << 1 << std::endl;
        if(this->_grade + 1 > 150)
        {
            throw TooLowException();  // Throw an instance of MyException
        }else
            this->_grade += 1;
    }
    catch (std::exception & e)
    {
        std::cout << "\033[03 Caught exception: " << e.what() << std::endl;
    }
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw TooLowException();
	else if (grade < 1)
		throw TooHighException();
	else
		this->_grade = grade;
}


// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}