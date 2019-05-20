#ifndef TEMA_POO3_SOLUTII_FRANE_H
#define TEMA_POO3_SOLUTII_FRANE_H

class Solutii_frane {

public:
    static int pret_pf;
    static int pret_ps;
    static int pret_disc;
    static int ore_om;

    Solutii_frane();
    ~Solutii_frane() = default;
    Solutii_frane(const Solutii_frane&) = default;

    static float inlocuit_placute_fata();
    static float inlocuit_placute_spate();
    static float inlocuit_discuri();


};



#endif //TEMA_POO3_SOLUTII_FRANE_H
