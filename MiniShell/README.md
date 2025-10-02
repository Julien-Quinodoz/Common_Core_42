# Minishell ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/minishelle.png)</a>

> Projet de l'école 42 — créer un petit shell Unix minimaliste en C.
## Collaboration

Réalisé en collaboration avec **[Rodrigo Tari Carderera](https://github.com/Rodrigotari1)**

---

## 🎯 Objectif pédagogique

Le projet **Minishell** consiste à recréer un **shell simplifié** afin de comprendre le fonctionnement des systèmes Unix et de :
- gérer l’exécution de commandes internes et externes,
- travailler avec les **processus** (`fork`, `execve`),
- gérer la **redirection d’entrée/sortie** et les **pipes**,
- implémenter la gestion des **signaux** (`Ctrl+C`, `Ctrl+D`),
- construire un interpréteur de commandes fonctionnel et robuste.

---

## 📚 Contenu du projet

- `minishell.c` → boucle principale et parsing des commandes.
- `builtins.c` → commandes internes (`cd`, `echo`, `pwd`, `exit`, etc.).
- `execute.c` → gestion des forks, execve, redirections et pipes.
- `parser.c` → analyse lexicale et syntaxique des commandes.
- `minishell.h` → header contenant prototypes, structures et macros.
- `Makefile` → compilation et gestion des dépendances.

---

## 🧠 Compétences développées

- Gestion des **processus Unix** (`fork`, `wait`, `execve`)
- Gestion des **pipes et redirections**
- Programmation de commandes **internes**
- Gestion des **signaux et interruptions**
- Parsing de commandes et analyse syntaxique
- Structuration d’un projet complexe en C

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
