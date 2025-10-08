#include "fichier.h"

 int main() {
    char commande[100];
    ImagePPM *image = NULL;

    printf("Application de traitement d'images PPM.\n");
   

    while (1) {
        printf("ppmviewer > ");
        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = 0; // enlever le saut de ligne

        if (strncmp(commande, "quit", 4) == 0) {
            break;
        } else if (strncmp(commande, "size ", 5) == 0) {
            image = charger_image(commande + 5);
            if (image) {
                afficher_taille(image);
                liberer_image(image);
            }
        } else if (strncmp(commande, "gris ", 5) == 0) {
            image = charger_image(commande + 5);
            if (image) {
                passer_en_noir_et_blanc(image);
                sauver_image("image_gris.ppm", image);
                printf("Image en niveaux de gris sauvegardée sous 'image_gris.ppm'.\n");
                liberer_image(image);
            }
        } else if (strncmp(commande, "neg ", 4) == 0) {
            image = charger_image(commande + 4);
            if (image) {
                creer_negatif(image);
                sauver_image("image_neg.ppm", image);
                printf("Négatif de l'image sauvegardé sous 'image_neg.ppm'.\n");
                liberer_image(image);
            }
        } else if (strncmp(commande, "cut ", 4) == 0) {
            int l1, l2, c1, c2;
            char nom_fichier[100];
            sscanf(commande + 4, "%d %d %d %d %s", &l1, &l2, &c1, &c2, nom_fichier);
            image = charger_image(nom_fichier);
            if (image) {
                ImagePPM *decoupe = decouper_image(image, l1, l2, c1, c2);
                if (decoupe) {
                    sauver_image("image_decoupe.ppm", decoupe);
                    printf("Image découpée sauvegardée sous 'image_decoupe.ppm'.\n");
                    liberer_image(decoupe);
                }
                liberer_image(image);
            }
        } else if (strncmp(commande, "dom ", 4) == 0) {
            char couleur;
            int val;
            char nom_fichier[100];
            sscanf(commande + 4, "%c %d %s", &couleur, &val, nom_fichier);
            image = charger_image(nom_fichier);
            if (image) {
                foncer_eclaircir(image, couleur, val);
                sauver_image("image_modifiee.ppm", image);
                printf("Image modifiée sauvegardée sous 'image_modifiee.ppm'.\n");
                liberer_image(image);
            }
        } else if (strncmp(commande, "fil ", 4) == 0) {
            char nom_fichier[100];
            sscanf(commande + 4, "%s", nom_fichier);
            image = charger_image(nom_fichier);
            if (image) {
                appliquer_filtre_median(image);
                sauver_image("image_filtre.ppm", image);
                printf("Filtre médian appliqué, sauvegardé sous 'image_filtre.ppm'.\n");
                liberer_image(image);
            }
        } else {
            printf("Commande non reconnue.\n");
             afficher_menu();
        }
    }

    liberer_image(image);
    return 0;
}

