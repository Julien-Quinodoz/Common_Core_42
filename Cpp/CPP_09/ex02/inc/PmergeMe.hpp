/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:38:17 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/14 18:20:44 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_H
# define PMERGEME_CLASS_H

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>

# define B "\033[38;5;75m"
# define V "\033[38;5;177m"
# define J "\033[38;5;220m"
# define R "\033[38;5;203m"
# define G "\033[38;5;118m"
# define E "\033[0m"

template<typename T, template <typename, typename> class Container>
/*       └──────┬─────┘ └──────────────┬────────────────────────┘
                │                      │
         Type des éléments      Template de conteneur
         (int, float...)        (vector, deque, list...)
                │                      │
                └──────────┬───────────┘
                           │
                    Combinaison
                           ↓
              Container<T, std::allocator<T>>
              → vector<int, allocator<int>> */

class PmergeMe {
	public:
		 PmergeMe<T, Container>(void);
		~PmergeMe<T, Container>(void);
		PmergeMe<T, Container>(const PmergeMe<T, Container> &src);
		PmergeMe<T, Container>	&operator =(const PmergeMe<T, Container> &src);

	Container<T, std::allocator<T> > sort(const Container<T, std::allocator<T> > &tab) const;
};

# include "../src/PmergeMe.tpp"

#endif