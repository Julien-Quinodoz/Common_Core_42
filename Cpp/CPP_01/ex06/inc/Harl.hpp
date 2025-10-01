/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:50:19 by jquinodo          #+#    #+#             */
/*   Updated: 2025/04/17 19:38:23 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
# define Harl_HPP

# include <iostream>
# include <string>

class Harl
{
	private:

	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

	public:

	Harl(void);
	~Harl(void);

	void	complain(std::string level);

} ;

#endif