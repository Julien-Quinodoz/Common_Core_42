/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:39:02 by jquinodo          #+#    #+#             */
/*   Updated: 2025/10/20 20:01:16 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(void)		{}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe(void)		{}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &src)	{
	(void)src; // rien à copier  - évite le warning
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>	& PmergeMe<T, Container>::operator = (const PmergeMe<T, Container> &src)	{
	(void)src; // pas besoin de copier quoi que ce soit - évite le warning
	return *this;
}







/*  Allocation de mémoire :
  std::vector possède la méthode .reserve(). elle permettent d'allouer de la mémoire à l’avance pour éviter de réallouer à chaque push_back
  Mais --> deque n’a pas la  méthode ** reserve ** */
template <typename T>
bool reserve(T &container, typename T::size_type size)			// Cette version est attrapée par défaut pour tous les types qui ne correspondent pas à vector (Evite les warnings)
{
	(void) container; 			// éviter les warnings
	(void) size;
	return false;				// rien n'est fait
}

template <typename T, typename U>								// Cette version est appelée uniquement si ton conteneur est un std::vector. Ell appelle réellement la méthode .reserve(size)
bool reserve(std::vector<T, U> &container, typename std::vector<T, U>::size_type size)
{
	container.reserve(size);									//.reserve existe pour vector mais pas pour deque .
	return true;
}

// ---------------------------
// Fusion de deux containers de paires déja trié !
// ---------------------------
template<typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<std::pair<T, T> > >

merge(const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &left,
	  const Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > &right)
{
	 Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > result; 	//nouveau conteneur de paire

	reserve(result, left.size() + right.size());  							// aloue l'espace pour result

	size_t i = 0; // indice pour parcourir left
	size_t j = 0; // indice pour parcourir right
	while (i < left.size() && j < right.size())			// Parcours simultané des deux containers
	{
		if (left[i].first < right[j].first)				// compare les 2 premiers de la paire
			result.push_back(left[i++]); 				// ajoute left[i] puis incrémente i
		else
			result.push_back(right[j++]); 				// ajoute right[j] puis incrémente j
	}
														// Ajoute les éléments restants ; liste déjà trié donc ok !
	while (i <  left.size()) result.push_back(left[i++]);
	while (j < right.size()) result.push_back(right[j++]);

	return result;
}

// ---------------------------
// Tri récursif des paires : resultat , 2 listes (premier et deuxième) les 2 triées
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

	// Tri récursif et fusion fiste trié et second trié
	return merge(sort_pairs(first), sort_pairs(second));
}

/* ================================================================
** 	Illustration — Insertion binaire
** ---------------------------------------------------------------
** Objectif :
**   Insérer un élément dans un container déjà trié
**   en gardant l’ordre, grâce à une recherche binaire.
**
** Exemple :
**     tab = [1, 3, 5, 7, 9]
**     item = 6
**
** Étapes de la recherche :
**
**   Initialisation :
**       left = 0
**       right = 5   (taille du container)
**
**   ┌───────────────────────────────┐
**   │   [1]   [3]   [5]   [7]   [9] │
**   │    0     1     2     3     4  │
**   └───────────────────────────────┘
**          ↑ mid = 2  → tab[mid] = 5
**
**   (5 < 6) → l’élément doit aller à droite :
**       left = mid + 1 = 3
**
**   Nouvelle zone de recherche : on recommence le processus plusieurs fois — tant qu’on n’a pas trouvé la bonne place.
**       [7]   [9]
**        3     4
**        ↑ mid = 3  → tab[mid] = 7
**
**   (7 < 6) X → l’élément doit aller à gauche :
**       right = mid = 3
**
**   Fin : left == right == 3
**
**   → Position d’insertion = 3
**
**   Insertion :
**       tab.insert(tab.begin() + 3, 6);
**
** Résultat :
**       [1, 3, 5, 6, 7, 9]
**
** Remarque :
**   Le paramètre 'start' permet de débuter la recherche
**   à partir d’un certain index (utile dans le tri par paires).
================================================================ */
template<typename T, template <typename, typename> class Container>
void binary_search_insertion(Container<T, std::allocator<T> > &tab, size_t start, T item)
{
	size_t left = start;						// on initialise la zone de recherche :
	size_t right = tab.size();					// on va chercher entre start (inclus) et tab.size() (exclu).
	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (tab[mid] < item)
			left = mid + 1;
		else
			right = mid;
	}
	tab.insert(tab.begin() + left, item); 	// On insère l’élément à l’endroit trouvé, et la structure reste triée.
}

// ---------------------------
// Tri Merge-Insertion principal
// ---------------------------
template<typename T, template <typename, typename> class Container>				// déclares d'une fonction membre de classe template
Container<T, std::allocator<T> >												// Création du conteneur  (ex : std::vector<int> ou std::deque<int>)
PmergeMe<T, Container>::sort(const Container<T, std::allocator<T> > &tab) const // fonction sort  appartient à la classe template PmergeMe
{
	if (tab.size() < 2)
		return tab;

	bool is_odd = tab.size() % 2 != 0;										// Vérifie si nombre de nombres est impair


	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs;	// 1. Créer des paires d'éléments dans pairs

	reserve(pairs, tab.size()/2 + 1);										// réserve la memoire necessaire pour std::vector /2 car par paire / + 1 pour une liste impaire

	for (size_t i = 0; i + 1 < tab.size(); i += 2)							// + 2 pour former les paires
	{
		if (tab[i] > tab[i+1])												//  2.  trie local le premier nombre de la paire avant make_paire
			pairs.push_back(std::make_pair(tab[i+1], tab[i]));
		else
			pairs.push_back(std::make_pair(tab[i], tab[i+1]));
	}
	Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs_sorted = sort_pairs(pairs); // 3. Tri récursif des paires (trier par le premier nombre de la paire ) /////////

	Container<T, std::allocator<T> > sorted;								// 4. Construction du tableau trié

	reserve(sorted, tab.size());

	for (size_t i = 0; i < pairs_sorted.size(); ++i)						// remplissage de sorted les first  des paires en premier
		sorted.push_back(pairs_sorted[i].first);

	if (is_odd)																// 5️ Insertion du dernier élément impair (7) :
		binary_search_insertion(sorted, 0, tab.back());
    {																		// 6️ Insertion des seconds éléments des paires : ordre Jacobsthal (Ford–Johnson)
		// Séquence de Jacobsthal et ordre d'insertion (Ford–Johnson)
		// La suite commence par 0 et 1, puis chaque terme est obtenu en ajoutant le nombre précédent à deux fois le nombre anté-précédent.
		// exemple : 0, 1, 1, 3, 5, 11, 21, 43, ...     : 11 = 5 + (2*3)  : 21 = (11 + (2*5) ... )
		// ----------------------------------------------------------
		// • Objectif: déterminer l'ordre optimal pour insérer les "seconds" des paires
		//   dans la chaîne des "first" afin de limiter le nombre de comparaisons.
		// • Principe: on délimite des blocs par les nombres de Jacobsthal, puis pour
		//   chaque bloc on insère les indices en ordre décroissant (J_k-1 .. J_{k-1}).
		//   Chaque insertion utilise une recherche binaire dans la chaîne déjà triée.

		std::vector<size_t> jac;
		jac.push_back(0);
		jac.push_back(1);												// La suite commence toujours par 0 & 1
		while (jac.back() < pairs_sorted.size())						// construction de la suite de Jacobsthal
			jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);	// ex: 0, 1, 1+2*0=1, 1+2*1=3, 3+2*1=5, 5+2*3=11, ...

		std::vector<size_t> order;
		size_t last = 0;
		for (size_t b = 1; b < jac.size(); ++b)								// boucle pour transformer la suite de Jacobsthal en ordre réel d’insertion
		{
			size_t bound = jac[b];											// bound = borne supérieure d’un segment d’indices donné par la suite Jacobsthal.
			if (bound > pairs_sorted.size()) bound = pairs_sorted.size();	// si la borne dépasse la taille du container, on la met à la taille du container
			if (bound <= last) continue;									// si la borne est inférieure ou égale à l’indice précédent, on passe au bloc suivant
			for (size_t k = bound; k > last; --k) order.push_back(k - 1);	// on insère les indices en ordre décroissant
			last = bound;													// on met à jour l’indice précédent
			if (last == pairs_sorted.size()) break;							// si l’indice précédent est égal à la taille du container, on arrête la boucle
		}

		// Application: pour chaque indice p, on insère le "second" correspondant
		// à partir de p+1 (les "first" remplissent les premières positions).
		// L'insertion binaire maintient l'ordre et limite les comparaisons.
		for (size_t idx = 0; idx < order.size(); ++idx)
		{
			size_t p = order[idx];
			binary_search_insertion(sorted, p + 1, pairs_sorted[p].second);
		}
	}

	return sorted;															//  -> Résultat final : [1, 2, 3, 5, 7, 8, 9]
}
/* ================================================================
** 	 Exemple visuel — Tri Merge-Insertion (cas impair)
** ----------------------------------------------------
** Entrée :
**     [5, 2, 8, 1, 9, 3, 7]
**     ↑                ↑
**     └────── 7 éléments → nombre impair
**
** Étapes :
**
** 1️ Formation des paires :
**     [5,2]   [8,1]   [9,3]   [7] ← dernier élément seul
**
** 2️ Tri local dans chaque paire :
**     (2,5)   (1,8)   (3,9)
**
** 3️ Tri récursif par premier élément :
**     Premiers = [2,1,3]  →  Trié → [1,2,3]
**
**     ↳ Paires réordonnées :
**         (1,8)   (2,5)   (3,9)
**
** 4️ Construction du tableau trié (base) :
**     [1, 2, 3]
**
** 5️ Insertion du dernier élément impair (7) :
**     → insertion binaire → [1, 2, 3, 7]
**
** 6️ Insertion des seconds éléments des paires :
**     +8 → [1, 2, 3, 7, 8]
**     +5 → [1, 2, 3, 5, 7, 8]
**     +9 → [1, 2, 3, 5, 7, 8, 9]
**
** -> Résultat final :
**     [1, 2, 3, 5, 7, 8, 9]
**
** - Chaque paire est triée localement avant fusion.
** - Les premiers éléments sont triés récursivement → structure de base.
** - Les seconds éléments et le dernier élément impair sont insérés par recherche binaire.
================================================================ */