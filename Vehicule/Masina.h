#ifndef TEMA_POO3_MASINA_H
#define TEMA_POO3_MASINA_H

#include "Vehicul.h"
#include "Motor_auto.h"
#include "Directie_auto.h"
#include "Caroserie.h"
#include "Solutii_frane.h"
#include "Solutii_motor.h"
#include "Solutii_Caroserie.h"


using namespace std;


class Masina : public Vehicul<autoT> {

protected:
    Motor_auto m;
    Directie_auto *d;
    Caroserie crs;
    double calcul_cost_caroserie();

public:
    explicit Masina(autoT ,int k = 4);
    Masina(const Masina &obj);
    ~Masina() override;

    Masina &operator=(Masina);
    void calcul_cost() override;



};


#endif //TEMA_POO3_MASINA_H
