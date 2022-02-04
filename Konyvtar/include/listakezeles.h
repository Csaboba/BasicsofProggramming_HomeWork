#ifndef LISTAKEZELES_H
#define LISTAKEZELES_H

typedef struct Konyv{
    char cim[60];
    char iro[50];
    char mufaj[40];
    int sorszam;
    int kiad_ev;
    struct Konyv *kov;
 }Konyv;

 int legnagyobb_sorszam(Konyv *konyvtar);
 Konyv *vegeptr(Konyv* konyvtar);
 int konyv_hozzaadas(Konyv *konyvtar, char cim[60], char iro[50], char mufaj[40], int kiad_ev);
 Konyv *konyv_vegehez_hozzaadas(Konyv *konyvtar, Konyv *vege, int sorszam, char cim[60], char iro[50], char mufaj[40], int kiad_ev);


#endif
