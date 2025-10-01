/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:58:52 by jquinodo          #+#    #+#             */
/*   Updated: 2025/07/09 10:36:39 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target("Untargeted")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(src._target)
{
	*this = src;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &src)
{
	(void)src;
	return *this;
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	file;
	std::string		filename = this->_target + "_shrubbery";

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.open(filename.c_str());
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file.close();
}
