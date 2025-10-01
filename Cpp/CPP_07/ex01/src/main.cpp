/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:18:12 by jquinodo          #+#    #+#             */
/*   Updated: 2025/08/20 15:02:45 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "iter.hpp"

template < typename T >

void	print(T const & value)
{
	std::cout << J "--> " E << value << J " <--" E << std::endl;
}

int	main(void)
{
	int			int_arr[5] = {1, 2, 3, 4, 5};
	const int 	int_arr_2[3] = {6, 7, 8};

	std::cout << B "====== ARR INT ======" E << std::endl;
	iter(int_arr, 5, print<int>);

		std::cout << B "====== CONST ARR INT ======" E << std::endl;
	iter(int_arr_2, 3, print<int>);


	

	std::string	str_arr[4] = {"UN", "DEUX", "TROIS", "QUATRE"};

	std::cout << B "====== ARR STR ======" E << std::endl;
	iter(str_arr, 4, print<std::string>);




	std::cout << B "*********************" E << std::endl;
	return 0;
}