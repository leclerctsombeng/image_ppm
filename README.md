
 
```markdown
# Traitement d'Images PPM

## Description

Ce projet a pour objectif de créer une application capable de manipuler des images au format PPM (Portable PixMap). Les principales fonctionnalités incluent l'ajustement de la luminosité, la conversion en niveaux de gris, la création de négatifs, la découpe d'images et l'application de filtres.

## Fonctionnalités

- **Affichage de la taille de l'image** : Affiche les dimensions de l'image.
- **Conversion en niveaux de gris** : Transforme l'image en une version en noir et blanc.
- **Création du négatif** : Inverse les couleurs de l'image.
- **Découpe d'images** : Permet d'extraire une sous-région de l'image.
- **Ajustement de la luminosité** : Modifie la luminosité des pixels en fonction de la couleur spécifiée.
- **Application d'un filtre médian** : Remplace chaque pixel par la valeur médiane de ses voisins.

## Installation

1. Clonez le dépôt :
   ```bash
   git clone <URL_du_dépôt>
   cd <nom_du_dépôt>
   ```

2. Compilez le programme :
   ```bash
   make
   ```

## Utilisation

1. Exécutez le programme :
   ```bash
   ./exe
   ```

2. Utilisez les commandes suivantes :
   - `size <nom_fichier>` : Affiche la taille de l'image.
   - `gris <nom_fichier>` : Convertit l'image en niveaux de gris.
   - `neg <nom_fichier_entree> <nom_fichier_sortie>` : Crée le négatif de l'image.
   - `cut <nom_fichier> <l1> <l2> <c1> <c2> <nom_fichier_sortie>` : Découpe une partie de l'image.
   - `dom <R/G/B> <valeur> <nom_fichier>` : Ajuste la luminosité.
   - `fil <nom_fichier_entree> <nom_fichier_sortie>` : Applique le filtre médian.
   - `quit` : Quitte l'application.

## Contributions

Ce projet a été réalisé par une équipe de 6 étudiants, chacun ayant contribué à une tâche spécifique :

1. **Étudiant 1 :** 
   - Développement de la fonction de lecture de l'en-tête et d'affichage de la taille de l'image.

2. **Étudiant 2 :** 
   - Implémentation de la conversion en niveaux de gris et de la création de négatifs.

3. **Étudiant 3 :** 
   - Développement des fonctionnalités de découpe d'images et d'ajustement de la luminosité.

4. **Étudiant 4 :** 
   - Implémentation de la fonction d'application du filtre médian.

5. **Étudiant 5 :** 
   - Tests et validation des fonctionnalités, ainsi que correction des bugs.

6. **Étudiant 6 :** 
   - Rédaction de la documentation et mise en place du README.

## Remarques

- Assurez-vous que le fichier PPM que vous souhaitez traiter est dans le même répertoire que l'exécutable ou fournissez le chemin correct.
- Les fichiers de sortie seront générés dans le même répertoire que l'exécutable, avec les noms spécifiés dans les commandes.

 

 
