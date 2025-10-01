/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:08:30 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/03 10:11:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template<typename T>

typename T::iterator easyfind(T &liste, int nb) // retourne un itérateur; curseur au niveau de l élément
{
	typename T::iterator res;
	res = std::find(liste.begin(), liste.end(), nb); //find chercher un élément dans une plage donnée (entre deux itérateurs) et renvoie l'iterateur dessus si trouvé.
													// renvoie : liste.end() ;  un itérateur spécial qui pointe juste après le dernier élément si rien trouvé
	return res;
}