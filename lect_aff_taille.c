 #include "fichier.h"
 
 void afficher_taille(ImagePPM *image) {
    printf("Taille de l'image : %d x %d\n", image->largeur, image->hauteur);
}
ImagePPM* charger_image(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        printf("Erreur : fichier '%s' non trouvé.\n", nom_fichier);
        return NULL;
    }

    ImagePPM *image = malloc(sizeof(ImagePPM));
    if (!image) {
        fclose(fichier);
        printf("Erreur : échec de l'allocation de mémoire pour l'image.\n");
        return NULL;
    }

    if (fscanf(fichier, "P3\n%d %d\n%d\n", &image->largeur, &image->hauteur, &image->max_val) != 3) {
        fclose(fichier);
        free(image);
        printf("Erreur : format du fichier incorrect.\n");
        return NULL;
    }

    image->pixels = malloc(image->largeur * image->hauteur * 3);
    if (!image->pixels) {
        fclose(fichier);
        free(image);
        printf("Erreur : échec de l'allocation de mémoire pour les pixels.\n");
        return NULL;
    }

    for (int i = 0; i < image->largeur * image->hauteur * 3; i++) {
        if (fscanf(fichier, "%hhu", &image->pixels[i]) != 1) {
            fclose(fichier);
            free(image->pixels);
            free(image);
            printf("Erreur : échec de la lecture des pixels.\n");
            return NULL;
        }
    }
    fclose(fichier);
    printf("Image chargée : %d x %d\n", image->largeur, image->hauteur);
    return image;
}

// Fonction pour sauvegarder une image PPM
void sauver_image(const char *nom_fichier, ImagePPM *image) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (!fichier) {
        printf("Erreur : échec de l'ouverture du fichier pour sauvegarde.\n");
        return;
    }
    
    fprintf(fichier, "P3\n%d %d\n%d\n", image->largeur, image->hauteur, image->max_val);
    for (int i = 0; i < image->largeur * image->hauteur * 3; i++) {
        fprintf(fichier, "%d ", image->pixels[i]);
    }
    fclose(fichier);
}
void afficher_menu() {
    printf("Commandes disponibles :\n");
    printf("1. size <nom_fichier> - Afficher la taille de l'image.\n");
    printf("2. gris <nom_fichier> - Convertir l'image en niveaux de gris.\n");
    printf("3. neg <nom_fichier> - Créer le négatif de l'image.\n");
    printf("4. cut <l1> <l2> <c1> <c2> <nom_fichier> - Découper l'image.\n");
    printf("5. dom <R/G/B> <valeur> <nom_fichier> - Foncer ou éclaircir.\n");
    printf("6. fil <nom_fichier> - Appliquer un filtre médian.\n");
    printf("7. quit - Quitter l'application.\n");
}
