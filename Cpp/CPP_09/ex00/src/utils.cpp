/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:52 by jquinodo          #+#    #+#             */
/*   Updated: 2025/09/24 11:57:11 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>


void trim(std::string &str)
{
	const std::string whitespace = " \t";

	std::string::size_type start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)	// position invalide ou une absence de position.
	{
		str.clear();
		return;
	}
	std::string::size_type end = str.find_last_not_of(whitespace);
	str.assign(str.substr(start, end - start + 1));
}

// → une année est bissextile si elle est divisible par 4
// → sauf si elle est divisible par 100 (ex. 1900 n’est pas bissextile)
// → sauf si elle est divisible par 400 (ex. 2000 est bien bissextile)
static bool is_bissextile(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool check_date_format(std::string str)
{
	// Check la longeur du champ
	std::vector<char> buffer(str.size() + 1);		// Variante Taille dynamique, gestion automatique
	std::strcpy(buffer.data(), str.c_str());		// .c_str : retourne un pointeur constant qui pointe vers une chaîne de caractères terminée par un caractère null\0

	char *ptr;

	ptr = strtok(buffer.data(), "-");

	int i = 0;
	while (ptr != NULL)					/// boucle 3x:  yyyy - mm - dd
	{
		if (i == 0 && strlen(ptr) != 4)		//yyyy
			return false;
		else if (i > 0 && strlen(ptr) != 2)	//mm-dd
			return false;

		ptr = strtok(NULL, "-");		// avec strtok(NULL, "-"), strtok utilise une variable statique interne pour se souvenir de la position
		i++;
	}
	if (i != 3)
		return false;

	// Validation stricte des entrées année/mois/jour
	int y = 0, m = 0, d = 0;
	if (std::sscanf(str.c_str(), "%4d-%2d-%2d", &y, &m, &d) != 3)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1)
		return false;
	static const int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int dim = days_in_month[m - 1];
	if (m == 2 && is_bissextile(y))
		dim = 29;
	if (d > dim)
		return false;

	return true;
}

bool check_Value(std::string str)
{
	std::stringstream stream(str);		//créer un stream sur copie de str
	
	float f;

	if (!(stream >> f) || !stream.eof())
		return false;

	// Rejette les valeurs négatives ou nulles
	if (f <= 0.0f)
		return false;

	return true;
}

float str_to_float(std::string str)
{
	std::stringstream stream(str);
	float f;

	if (!(stream >> f) || !stream.eof())
		return -1;

	return f;
}

bool try_parse_float(const std::string &str, float &out)
{
	std::stringstream stream(str);
	if (!(stream >> out) || !stream.eof())
		return false;
	return true;
}
