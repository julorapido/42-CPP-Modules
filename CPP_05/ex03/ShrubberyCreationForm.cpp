/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:27:14 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:47 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm():
    Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
    Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << 
        this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;

	*this = src;
}

// Deconstructors
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

static void createShrubberyFile(const std::string& target)
{
    // Construct the filename using the target
    std::string filename = target + "_shrubbery";

    // Open the file in write mode
    std::ofstream outfile(filename.c_str());
    
    // Check if the file is successfully opened
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Write ASCII trees to the file
    outfile << "    ^   " << std::endl;
    outfile << "   ^^^  " << std::endl;
    outfile << "  ^^^^^ " << std::endl;
    outfile << " ^^^^^^^" << std::endl;
    outfile << "^^^^^^^^^" << std::endl;
    outfile << "   ||   " << std::endl;
    
    // Close the file
    outfile.close();

    std::cout << "\033[33m File created: " << filename << "! (ASCII TREE)\033[0m" << std::endl;
}

// Public Methods
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getRequiredGradeExec())
		throw (Bureaucrat::TooLowException());
	else if (this->getIsSignedBool() == false)
		throw (Form::FormNotSignedException());
	else
    {
        // ASCII TREE
        createShrubberyFile(this->_target);
    }
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}


// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getRequiredGradeSign() <<
	"\n\texec-grade:\t" << a->getRequiredGradeExec() <<
	"\n\tis signed:\t" << a->getIsSignedBool() <<
	std::endl;
	return (o);
}