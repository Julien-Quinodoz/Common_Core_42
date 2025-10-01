/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:22:15 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 09:37:04 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

Bureaucrat::Bureaucrat(void): _name("anonym"), _grade(LOW_GRADE)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < HIGHT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName())
{
	*this = src;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;

}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < HIGHT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);

		std::cout << V "==> " E << this->_name << G " signed " E << form.getName() << V " <==\n" E << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << V"==> " E << this->_name << R " ne peut pas signer " E << form.getName() << R " ; le grade minimal est de " E << form.getSignGrade() << " ❌" << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (R "❌ Le grade doit être au minimum de 1 ❌" E);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (R "❌ Le grade est trop grand (max 150) ❌" E);
}

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << V "==> " E << bur.getName() << V", grade : " E << bur.getGrade() << V " <==" E;
	return o;
}
