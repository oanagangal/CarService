#include "Caroserie.h"

Caroserie::Caroserie(): Defectiuni()
{
     corodat_rugina = 0;
     ruginit = false;
     aripa_st = 0;
     aripa_dr = 0;
     fata = 0;
     spate = 0;
     capota = 0;
}

Caroserie::Caroserie(const Caroserie &cr): Defectiuni(cr)
{
    corodat_rugina = cr.corodat_rugina;
    ruginit = cr.ruginit;
    aripa_st = cr.aripa_st;
    aripa_dr = cr.aripa_dr;
    fata = cr.fata;
    spate = cr.spate;
    capota = cr.capota;
}

Caroserie &Caroserie::operator=(Caroserie cr){

    corodat_rugina = cr.corodat_rugina;
    ruginit = cr.ruginit;
    aripa_st = cr.aripa_st;
    aripa_dr = cr.aripa_dr;
    fata = cr.fata;
    spate = cr.spate;
    capota = cr.capota;
    return *this;
}

int Caroserie::suprafata_ruginita()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    corodat_rugina = (rand()%20) + 1;

    return corodat_rugina;
}

int Caroserie::stare_aripa_st()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    aripa_st = (rand()%13) + 1;

    return aripa_st;
}

int Caroserie::stare_aripa_dr()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    aripa_dr = (rand()%12) + 1;

    return aripa_dr;
}

int Caroserie::stare_fata()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    fata = (rand()%11) + 1;

    return fata;
}

int Caroserie::stare_spate()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    spate = (rand()%13) + 1;

    return spate;
}

int Caroserie::stare_capota()
{
    srand(static_cast<unsigned int>(time(nullptr)));
     capota = (rand()%11) + 1;

    return capota;
}

bool Caroserie::exista_rugina()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    ruginit = static_cast<bool>(rand() % 2);

    return ruginit;
}

Caroserie::~Caroserie() = default;



