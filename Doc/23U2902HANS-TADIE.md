Nom : TADIE FEZE HANS MAVIN
Matricule : 23U2902

■ Contributions

Réalisation de tests approfondis sur l’ensemble des fonctionnalités du programme afin de garantir leur bon fonctionnement.

Correction des bugs identifiés lors des phases de test.

Rédaction et implémentation du programme principal (main), permettant l’interaction entre les différentes fonctions à travers des commandes saisies par l’utilisateur.

●Description du projet

Ce projet consiste à développer un programme en langage C capable de manipuler et de traiter des fichiers PPM (Portable Pixmap).
Le programme implémente plusieurs fonctionnalités permettant de :

Charger un fichier image PPM valide ;

Appliquer diverses transformations ou traitements ;

Sauvegarder les résultats ;

Interagir avec l’utilisateur à travers une interface en ligne de commande.

L’objectif principal est d’assurer la fiabilité et la robustesse du code tout en garantissant une bonne expérience d’utilisation.

■ Instructions d’utilisation

1. Compilation du programme

gcc -o programme main.c fonctions.c -lm


2. Exécution du programme

./programme


3. Utilisation des commandes
Après le chargement d’un fichier PPM valide, entrez les commandes suivantes pour tester les fonctionnalités :

charger <nom_fichier.ppm> : charge une image PPM.

afficher : affiche les informations de l’image chargée.

traiter : applique un traitement (selon les fonctions disponibles).

sauvegarder <nouveau_nom.ppm> : enregistre les modifications.

quitter : termine 

■Tests et validation

Des tests unitaires et fonctionnels ont été effectués sur chaque module du projet afin de :

Vérifier la cohérence des entrées et sorties ;

Détecter et corriger les anomalies ;

Valider le bon fonctionnement du programme global.

Tous les tests ont permis d’obtenir une version stable et fonctionnelle du projet.

■ Remarques

Le programme est écrit en C standard (C99).

Une attention particulière a été portée à la gestion de la mémoire et au contrôle des erreurs.

Le code est structuré et commenté pour en faciliter la compréhension et la maintenance.
