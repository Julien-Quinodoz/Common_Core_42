# Push_swap ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/push_swapm.png)</a>

> Projet de l'école 42 — trier une pile d'entiers avec un nombre minimal d'opérations.

---

## 🎯 Objectif pédagogique

Le projet **Push_swap** a pour but de créer un programme capable de **trier une pile d’entiers** en utilisant **un ensemble limité d’instructions**.
Il permet de travailler sur :
- la manipulation de **piles et listes chaînées**
- l’optimisation d’algorithmes pour minimiser le nombre d’opérations
- la rigueur dans la gestion de la mémoire
- la conception d’un programme modulaire et performant

---

## 📚 Contenu du projet

- `push_swap.c` → programme principal qui trie une pile d’entiers.
- `checker.c` → programme secondaire pour vérifier que les instructions produisent une pile triée.
- `utils.c` → fonctions utilitaires pour gérer les piles et opérations.
- `push_swap.h` → header contenant prototypes et structures nécessaires.

### Instructions autorisées

- `sa`, `sb`, `ss` → swap
- `pa`, `pb` → push
- `ra`, `rb`, `rr` → rotate
- `rra`, `rrb`, `rrr` → reverse rotate

---

## 🧠 Compétences développées

- Manipulation avancée de **listes chaînées**
- Optimisation d’algorithmes et réflexion sur complexité
- Gestion dynamique de la mémoire (`malloc`, `free`)
- Conception d’un programme **robuste et testable**
- Débogage et validation via des outils internes et externes

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
