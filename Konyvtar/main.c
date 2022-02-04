#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "konyvtarkezeles.h"
#include "fajlkezeles.h"
#include "listakezeles.h"

//#include "debugmalloc.h"

void kereses_menu(Konyv *konyvtar, char *fajlnev)
{
    int valasz = 0;
    while (valasz != 9)
    {
        printf("-------------------------------------\n"
               "Kereses cim alapjan: 1\n"
               "Kereses iro alapjan: 2\n"
               "Kereses kiadasi ev alapjan: 3\n"
               "Kereses mufaj alapjan: 4\n"
               "Kilepes: 9\n"
               "-------------------------------------\n"
               "Valasz:");
        scanf("%d", &valasz);

        switch (valasz)
        {
            case 1: kereses_cim(konyvtar); break;
            case 2: kereses_iro(konyvtar); break;
            case 3: kereses_ev(konyvtar); break;
            case 4: kereses_mufaj(konyvtar); break;
            case 9: /*kilepes(konyvtar);*/ break;
            default: printf("Helytelen szamot adtal meg!\n"); break;
        }
        //kereses_utani_menu(konyvtar, fajlnev);
    }
  //  kereses_utani_menu(konyvtar, fajlnev);
    return;
}

/*void kereses_utani_menu(Konyv *konyvtar, char *fajlnev)
{
    int valasz = 0;

    while(valasz != 9)
    {
        printf("\n--------------------------------\n"
               "Uj konyv felvetele: 1\n"
               "Elem torlese: 2\n"
               "Kilepes: 9\n"
               "Valasz:");

        scanf("%d", &valasz);

        switch(valasz)
        {
            case 1: uj_letrehoz(konyvtar, fajlnev); break;
            case 2: torles(konyvtar, fajlnev); break;
            case 9: kilepes(konyvtar); break;
            default: printf("Helytelen szamot adtal meg!\n"); break;
        }

    }
}*/



//Konyv* fomenu(Konyv *konyvtar, char *fajlnev)
void fomenu(Konyv *konyvtar, char *fajlnev)
{
    int valasz = 0;

    while (valasz != 9) {

        printf("\n----------------------------------\n"
               "Valassz cselekvest, ird be a hozza tartozo szamot, majd nyomj entert!\n"
               "Osszes konyv megjelenitese: 1\n"
               "Egy konyv keresese: 2\n"
               "Uj konyv felvetele: 3\n"
               "Konyv torlese: 4\n"
               "Kilepes: 9\n"
               "----------------------------------\n"
               "Valasz:");

        scanf("%d", &valasz);

        switch (valasz)
        {
            case 1: osszes_kiirasa(konyvtar); break;
            case 2: kereses_menu(konyvtar, fajlnev); break;
            case 3: uj_letrehoz(konyvtar, fajlnev); break;
            case 4: konyvtar = torles(konyvtar, fajlnev); break;
            case 9: kilepes(konyvtar); break;
            default: printf("Helytelen szamot adtal meg!\n"); break;
        }
    }
     return;
}

int main(int argc, char *argv[])
{
    Konyv *konyvtar;
    char *fajlnev = "Sokkonyv.txt";
  //  char *fajlnev = "D:\\Egyetem\\Programozas\\Konyvtar\\bin\\Debug\\Sokkonyv.txt";
    printf("Udvozollek a konyvatrban!\n");

    konyvtar = fajl_olvasas(fajlnev);

    //fomenu(konyvtar, fajlnev);
    fomenu(konyvtar, fajlnev);

    return 0;
}
