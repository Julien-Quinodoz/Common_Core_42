# NetPractice ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/netpracticem.png)</a>

> Projet de l'école 42 — découvrir les concepts réseau en C.

---

## 🎯 Objectif pédagogique

Le projet **NetPractice** a pour but de se familiariser avec la **programmation réseau** et les **protocoles TCP/UDP** en C :
- création de **clients et serveurs** simples,
- gestion des **sockets**, connexions et transmissions de données,
- utilisation des fonctions réseau standard (`socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, `recv()`),
- compréhension des bases de la communication réseau et de la synchronisation.

---

## 📚 Contenu du projet

- `server.c` → serveur simple capable de recevoir et envoyer des données.
- `client.c` → client capable de se connecter au serveur et échanger des messages.
- `netpractice.h` → header avec prototypes et macros.
- `Makefile` → compilation et gestion des dépendances.

### Fonctionnement

- Le **serveur** écoute sur un port spécifique et attend les connexions des clients.
- Le **client** se connecte au serveur et peut envoyer des messages.
- Les messages sont affichés côté serveur et/ou client selon le projet.

---

## 🧠 Compétences développées

- Programmation réseau avec **sockets TCP/UDP**
- Gestion des connexions et des flux de données
- Utilisation des fonctions système réseau sous Unix
- Gestion des erreurs et robustesse du code
- Mise en place de protocoles simples de communication

---

## ⚙️ Compilation & Utilisation

### Compilation

```bash
make
