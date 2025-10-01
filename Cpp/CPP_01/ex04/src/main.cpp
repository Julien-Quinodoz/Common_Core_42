/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:08:19 by jquinodo          #+#    #+#             */
/*   Updated: 2025/05/06 14:29:54 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include<cstdlib>

// lit un fichier texte et retourne son contenu en une seule chaîne.
std::string ft_read(char *fd)
{
	std::ifstream	File;			//input file Creer objet de classe ifstream pour utiliser ses métose open, eof, is_open, close
	std::string		res;
	std::string		line;

	File.open(fd);
	if(!File.is_open())
	{
		std::cout<<"Error open file <arg1>" << std::endl;
		exit (1);
	}
	else
	{
		while (!File.eof())
		{
			std::getline(File, line); //lit et copie File dans ligne; stop au \n ou eof  -- repart du même endroit après nouvelle appel
			res += line;
			if (!File.eof())			// rajoute \n si ce n'est pas eof
				res += '\n';
		}
	}
	File.close();
	return res;        //return qu'une string avec \n , prète a être lue et interpretée
}

//remplace toutes les occurrences d’un mot/texte dans cette chaîne et écrit le résultat dans un nouveau fichier.
void replace_str(std::string txt_line, std::string s1, std::string s2, std::string fd)
{
	std::ofstream outfile;					//outout file création d'un objet ofstream pour utiliser les metodes

	// outfile.open(fd + ".replace");
	outfile.open((fd + ".replace").c_str());		// .open() création du nouveau fichier avec sufix .replace ; Efface si il existe
	if (!outfile.is_open())
	{
		std::cout << "error to open file" << std::endl;
		exit (1);
	}
	std::size_t found_i = txt_line.find(s1);		// cherche la première occurrence de la chaîne s1 dans la chaîne txt_line et renvoie la position : found == 6.
	while(found_i != std::string::npos)							// Si s1 n'est pas trouvée → found contiendra npos (une valeur spéciale signifiant “pas trouvé”).
	{									//while found ; tant que npos n'est pas trouvé
		txt_line.erase(found_i, s1.length());		//suprime s1 de l'emplacement de txt_line (position found) le nombre de caractère de s1 (s1.len)
		txt_line.insert(found_i, s2);				//insert  s2 de l'emplacement de txt_line (position found) le nombre de caractère de s2 (s2.len)
		found_i = txt_line.find(s1, found_i + s2.length()); // recherche la prochaine position de S1 après la copie de s2 (found + s2.len) si ; Pour éviter de re-trouver la même zone (ex: si s1 est contenu dans s2
	}
	outfile << txt_line;							//copie txt_line dans outfile (nouveau fichier créer)
	outfile.close();
	return ;
}

int main(int ac, char **av)
{
	std::string str;

	if(ac != 4)
	{
		std::cout<<("./replace <filename> <search> <replacement>")<<std::endl;
		return 0;
	}
	else if(!av[1][0] || !av[2][0] || !av[3][0])
	{
		std::cout << "Invalid <arg>" << std::endl;
		return 0;
	}
	str = ft_read(av[1]);					//return qu'une string avec \n , prète a être lue et interpretée
	replace_str(str, av[2],av[3], av[1]);
	return 0;
}
