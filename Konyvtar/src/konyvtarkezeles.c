#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "konyvtarkezeles.h"
#include "fajlkezeles.h"
#include "listakezeles.h"
//#include "debugmalloc.h"


void kiiras(Konyv *ezt)
{
    //if (ezt != NULL)
    printf("Sorszam: %d, Cim: %s, Iro: %s, Mufaj: %s, Kiadasi ev: %d\n", ezt->sorszam, ezt->cim, ezt->iro, ezt->mufaj, ezt->kiad_ev);
}

void osszes_kiirasa(Konyv *konyvtar)
{
    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
        kiiras(mozgo);
}

void uj_letrehoz(Konyv *konyvtar, char *fajlnev)
{
    getchar();
    int sorszam;
    char cim[60];
    char iro[50];
    char mufaj[40];
    int kiad_ev = 0;
    char kiad_ev_str[5];
    char sorszam_str[6];
    printf("\n-------------------------\n"
           "Add meg a konyv cimet!\nA konyv cime: ");
    scanf("%[^\n]%*c", cim);
    printf("\nAdd meg az irojat!\nA konyv iroja: ");
    scanf("%[^\n]%*c", iro);
    printf("\nAdd meg a konyv mufajat!\nA konyv mufaja: ");
    scanf("%[^\n]%*c", mufaj);
 //   printf("uj letrehoz %s", mufaj);
    printf("\nMikor adtak ki a konyvet?\nA konyv kiadasi eve: ");
 //    printf("uj letrehoz1 %s", mufaj);
    scanf("%[^\n]%*c", kiad_ev_str);
//     printf("uj letrehoz2 %s", mufaj);
    kiad_ev = atoi(kiad_ev_str);
    sorszam = atoi(sorszam_str);
    sorszam = konyv_hozzaadas(konyvtar, cim, iro, mufaj, kiad_ev);
    fajl_irasa(fajlnev, konyvtar);
    return;
}

void kereses_cim(Konyv *konyvtar)
{
    getchar();
    char keresendo[60];
    printf("Adja meg a keresendo cimet!\n");
    scanf("%s", keresendo);
    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (strstr(mozgo->cim, keresendo) != NULL){
            kiiras(mozgo);
        }
    }
    return;
}

void kereses_iro(Konyv *konyvtar)
{
    getchar();
    char keresendo[60];
    //char *keresendo;
    printf("Adja meg a keresendo irot!\n");
    //scanf("%s", &keresendo);
    scanf("%s", keresendo);
    //sscanf(keresendo, "%s", keresendo);
    //fgets(keresendo, 60, stdin);
    //gets(keresendo);
    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
    {
        //if (strcmp(mozgo->iro, keresendo) == 0)
        if (strstr(mozgo->iro, keresendo) != NULL)
            kiiras(mozgo);
    }
    return;
}

void kereses_ev(Konyv *konyvtar)
{
    getchar();
    int keresendo;
    printf("Adja meg a keresendo evet!\n");
    scanf("%d", &keresendo);
    Konyv *mozgo;

    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (mozgo->kiad_ev == keresendo)
            kiiras(mozgo);
    }
    return;
}

void kereses_mufaj(Konyv *konyvtar)
{
    getchar();
    char keresendo[60];
    printf("Adja meg a keresendo mufajt!\n");
    scanf("%s",keresendo);
    Konyv *mozgo;
    for (mozgo = konyvtar; mozgo != NULL; mozgo = mozgo->kov)
    {
        if (strstr(mozgo->mufaj, keresendo) != NULL)
            kiiras(mozgo);
    }
    return;
}

void kilepes(Konyv *konyvtar)
{
    if (konyvtar == NULL) return;
    Konyv *iter = konyvtar;
    while (iter != NULL) {
        Konyv *kov = iter->kov; /* következõ elem */
        free(iter);
        iter = kov;
    }
}

Konyv *torles(Konyv *konyvtar, char *fajlnev)
{
  //  int valasz;
  //  Konyv *konyvtar;
    int valasztott_sorszam;
    Konyv *mozgo = konyvtar;
    Konyv *lemarado = NULL;
    printf("\n--------------------------------\n"
           "Add meg a torlendo elem sorszamat!\nValasz: ");
          // "Keress ra arra az elemre amelyet torolni szeretnel, hogy megtudd a sorszamat (1), majd add meg azt.\nHa mar tudod, hogy mit szeretnel torolni, nyomj 2.est!\nValasz:");
  /*  scanf("%d", &valasz);
    switch (valasz){
 //   case 1: kereses_menu(konyvtar, fajlnev); break;
    case 2: printf("A torlendo elem sorszama: ");
    default: printf("Helytelen szamot adtal meg!\n"); break;
    }*/
    scanf("%d", &valasztott_sorszam);
    while (mozgo != NULL && mozgo->sorszam != valasztott_sorszam)
    {
        lemarado = mozgo;
        mozgo = mozgo->kov;
    }
    if (mozgo == NULL) return konyvtar;
    else if (lemarado == NULL)
    {
        Konyv *ujkonyvtar = mozgo->kov;
        free(mozgo);
        konyvtar = ujkonyvtar;
    } else  {
        lemarado->kov = mozgo->kov;
        free(mozgo);
        }

    fajl_irasa(fajlnev, konyvtar);
    return konyvtar;
}
