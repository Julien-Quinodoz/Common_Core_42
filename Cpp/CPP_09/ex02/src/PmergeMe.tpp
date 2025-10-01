/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:39:02 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/23 19:22:02 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(void)		{}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe(void)		{}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &src)
{
	(void)src; // rien à copier
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>	& PmergeMe<T, Container>::operator = (const PmergeMe<T, Container> &src)
{
	(void)src; // pas besoin de copier quoi que ce soit
	return *this;
}






// ---------------------------
// Réservation de mémoire
// ---------------------------

// std::vector permettent de réserver de la mémoire à l’avance pour éviter de réallouer à chaque push_back
//  Mais --> deque) n’a pas la  méthode ** reserve **

// Version générique : pour les containers qui n'ont pas  reserve() ex:  deque
template <typename T>
bool reserve(T &container, typename T::size_type size)
{
	(void) container; 			// éviter les warnings
	(void) size;
	return false;				// rien n'est fait
}

// Version spécifique pour std::vector : on réserve de la place à l'avance : performance (moins de reallocations).
template <typename T, typename U>
bool reserve(std::vector<T, U> &container, typename std::vector<T, U>::size_type size)
{
	container.reserve(size);
	return true;				// indique qu'on a réservé
}

// ---------------------------
// Fusion de deux containers de paires déja trié !
// ---------------------------
template<typename T, template <typename, typename> class Container>

Container<std::pair<T, T>, std::allocator<std::pair<T, T> > >

merge(const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &left,
	  const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &right)
{
	 Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > result; //nouveau conteneur de paire

	reserve(result, left.size() + right.size());  		// aloue l'espace pour result

	size_t i = 0; // indice pour parcourir left
	size_t j = 0; // indice pour parcourir right


	while (i < left.size() && j < right.size())			// Parcours simultané des deux containers
	{
		if (left[i].first < right[j].first)				// compare les 2 premiers de la paire
			result.push_back(left[i++]); 				// ajouter left[i] puis incrémenter i
		else
			result.push_back(right[j++]); 				// ajouter right[j] puis incrémenter j
	}

	 				// Ajouter les éléments restants ; liste déjà trié donc ok !
	while (i < left.size()) result.push_back(left[i++]);
	while (j < right.size()) result.push_back(right[j++]);

	return result;
}

// ---------------------------
// Tri récursif des paires
// ---------------------------
template<typename T, template <typename, typename> class Container>

Container<std::pair<T, T>, std::allocator<std::pair<T, T> > >

sort_pairs(const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &pairs)
{
	if (pairs.size() <= 1)
		return pairs;

	// Séparer les paires en deux sous-containers
	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > first;
	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > second;

	std::copy(pairs.begin(), pairs.begin() + pairs.size()/2, std::back_inserter(first));
	std::copy(pairs.begin() + pairs.size()/2, pairs.end(), std::back_inserter(second));

	// Tri récursif et fusion
	return merge(sort_pairs(first), sort_pairs(second));
}

// ---------------------------
// Insertion binaire d'un élément dans un container trié
// ---------------------------
template<typename T, template <typename, typename> class Container>

void binary_search_insertion(Container<T, std::allocator<T> > &array, size_t start, T item)
{
	size_t left = start;
	size_t right = array.size();

	// Recherche de la position d'insertion
	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (array[mid] < item)
			left = mid + 1;
		else
			right = mid;
	}

	// Insertion à la position trouvée
	array.insert(array.begin() + left, item);
}

// ---------------------------
// Tri Merge-Insertion principal
// ---------------------------
template<typename T, template <typename, typename> class Container>

Container<T, std::allocator<T> >

PmergeMe<T, Container>::sort(const Container<T, std::allocator<T> > &tab) const
{
	if (tab.size() < 2)
		return tab; 	// rien à trier

	// 1. Créer des paires d'éléments
	bool is_odd = tab.size() % 2 != 0;

	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs;

	reserve(pairs, tab.size()/2 + 1);		//réserve la memoire necessaire pour std::vector /2 car par paire / + 1 pour une liste impaire

	for (size_t i = 0; i + 1 < tab.size(); i += 2)		// + 2 pour former les paires
	{
		if (tab[i] > tab[i+1])							// trie la paire avant make_paire
			pairs.push_back(std::make_pair(tab[i+1], tab[i]));
		else
			pairs.push_back(std::make_pair(tab[i], tab[i+1]));
	}

	// 2. Tri récursif des paires (trier par le premier de la paire )
	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs_sorted = sort_pairs(pairs);

	// 3. Construction du tableau trié 
	Container<T, std::allocator<T> > sorted;

	reserve(sorted, tab.size());

	for (size_t i = 0; i < pairs_sorted.size(); ++i)
		sorted.push_back(pairs_sorted[i].first);

	// 4. Si le nombre d'éléments est impair, ajouter le dernier élément
	if (is_odd)
		binary_search_insertion(sorted, 0, tab.back());

	// 5. Insérer les seconds éléments des paires dans l'ordre optimal
	for (size_t i = 0; i < pairs_sorted.size(); ++i)
		binary_search_insertion(sorted, i+1, pairs_sorted[i].second);

	return sorted;
}
