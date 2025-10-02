# Cub3D ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/cub3dm.png)</a>

> Projet de l'école 42 — créer un petit jeu 3D en C à la manière de Wolfenstein 3D.
## Collaboration

Réalisé en collaboration avec **[Rodrigo Tari Carderera](https://github.com/Rodrigotari1)**

---

## 🎯 Objectif pédagogique

Le projet **Cub3D** a pour but de se familiariser avec la **programmation graphique 3D** et le **raycasting** en C :
- implémentation d’un moteur 3D simple avec **MiniLibX**,
- gestion de l’affichage de textures et sprites,
- manipulation des cartes 2D pour générer une perspective 3D,
- gestion des mouvements du joueur et collisions,
- compréhension des bases de la 3D et des transformations géométriques.

---

## 📚 Contenu du projet

- `cub3d.c` → boucle principale et initialisation du jeu.
- `render.c` → moteur de raycasting et affichage 3D.
- `input.c` → gestion des déplacements du joueur.
- `map.c` → lecture et validation des cartes.
- `textures/` → fichiers XPM pour les murs et objets.
- `cub3d.h` → header principal.
- `Makefile` → compilation et gestion des dépendances.

---

## 🧩 Fonctionnalités

- Lecture et validation de fichiers de carte `.cub`.
- Déplacement du joueur (`W`, `A`, `S`, `D`) avec collisions.
- Affichage 3D en raycasting avec textures murales.
- Gestion des sprites et objets dans le jeu.
- Minimisation des artefacts visuels et optimisation du rendu.

---

## 🧠 Compétences développées

- Programmation graphique avec **MiniLibX**
- Concepts de **raycasting et moteur 3D**
- Gestion des entrées clavier et collisions
- Manipulation de cartes 2D pour simulation 3D
- Structuration d’un projet graphique complexe en C

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
