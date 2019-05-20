#ifndef TEMA_POO3_DIRECTIE_MOTO_H
#define TEMA_POO3_DIRECTIE_MOTO_H

#include "Directie_auto.h"

class Directie_moto: public Directie_auto {

    bool ghidon_stramb;
public:
    Directie_moto();
    Directie_moto(const Directie_moto&);
    ~Directie_moto() override;
    Directie_moto&operator=(Directie_moto);

    bool stare_ghidon();

};


#endif //TEMA_POO3_DIRECTIE_MOTO_H
