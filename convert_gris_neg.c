 #include "fichier.h"
 
 void passer_en_noir_et_blanc(ImagePPM *image) {
    for (int i = 0; i < image->largeur * image->hauteur; i++) {
        unsigned char *composantes = &image->pixels[i * 3];
        unsigned char gris = (composantes[0] + composantes[1] + composantes[2]) / 3;
        composantes[0] = composantes[1] = composantes[2] = gris;
    }
}

void creer_negatif(ImagePPM *image) {
    for (int i = 0; i < image->largeur * image->hauteur; i++) {
        unsigned char *composantes = &image->pixels[i * 3];
        composantes[0] = 255 - composantes[0];
        composantes[1] = 255 - composantes[1];
        composantes[2] = 255 - composantes[2];
    }
}
void liberer_image(ImagePPM *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}
