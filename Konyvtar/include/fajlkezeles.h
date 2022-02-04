#include "konyvtarkezeles.h"
#include "listakezeles.h"
#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H

Konyv *fajl_olvasas(char *fajlnev);
void fajl_irasa(char *fajlnev, Konyv *konyvtar);

#endif
