/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:20:32 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 09:39:36 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

Form::Form(void) : _name("anonym"), _signGrade(HIGHT_GRADE), _execGrade(HIGHT_GRADE)
{
	this->_isSigned = false;
}

Form::~Form(void)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if(signGrade < HIGHT_GRADE || execGrade < HIGHT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > LOW_GRADE || execGrade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(const Form &src) : _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

Form	&Form::operator =(const Form &src)
{
	if (this != &src)
	{
		this->_isSigned = src.isSigned();
	}
	return *this;
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::isSigned(void) const
{
	return this->_isSigned;
}

int	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void	Form::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return (R "❌ Le grade est trop haut pour ce formulaire ❌ \n" E);
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return (R "❌ Le grade est trop bas pour ce formulaire ❌ \n" E);
}

std::ostream	&operator <<(std::ostream &o, const Form &form)
{
	o << V "==========================================" E<< std::endl;
	o << V "|| Form:\t" B << form.getName() 							<< V "\t\t\t||" E << std::endl;
	o << V "||\tSigned:\t\t\t" << form.isSigned() 					<< V "\t||" E << std::endl;
	o << V "||\tGrade to sign:\t\t" << form.getSignGrade()			<< V "\t||" E << std::endl;
	o << V "||\tGrade to execute:\t" << form.getExecGrade()			<< V "\t||" E << std::endl;
	o << V "==========================================" E				<< std::endl;

	return o;
}

