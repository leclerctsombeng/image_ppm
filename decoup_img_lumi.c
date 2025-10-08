 #include "fichier.h"
ImagePPM* decouper_image(ImagePPM *image, int l1, int l2, int c1, int c2) {
    if (l1 >= l2 || c1 >= c2 || l2 > image->hauteur || c2 > image->largeur) {
        printf("Erreur : coordonnées invalides.\n");
        return NULL;
    }

    ImagePPM *decoupe = malloc(sizeof(ImagePPM));
    if (!decoupe) {
        printf("Erreur : échec de l'allocation de mémoire pour l'image découpée.\n");
        return NULL;
    }

    decoupe->largeur = c2 - c1;
    decoupe->hauteur = l2 - l1;
    decoupe->max_val = image->max_val;
    decoupe->pixels = malloc(decoupe->largeur * decoupe->hauteur * 3);
    if (!decoupe->pixels) {
        free(decoupe);
        printf("Erreur : échec de l'allocation de mémoire pour les pixels découpés.\n");
        return NULL;
    }

    for (int l = l1; l < l2; l++) {
        for (int c = c1; c < c2; c++) {
            int idx_src = (l * image->largeur + c) * 3;
            int idx_dst = ((l - l1) * decoupe->largeur + (c - c1)) * 3;
            decoupe->pixels[idx_dst] = image->pixels[idx_src];
            decoupe->pixels[idx_dst + 1] = image->pixels[idx_src + 1];
            decoupe->pixels[idx_dst + 2] = image->pixels[idx_src + 2];
        }
    }

    return decoupe;
}

