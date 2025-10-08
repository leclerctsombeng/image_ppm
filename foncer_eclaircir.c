#include "fichier.h"

void foncer_eclaircir(ImagePPM *image, char couleur, int val) {
    for (int i = 0; i < image->largeur * image->hauteur; i++) {
        unsigned char *composantes = &image->pixels[i * 3]; // R, G, B
        int index = (couleur == 'R') ? 0 : (couleur == 'G') ? 1 : 2;
        int new_value = composantes[index] + val;

        // Limiter les valeurs entre 0 et 255
        if (new_value < 0) new_value = 0;
        if (new_value > 255) new_value = 255;

        composantes[index] = new_value;
    }
}

 

