# Philosophers ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/philosopherse.png)</a>

> Projet de l'école 42 — résoudre le problème des philosophes en C avec les threads et la synchronisation.

---

## 🎯 Objectif pédagogique

Le projet **Philosophers** consiste à implémenter le célèbre **problème des philosophes** pour pratiquer :
- la **programmation concurrente** avec **threads** (`pthread`),
- la **synchronisation** via mutex, sémaphores ou autres mécanismes,
- la **gestion des ressources partagées** (fourchettes) sans provoquer de **deadlock** ou d’**étoilement**.

Il permet de comprendre le comportement des systèmes multitâches et d’appliquer les concepts de sécurité et de coordination des threads.

---

## 📚 Contenu du projet

- `philosophers.c` → fonction principale et création des threads.
- `philosophers_utils.c` → fonctions utilitaires (affichage, temporisation, contrôle de l’état).
- `philosophers.h` → header contenant prototypes, structures et macros.
- `Makefile` → compilation du projet.

### Fonctionnement

- Les philosophes alternent entre **penser**, **manger** et **dormir**.
- Chaque philosophe doit **prendre deux fourchettes** pour manger.
- Le programme doit éviter :
  - **Deadlock** (tous les philosophes bloqués)
  - **Étoilement** (un philosophe jamais servi)

---

## 🧠 Compétences développées

- Programmation concurrente avec **pthread**
- Synchronisation avec **mutex** ou **sémaphores**
- Gestion de **l’affichage concurrent** (éviter les collisions sur stdout)
- Analyse et prévention des **conditions de course**
- Structuration d’un projet multitâches robuste

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
