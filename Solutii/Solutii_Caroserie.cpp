#include "Solutii_Caroserie.h"

       int Solutii_Caroserie::pret_agent_curatare = 25;
       int Solutii_Caroserie::pret_chit = 10;
       int Solutii_Caroserie::pret_grund = 60;
       int Solutii_Caroserie::pret_vopsea = 50;
       int Solutii_Caroserie::pret_lac = 20;
       int Solutii_Caroserie::capota_noua = 480;
       int Solutii_Caroserie::aripa_noua = 300;
       int Solutii_Caroserie::fata_spate = 300;
       int Solutii_Caroserie::manopera = 50;

double Solutii_Caroserie::indepartare_rugina(int k)
{
    float pas1 = Solutii_Caroserie::pret_agent_curatare + Solutii_Caroserie::pret_chit;
    float pas2 = Solutii_Caroserie::pret_grund + Solutii_Caroserie::pret_vopsea + Solutii_Caroserie::pret_lac;

    return k*(pas1 + pas2) + 0.3 * Solutii_Caroserie::manopera;
}

double Solutii_Caroserie::remediere_lovitura(int k)
{
    float pas = Solutii_Caroserie::pret_grund + Solutii_Caroserie::pret_vopsea + Solutii_Caroserie::pret_lac;
    return k*(pas + 0.8 * Solutii_Caroserie::manopera);
}

double Solutii_Caroserie::schimb_capota()
{
    float pas = Solutii_Caroserie::pret_vopsea + Solutii_Caroserie::pret_lac;
    return Solutii_Caroserie::capota_noua + pas + 0.8 * Solutii_Caroserie::manopera;
}

double Solutii_Caroserie::schimb_aripa()
{
    float pas = Solutii_Caroserie::pret_vopsea + Solutii_Caroserie::pret_lac;
    return Solutii_Caroserie::aripa_noua + pas + 0.8 * manopera;
}

double Solutii_Caroserie::schimb_fataspate()
{
    float pas = Solutii_Caroserie::pret_vopsea + Solutii_Caroserie::pret_lac;
    return Solutii_Caroserie::fata_spate + pas + 0.8 * Solutii_Caroserie::manopera;
}
