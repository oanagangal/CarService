#ifndef TEMA_POO3_CAROSERIE_H
#define TEMA_POO3_CAROSERIE_H

#include "Defectiuni.h"

class Caroserie: public Defectiuni {

    int corodat_rugina;
    bool ruginit;
    int aripa_st;
    int aripa_dr;
    int fata;
    int spate;
    int capota;
public:
    Caroserie();
    Caroserie(const Caroserie&);
    ~Caroserie() override;

    Caroserie&operator=(Caroserie);
    bool exista_rugina();
    int suprafata_ruginita();
    int stare_aripa_st();
    int stare_aripa_dr();
    int stare_fata();
    int stare_spate();
    int stare_capota();




};


#endif //TEMA_POO3_CAROSERIE_H
