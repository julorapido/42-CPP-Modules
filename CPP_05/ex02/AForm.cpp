/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:10:12 by jsaintho          #+#    #+#             */
/*   Updated: 2025/02/03 16:06:21 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

// Constructors
Form::Form(void): _name("default"), _signed(false), _required_grade_sign(150), _required_grade_exec(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _signed(false), _required_grade_sign(src.getRequiredGradeSign()), _required_grade_exec(src.getRequiredGradeExec())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _signed(false), _required_grade_sign(sign_grade), _required_grade_exec(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getRequiredGradeSign();
	const int j = this->getRequiredGradeExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): _name(name), _signed(false), _required_grade_sign(150), _required_grade_exec(150)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getRequiredGradeSign() <<
	" and execution-grade of " << this->getRequiredGradeExec() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _required_grade_sign(sign_grade), _required_grade_exec(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getRequiredGradeSign();
	const int j = this->getRequiredGradeExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

// Deconstructors
Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	//nothing to assign in this class
	return *this;
}

// Public Methods
void Form::beSigned(Bureaucrat &signer)
{
	if ((unsigned int)signer.getGrade() > this->getRequiredGradeSign())
		throw(Bureaucrat::TooLowException());
	else if (this->getIsSignedBool() == false)
	{
		this->_signed = true;
		signer.executeForm(*this);
		std::cout << " \033[32m" << this->getName() << " Form was signed by " << signer.getName() << "\033[0m" << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

// Getter
std::string	Form::getName(void)const
{
	return (this->_name);
}
void Form::execute(Bureaucrat const &executor)const
{
	(void)executor;
}
bool	Form::getIsSignedBool(void)const
{
	return (this->_signed);
}

unsigned int	Form::getRequiredGradeSign(void)const
{
	return (this->_required_grade_sign);
}

unsigned int    Form::getRequiredGradeExec(void)const
{
	return (this->_required_grade_exec);
}

// Exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getRequiredGradeSign() <<
	"\n\texec-grade:\t" << a->getRequiredGradeExec() <<
	"\n\tis signed:\t" << (a->getIsSignedBool() ? "signed." : "not signed." )<<
	std::endl;
	return (o);
}
