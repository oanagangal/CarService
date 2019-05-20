#ifndef TEMA_POO3_MOTOCICLETA_H
#define TEMA_POO3_MOTOCICLETA_H

#include "Vehicul.h"
#include "Motor_moto.h"
#include "Directie_moto.h"
#include "Solutii_motor.h"
#include "Solutii_frane.h"

class Motocicleta: public Vehicul<motoT>{

protected:
    Motor_moto mm;
    Directie_moto *dmoto;

public:
    explicit Motocicleta(motoT,int k = 2);
    Motocicleta(const Motocicleta&);
    ~Motocicleta() override;

    Motocicleta&operator=(Motocicleta);
    void calcul_cost() override;


};


#endif //TEMA_POO3_MOTOCICLETA_H
