#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fajlkezeles.h"
#include "konyvtarkezeles.h"
#include "listakezeles.h"
//#include "debugmalloc.h"

Konyv *fajl_olvasas(char *fajlnev)
{
    Konyv *konyvtar = NULL;
    FILE *fp;

    printf("%s\n", fajlnev);
    fp = fopen(fajlnev, "rt");
    if (fp == NULL)
    {
        printf("Nem lehet megnyitni a fajlt!\n");
        return konyvtar;
    }

    int sorszam = 0;
    char cim[60];
    char iro[50];
    char mufaj[20];
    int kiad_ev = 0;
    char kiad_ev_str[8];
    char sorszam_str[6];
    Konyv *vege = NULL;

    while (fscanf(fp, " %[^\t] %[^\t] %[^\t] %[^\t] %[^\n]", sorszam_str, cim, iro, mufaj, kiad_ev_str) != EOF)
    {
        kiad_ev = atoi(kiad_ev_str);
        sorszam = atoi(sorszam_str);
     //   printf("-%s=%s\n", mufaj, iro);
        Konyv *ujelem = konyv_vegehez_hozzaadas(konyvtar, vege, sorszam, cim, iro, mufaj, kiad_ev);
        if (konyvtar == NULL)
            konyvtar = ujelem;
        vege = ujelem;
    }

    fclose(fp);
    return konyvtar;
}


void fajl_irasa(char *fajlnev, Konyv *konyvtar)
{
    FILE *fp;
    fp = fopen(fajlnev, "wt");
    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov){
       // printf("%s", mozgo->mufaj);
        fprintf(fp, "%d\t%s\t%s\t%s\t%d\n", mozgo->sorszam, mozgo->cim, mozgo->iro, mozgo->mufaj, mozgo->kiad_ev);
    }
    fclose(fp);
}
