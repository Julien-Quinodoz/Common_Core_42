# Born2BeRoot ![42 Badge](https://github.com/Julien-Quinodoz/42-project-badges/blob/main/badges/born2berootm.png)</a>

> Projet de l'école 42 — découvrir et sécuriser un serveur Linux.

---

## 🎯 Objectif pédagogique

Le projet **Born2BeRoot** a pour but de te familiariser avec les **fondamentaux de l’administration système** à travers la **mise en place d’une machine virtuelle Linux** sécurisée.

Il permet de travailler sur :

- l’installation et la configuration d’une **machine virtuelle** (Debian ou Rocky Linux),  
- la gestion des **utilisateurs**, **groupes** et **droits sudo**,  
- la configuration de **SSH** et des **pare-feux (UFW)**,  
- la mise en place de **politiques de sécurité** (mots de passe, sudo, etc.),  
- la surveillance du système via un **script de monitoring**.  

---

## 📚 Contenu du projet

- Configuration des utilisateurs et groupes.
- Gestion des permissions et droits sudo.
- Installation et configuration de services comme :
  - SSH
  - FTP (vsftpd ou autre)
  - Serveur web (NGINX ou Apache)
- Configuration du firewall (ufw/iptables).
- Sécurisation de base du serveur.

---

## 🧠 Compétences développées

- Administration Linux (Ubuntu / Debian)
- Gestion des utilisateurs et groupes
- Sécurisation et configuration réseau
- Installation et configuration de services critiques
- Automatisation et scripts shell
- Gestion des logs et monitoring

---

## ⚙️ Mise en place & Utilisation

### Pré-requis

- Machine virtuelle Linux (Ubuntu/Debian) ou serveur physique.
- Accès root ou sudo.

### Étapes principales

1. **Mettre à jour le serveur** :

```bash
sudo apt update && sudo apt upgrade -y
