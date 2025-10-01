# ft_printf ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/ft_printfe.png)</a>

> Projet de l'école 42 — réimplémenter la fonction printf en C.

---

## 🎯 Objectif pédagogique

Le projet **ft_printf** a pour but de réécrire la célèbre fonction `printf` en C.
Il permet de travailler sur :
- l’interprétation et le traitement des **spécificateurs de format** (`%d`, `%s`, `%x`, etc.),
- la manipulation de **va_list** pour les arguments variables,
- la gestion de chaînes et de nombres en mémoire dynamique,
- la rigueur dans le respect des contraintes de style et de fonctionnement.

---

## 📚 Contenu du projet

- `ft_printf.c` → fonction principale `ft_printf()`.
- `ft_printf_utils.c` → fonctions utilitaires pour convertir et afficher les différents types.
- `ft_printf.h` → header contenant les prototypes et macros nécessaires.

### Spécificateurs supportés

- `%c` → caractère
- `%s` → chaîne de caractères
- `%p` → pointeur
- `%d` / `%i` → entier signé
- `%u` → entier non signé
- `%x` / `%X` → entier hexadécimal
- `%%` → caractère `%`

---

## 🧠 Compétences développées

- Gestion des arguments variadiques (`stdarg.h`)
- Manipulation de chaînes et conversion de types
- Rigueur et modularité dans la programmation
- Gestion des cas limites et erreurs
- Création d’une fonction réutilisable et testable

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
gcc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c main.c -o test_printf
