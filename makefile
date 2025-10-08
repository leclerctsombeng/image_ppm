exe : main.o appli_filt_median.o convert_gris_neg.o decoup_img_lumi.o lect_aff_taille.o foncer_eclaircir.o
	gcc -o exe main.o appli_filt_median.o convert_gris_neg.o decoup_img_lumi.o lect_aff_taille.o foncer_eclaircir.o
main.o : main.c appli_filt_median.c convert_gris_neg.c decoup_img_lumi.c lect_aff_taille.c
	gcc -c main.c
appli_filt_median.o : appli_filt_median.c fichier.h
	gcc -c appli_filt_median.c
convert_gris_neg.o : convert_gris_neg.c fichier.h
	gcc -c convert_gris_neg.c
decoup_img_lumi.o : decoup_img_lumi.c fichier.h
	gcc -c decoup_img_lumi.c
lect_aff_taille.o : lect_aff_taille.c fichier.h
	gcc -c lect_aff_taille.c
foncer_eclaircir.o : foncer_eclaircir.c fichier.h
	gcc -c foncer_eclaircir.c
clean:
	rm -f *.o
