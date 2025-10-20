# Push_swap ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/push_swapm.png)</a>

> Projet de l'école 42 — trier une pile d'entiers avec un nombre minimal d'opérations.

---
# 🧩 Push_swap  
![42 Badge](https://raw.githubusercontent.com/Julien-Quinodoz/42-project-badges/main/badges/push_swapm.png)

> Projet de l'école 42 — trier une pile d'entiers avec un nombre minimal d'opérations.

---

## 🎯 Objectif pédagogique

Le projet **Push_swap** consiste à créer un programme capable de **trier une pile d'entiers** en utilisant un **ensemble limité d'instructions**, tout en **minimisant le nombre total d’opérations** nécessaires.

Ce projet permet de travailler sur :

- la **manipulation de structures de données dynamiques** (piles et listes chaînées),  
- la **conception d’algorithmes efficaces** et leur optimisation,  
- la **gestion stricte de la mémoire** en C,  
- la **rigueur du code et la modularité** d’un projet structuré.  

---

## ⚙️ Contraintes et règles

- Le tri doit être réalisé à l’aide de **deux piles uniquement** :
  - **Pile A** : contient les entiers à trier.  
  - **Pile B** : pile auxiliaire utilisée pendant le tri.  

- Les **seules instructions autorisées** (et à coder soit même) sont :  

sa : swap a — échange les deux premiers éléments du stack a  
sb : swap b — échange les deux premiers éléments du stack b  
ss : sa et sb simultanément  
pa : push a — prend le premier élément de b et le place sur a  
pb : push b — prend le premier élément de a et le place sur b  
ra : rotate a — décale tous les éléments de a d’une position vers le haut  
rb : rotate b — idem pour b  
rr : ra et rb simultanément  
rra : reverse rotate a — décale tous les éléments de a d’une position vers le bas  
rrb : reverse rotate b — idem pour b  
rrr : rra et rrb simultanément  

- Aucune fonction de tri standard (`qsort`, `sort`, etc.) n’est autorisée.  
- L’algorithme doit être **entièrement implémenté à la main**, en respectant les contraintes du sujet.  
- Le programme doit être robuste face à des **entrées invalides** (doublons, caractères non numériques, etc.).

---

## 🔢 Optimisation du tri

Le défi principal du projet est de concevoir un **algorithme capable de trier efficacement la pile** en réduisant au maximum le nombre d’opérations.

Plusieurs stratégies peuvent être adoptées selon la taille du jeu de données :

- **Petites piles (≤ 5 éléments)** : approche basée sur un tri par insertion simple.  
- **Grandes piles** : algorithmes plus complexes comme :
- le **Radix Sort** (tri binaire par bits),  
- ou le **tri par chunks**, qui découpe la pile en sous-groupes de valeurs.

Des valeurs de référence existent pour évaluer les performances de ton programme :

| Taille de la pile | Nombre de mouvements attendu (ordre de grandeur) |
|:------------------:|:----------------------------------------------:|
| 3 | ≤ 3 |
| 5 | ≤ 12 |
| 100 | < 700 |
| 500 | < 5500 |

Ces chiffres ne sont pas obligatoires mais représentent une **cible d’efficacité réaliste** pour un bon algorithme.

---

# Exemples d’utilisation
./push_swap 3 2 5 1 4 34 -11 44 56 67 87 89 213 -54332 9 10 21



## 🧠 Compétences développées

Manipulation de piles et listes chaînées dynamiques

Conception d’un algorithme de tri personnalisé

Analyse et optimisation algorithmique

Gestion de la mémoire en C (malloc, free)

Application stricte de la norme 42 et d’une architecture modulaire


