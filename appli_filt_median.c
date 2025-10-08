#include "fichier.h"

void appliquer_filtre_median(ImagePPM *image) {
    unsigned char *pixels_temp = malloc(image->largeur * image->hauteur * 3);
    for (int i = 0; i < image->largeur * image->hauteur; i++) {
        int voisins[9][3] = {0}; // 3 couleurs pour 8 voisins + soi-même
        int compteur = 0;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ni = (i / image->largeur) + di;
                int nj = (i % image->largeur) + dj;
                if (ni >= 0 && ni < image->hauteur && nj >= 0 && nj < image->largeur) {
                    int idx = (ni * image->largeur + nj) * 3;
                    voisins[compteur][0] = image->pixels[idx];
                    voisins[compteur][1] = image->pixels[idx + 1];
                    voisins[compteur][2] = image->pixels[idx + 2];
                    compteur++;
                }
            }
        }

        for (int c = 0; c < 3; c++) {
            // Tri pour obtenir la valeur médiane
            for (int a = 0; a < compteur - 1; a++) {
                for (int b = a + 1; b < compteur; b++) {
                    if (voisins[a][c] > voisins[b][c]) {
                        int temp = voisins[a][c];
                        voisins[a][c] = voisins[b][c];
                        voisins[b][c] = temp;
                    }
                }
            }
            pixels_temp[i * 3 + c] = voisins[compteur / 2][c]; // valeur médiane
        }
    }

    memcpy(image->pixels, pixels_temp, image->largeur * image->hauteur * 3);
    free(pixels_temp);
}

