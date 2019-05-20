#include "Solutii_frane.h"

int Solutii_frane::pret_pf = 35;
int Solutii_frane::pret_ps = 45;
int Solutii_frane::pret_disc = 50;
int Solutii_frane::ore_om = 30;


Solutii_frane::Solutii_frane() = default;

float Solutii_frane::inlocuit_placute_fata()
{
    return static_cast<float>(2 * Solutii_frane::pret_pf + 0.3 * Solutii_frane::ore_om);
}

float Solutii_frane::inlocuit_placute_spate()
{
    return static_cast<float>(2 * Solutii_frane::pret_ps + 0.3 * Solutii_frane::ore_om);
}

float Solutii_frane::inlocuit_discuri()
{
    float s = inlocuit_placute_fata();

    return s + static_cast<float>(2 * Solutii_frane::pret_disc + 0.3 * Solutii_frane::ore_om);
}

