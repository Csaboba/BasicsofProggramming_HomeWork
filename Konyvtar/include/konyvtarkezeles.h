#include "listakezeles.h"
#ifndef KONYVTARKEZELES_H
#define KONYVTARKEZELES_H

void kereses_cim(Konyv *konyvtar);
void kereses_iro(Konyv *konyvtar);
void kereses_ev(Konyv *konyvtar);
void kereses_mufaj(Konyv *konyvtar);
void osszes_kiirasa(Konyv *konyvtar);
void uj_letrehoz(Konyv *konyvtar, char *fajlnev);
Konyv *torles(Konyv *konyvtar, char *fajlnev);
void kilepes(Konyv *konyvtar);

#endif // KONYTARKEZELES_H
