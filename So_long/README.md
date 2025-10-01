# So_long ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/so_longm.png)</a>

> Projet de l'école 42 — créer un petit jeu 2D en C avec la bibliothèque MiniLibX.

---

## 🎯 Objectif pédagogique

Le projet **So_long** a pour but d’introduire la **programmation graphique** en C à travers la création d’un **jeu 2D minimaliste**.
Il permet d’apprendre à :
- utiliser la **MiniLibX** pour l’affichage graphique,
- gérer les **événements clavier et fenêtre**,
- manipuler des **maps** et des **sprites**,
- structurer un projet de jeu complet et fonctionnel.

---

## 📚 Contenu du projet

- `so_long.c` → fonction principale du jeu.
- `map.c` → gestion de la carte et vérification de la validité du niveau.
- `render.c` → affichage du jeu et gestion des sprites.
- `input.c` → gestion des mouvements du joueur.
- `so_long.h` → header principal.
- `Makefile` → compilation et gestion des dépendances.

---

## 🧩 Règles du jeu

- Le joueur doit **collecter tous les objets (C)** avant d’atteindre la **sortie (E)**.
- Il se déplace sur une **carte composée de murs (1)** et de **cases vides (0)**.
- Le jeu se termine quand le joueur atteint la sortie après avoir ramassé tous les objets.
- La carte doit être **fermée** par des murs et contenir au moins :
  - 1 départ (`P`)
  - 1 sortie (`E`)
  - 1 objet (`C`)

---

## 🧠 Compétences développées

- Programmation graphique avec **MiniLibX**
- Gestion des **événements clavier et affichage**
- Manipulation de fichiers texte et parsing de cartes
- Organisation et structure d’un projet C complet
- Respect des normes et gestion mémoire (`valgrind` friendly)

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
