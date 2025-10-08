#ifndef _FICHIER_H
#define _FICHIER_H

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int largeur;
    int hauteur;
    int max_val;
    unsigned char *pixels; // tableau pour stocker les pixels
} ImagePPM;

// Prototypes de fonctions
ImagePPM* charger_image(const char *nom_fichier);
void sauver_image(const char *nom_fichier, ImagePPM *image);
void foncer_eclaircir(ImagePPM *image, char couleur, int val);
void passer_en_noir_et_blanc(ImagePPM *image);
void creer_negatif(ImagePPM *image);
void afficher_taille(ImagePPM *image);
ImagePPM* decouper_image(ImagePPM *image, int l1, int l2, int c1, int c2);
void appliquer_filtre_median(ImagePPM *image);
void liberer_image(ImagePPM *image);
void afficher_menu();

#endif

