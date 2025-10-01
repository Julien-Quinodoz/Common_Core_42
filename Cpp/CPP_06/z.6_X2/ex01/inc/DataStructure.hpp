/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStructure.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:03:54 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/03 14:15:17 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASTRUCTURE_HPP
# define DATASTRUCTURE_HPP

#include <string>
#include <vector>

struct Data
{
    int num;
    double doub;
    std::string str;
    std::vector<int> list;
    bool isTested;
};

#endif
