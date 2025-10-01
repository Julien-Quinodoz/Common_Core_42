/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:58:39 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 09:47:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

AForm::AForm(void) : _name("Unnamed"), _signGrade(HIGHT_GRADE), _execGrade(HIGHT_GRADE)
{
	this->_isSigned = false;
}

AForm::~AForm(void)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if(signGrade < HIGHT_GRADE || execGrade < HIGHT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > LOW_GRADE || execGrade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(const AForm &src) : _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

AForm	&AForm::operator =(const AForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src.isSigned();
	}
	return *this;
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::isSigned(void) const
{
	return this->_isSigned;
}

int	AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int	AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

void	AForm::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	else if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	else
		this->beExecuted();
}


const char* AForm::GradeTooHighException::what(void) const throw()
{
	return (R "le grade est trop haut pour ce formulaire  " E);
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return (R "le grade est trop bas pour ce formulaire  " E);
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return (R "le formulaire n'a pas été signé " E);
}

std::ostream	&operator <<(std::ostream &o, const AForm &form)
{
	o << V "==========================================" E<< std::endl;
	o << V "|| Form:\t" B << form.getName() 							<< V"\t||" E << std::endl;
	o << V "||\tSigned:\t\t\t" << form.isSigned() 					<< V"\t||" E << std::endl;
	o << V "||\tGrade to sign:\t\t" << form.getSignGrade()			<< V"\t||" E << std::endl;
	o << V "||\tGrade to execute:\t" << form.getExecGrade()			<< V"\t||" E << std::endl;
	o << V "==========================================" E				<< std::endl;

	return o;
}

