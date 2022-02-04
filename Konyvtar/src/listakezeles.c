#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "konyvtarkezeles.h"
#include "fajlkezeles.h"
#include "listakezeles.h"
//#include "debugmalloc.h"

int legnagyobb_sorszam(Konyv *konyvtar)
{
    int maxsorszam = 0;

    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
    {
       maxsorszam = (maxsorszam < mozgo->sorszam) ? mozgo->sorszam : maxsorszam;
    }
    return maxsorszam;
}

Konyv *vegeptr(Konyv* konyvtar)
{
    Konyv *vege;
   // for (vege = konyvtar; vege != NULL; vege = vege->kov);
    for (vege = konyvtar; vege->kov != NULL; vege = vege->kov);
    return vege;
}

int konyv_hozzaadas(Konyv *konyvtar, char cim[60], char iro[50], char mufaj[40], int kiad_ev)
{
    int sorszam = legnagyobb_sorszam(konyvtar) + 1;

    Konyv *vege = vegeptr(konyvtar);
   //  printf("konyv hozzadasa1 %s", mufaj);
    Konyv *ujelem = konyv_vegehez_hozzaadas(konyvtar, vege, sorszam, cim, iro, mufaj, kiad_ev);
   //  printf("konyv hozzadasa2 %s", mufaj);
    return ujelem->sorszam;
}

Konyv *konyv_vegehez_hozzaadas(Konyv *konyvtar, Konyv *vege, int sorszam, char cim[60], char iro[50], char mufaj[40], int kiad_ev)
{
    Konyv *ujelem;
    ujelem = (Konyv*) malloc(sizeof(Konyv));

    ujelem->sorszam = sorszam;
    strcpy(ujelem->cim, cim);
    strcpy(ujelem->iro, iro);
    strcpy(ujelem->mufaj, mufaj);
    ujelem->kiad_ev = kiad_ev;
    ujelem->kov = NULL;

    if (vege != NULL)
        vege->kov = ujelem;

    return ujelem;
}
