# Minitalk ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/minitalkm.png)</a>

> Projet de l'école 42 — communication entre processus via signaux en C.

---

## 🎯 Objectif pédagogique

Le projet **Minitalk** consiste à créer un petit programme de communication **client/serveur** en C utilisant les **signaux UNIX**.
Il permet de travailler sur :
- la gestion des signaux (`SIGUSR1`, `SIGUSR2`)
- la communication entre processus
- la conversion et manipulation de données binaires
- la rigueur dans le contrôle des erreurs et la robustesse du code

---

## 📚 Contenu du projet

- `server.c` → programme serveur qui reçoit les messages et les affiche.
- `client.c` → programme client qui envoie un message au serveur via signaux.
- `minitalk.h` → header contenant les prototypes et macros nécessaires.

### Fonctionnement

- Le client envoie un **message texte** au serveur, caractère par caractère.
- Chaque bit d’un caractère est transmis via un signal (`SIGUSR1` pour 0, `SIGUSR2` pour 1).
- Le serveur reconstruit le message et l’affiche dans la console.

---

## 🧠 Compétences développées

- Gestion des **signaux UNIX** (`signal.h`)
- Communication inter-processus (IPC)
- Manipulation de bits et conversion binaire/ASCII
- Gestion des erreurs et robustesse du code
- Programmation C avancée et structuration de projets

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
